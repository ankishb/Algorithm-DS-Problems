class NumArray {
public:
    vector<int> tree;
    int n;
    NumArray(vector<int> nums) {
        n = nums.size();
        tree = vector<int>(n * 2, 0);
        build(nums, tree);
    }
    void build(vector<int> arr, vector<int>& tree) { 
        int n = arr.size();
        for (int i=0; i<n; i++){
            tree[n+i] = arr[i];
        }  
        for(int i = n - 1; i > 0; --i){
            tree[i] = tree[i * 2] + tree[i * 2 + 1]; 
        }    
    }
    
    void update(int p, int val) {
        tree[p + n] = val;
        p = p + n;
        for (int i = p; i > 1; i = i / 2){
            tree[i/2] = tree[i] + tree[i ^ 1];
        }       
    }
    
    int sumRange(int i, int j) {
        int res = 0;
        int l = i;
        int r = j + 1;
        l = l + n;
        r = r + n;
        while(l < r){
            if (l % 2 != 0){
                res += tree[l];
                l++;
            }
            if (r % 2 != 0){
                r--;
                res += tree[r];
            } 
            l = l / 2;
            r = r / 2;
        }
        return res;
    }
};
// ================================================
// ================================================
// ================================================

class numRange{
public:
    int n;
    vector<int> tree, dup;
    numRange(vector<int> A){
        dup = A;
        n = A.size();
        if(n == 0) return ;
        // we need to assign memory to segArray such that it can fit all the parents e.g.
        // for n = 13, we need [16*2 - 1], 
        // for n = 17, we need [32*2 - 1]
        int s = log2(n);
        if(pow(2, s) != len) s++;
        s = (2*pow(2, s)) - 1;
        tree.resize(s, 0);
        makeTreeIter();
        // makeTreeRec(0, n-1, 0);
    }
    void makeTreeIter(){
        for(int i=0; i<n; i++){
            tree[n+i] = dup[i];
        }
        // pow(2,i)   = i<<1
        // pow(2,i)+1 = i<<1 | 1
        for(int i=n-1; i>0; --i){
            tree[i] = tree[pow(2,i)] + tree[pow(2,i)+1];
        }
    }

    // in recursive, we start with root and go down in recusion
    /*
                    0
                  /   \
                 1     2
                / \   / \
               3   4 5   6

    */
    void makeTreeRec(int left, int right, int pos){
        if(high == low){ 
            tree[pos] = dup[low];
            return ;
        }
        int mid = left + (right - left)/2;
        makeTreeRec(left, mid, (2*pos)+1);
        makeTreeRec(mid+1, right, (2*pos)+2);
        tree[pos] = tree[(2*pos)+1] + tree[(2*pos)+2];
    }

    // note that to update, we go up and update all the node(parent, grand-parent and so on..), till we hit the root
    void updateItr(int idx, int value){
        int child, parent = idx+n;
        for(int i=parent; i>1; i=i>>1){
            child = i/2;
            tree[i] = value;
            tree[child] = tree[child*2] + tree[child*2 + 1];
        }
    }
    void updateRecHelper(int low, int high, int idx, int pos, int diff){
        if(low <= idx && high >= idx){
            tree[pos] = tree[pos] + diff;
        }
        if(low > idx || high < idx) return ;
        int mid = low + (high - low)/2;
        updateRecHelper(low, mid, idx, 2*pos+1, diff);
        updateRecHelper(mid+1, high, idx, 2*pos+2, diff);

    }
    void updateRec(int idx, int value){
        int diff = value - dup[i];
        dup[idx] = value;
        modify(0, n-1, idx, 0, diff);
    }

    /*
    1. if child is odd, then it is right child of its parent, and it include value at child and we move to next of its parent and add this if right range boundary doesn't interfere.
    2. if child is even then we include its parent if right boundary doesn't interefere.
    */
    int sumRange(int l, int r){
        int res = 0;
        for(l += n, r += n; l<r; l = l>>1, r = r>>1){
            if(l&1) { res += tree[l++]; }
            if(r&1) { res += tree[--r]; }
        }
        return res;
    }

    int sumRangeRec(int qLow, int qHigh, int low=0, int high=n-1; int pos=0){
        if(qLow <= low && qHigh >= high){
            return tree[pos];
        }
        if(low > qHigh || high < qLow) return 0;
        int mid = low + (high - low)/2;
        int leftAns = sumRangeRec(qLow, qHigh, low, mid, 2*pos+1);
        int rightAns = sumRangeRec(qLow, qHigh, mid+1, high, 2*pos+2);
        return leftAns + rightAns;
    }
};



// ================================================
// ================================================
// ================================================





class Node{
public:
    int sum, l, r;
    Node *left, *right;
    Node(int sum_, int l_, int r_){
        sum = sum_; l = l_; r = r_;
    }
};

class NumArray {
public:
    Node* root;

    Node* make_tree(int l, int r, vector<int> nums){
        if(l > r) return NULL;
        if(l == r){
            // create new node
            Node* temp = new Node(nums[l], l, l);
            return temp;
        }
        int sum = 0;
        int mid = l + (r - l)/2 ;
        Node* left_node = make_tree(l, mid, nums);
        Node* right_node = make_tree(mid+1, r, nums);

        if(left_node != NULL) sum += left_node->sum;
        if(right_node != NULL) sum +=right_node->sum;

        Node* root = new Node(sum, l, r);
        root->left = left_node;
        root->right = right_node;
        return root;
    }
    
    NumArray(vector<int>& nums) {
        root = make_tree(0, nums.size()-1, nums);
    }

    void update_tree(int i, int val, Node* root) {
        if(root->l == i && root->r == i){
            root->sum = val;
            return ;
        }
        Node* child = (i > (root->l + root->r)/2) ? root->right : root->left ;
        int old_sum = child->sum;
        update_tree(i, val, child);
        root->sum += child->sum - old_sum;
    }

    void update(int i, int val){
        update_tree(i, val, root);
    }
    
    int sumRangeUtil(int i, int j, Node* root) {
        if(root == NULL || i > j) return 0;
        // cout<<root->l <<" "<<root->r<<" "<<root->sum<<endl;
        if(i == root->l && j == root->r){
            return root->sum;
        }

        // int mid = root->l + (root->r - root->l) / 2;
        int mid = (root->r + root->l) / 2;
        if(mid < i){
            return sumRangeUtil(i, j, root->right);
        }
        else if(mid >= j){
            return sumRangeUtil(i, j, root->left);
        }
        else{
            return sumRangeUtil(i, mid, root->left) + sumRangeUtil(mid+1, j, root->right);
        }
    }

    int sumRange(int i, int j) {
        return sumRangeUtil(i, j, root);   
    }
};



// ================================================
// ================================================
// ================================================












#include <bits/stdc++.h> 
using namespace std; 
  
// limit for array size 
const int N = 100000;  
  
int n; // array size 
  
// Max size of tree 
int tree[2 * N]; 
  
// function to build the tree 
void build( int arr[])  
{  
    // insert leaf nodes in tree 
    for (int i=0; i<n; i++)     
        tree[n+i] = arr[i]; 
      
    // build the tree by calculating parents 
    for (int i = n - 1; i > 0; --i)      
        tree[i] = tree[i<<1] + tree[i<<1 | 1];     
} 
  
// function to update a tree node 
void updateTreeNode(int p, int value)  
{  
    // set value at position p 
    tree[p+n] = value; 
    p = p+n; 
      
    // move upward and update parents 
    for (int i=p; i > 1; i >>= 1) 
        tree[i>>1] = tree[i] + tree[i^1]; 
} 
  
// function to get sum on interval [l, r) 
int query(int l, int r)  
{  
    int res = 0; 
      
    // loop to find the sum in the range 
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) 
    { 
        if (l&1)  
            res += tree[l++]; 
      
        if (r&1)  
            res += tree[--r]; 
    } 
      
    return res; 
} 
  
// driver program to test the above function  
int main()  
{ 
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; 
  
    // n is global 
    n = sizeof(a)/sizeof(a[0]); 
      
    // build tree  
    build(a); 
      
    // print the sum in range(1,2) index-based 
    cout << query(1, 3)<<endl; 
      
    // modify element at 2nd index 
    updateTreeNode(2, 1); 
      
    // print the sum in range(1,2) index-based 
    cout << query(1, 3)<<endl; 
  
    return 0; 
} 










/*
That's it! Fully operational example. Forget about those cumbersome recursive functions with 5 arguments!

Now let's see why this works, and works very efficient.

    1. As you could notice from the picture, leaves are stored in continuous nodes with indices starting with n, element with index i corresponds to a node with index i + n. So we can read initial values directly into the tree where they belong.

    2. Before doing any queries we need to build the tree, which is quite straightforward and takes O(n) time. Since parent always has index less than its children, we just process all the internal nodes in decreasing order. In case you're confused by bit operations, the code in build() is equivalent to t[i] = t[2*i] + t[2*i+1].

    3. Modifying an element is also quite straightforward and takes time proportional to the height of the tree, which is O(log(n)). We only need to update values in the parents of given node. So we just go up the tree knowing that parent of node p is p / 2 or p>>1, which means the same. p^1 turns 2 * i into 2 * i + 1 and vice versa, so it represents the second child of p's parent.

    4. Finding the sum also works in O(log(n)) time. To better understand it's logic you can go through example with interval [3, 11) and verify that result is composed exactly of values in nodes 19, 26, 12 and 5 (in that order).

General idea is the following. If l, the left interval border, is odd (which is equivalent to l&1) then l is the right child of its parent. Then our interval includes node l but doesn't include it's parent. So we add t[l] and move to the right of l's parent by setting l = (l + 1) / 2. If l is even, it is the left child, and the interval includes its parent as well (unless the right border interferes), so we just move to it by setting l = l / 2. Similar argumentation is applied to the right border. We stop once borders meet.
*/



const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
	for (int i = n - 1; i > 0; --i){
        t[i] = t[i<<1] + t[i<<1|1];
        // t[i] = t[pow(2,i)] + t[pow(2,i)+1];
	}
}

// to update the element, we need to update its parent and go up. So from p, go up that is p/2
void modify(int p, int value) {  // set value at position p
	for (t[p += n] = value; p > 1; p >>= 1){
        // t[p>>1] = t[p] + t[p^1];
        t[p/2] = t[p] + t[p+1];
	}
}

int query(int l, int r) {  // sum on interval [l, r)
	int res = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1) res += t[l++];
		if (r&1) res += t[--r];
	}
	return res;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", t + n + i);
	build();
	modify(0, 1);
	printf("%d\n", query(3, 11));
	return 0;
}



class Node{
public:
	int sum, l, r;
	Node *left, *right;
	Node(int sum_, int l_, int r_){
		sum = sum_; l = l_; r = r_;
	}
};

class NumArray {
public:
    Node* root;

    Node* make_tree(int l, int r, vector<int> nums){
    	if(l > r) return NULL;
    	if(l == r){
    		// create new node
    		Node* temp = new Node(nums[l], l, l);
    		return temp;
    	}
    	int sum = 0;
    	int mid = l + (r - l)/2 ;
    	Node* left_node = make_tree(l, mid, nums);
    	Node* right_node = make_tree(mid+1, r, nums);

    	if(left_node != NULL) sum += left_node->sum;
    	if(right_node != NULL) sum +=right_node->sum;

    	Node* root = new Node(sum, l, r);
    	root->left = left_node;
    	root->right = right_node;
    	return root;
    }
    
    NumArray(vector<int>& nums) {
        root = make_tree(0, nums.size()-1, nums);
    }

    void update_tree(int i, int val, Node* root) {
    	if(root->l == i && root->r == i){
    		root->sum = val;
    		return ;
    	}
    	Node* child = (i > (root->l + root->r)/2) ? root->right : root->left ;
    	int old_sum = child->sum;
    	update_tree(i, val, child);
    	root->sum += child->sum - old_sum;
    }

    void update(int i, int val){
    	update_tree(i, val, root);
    }
    
    int sumRangeUtil(int i, int j, Node* root) {
        if(root == NULL || i > j) return 0;
        // cout<<root->l <<" "<<root->r<<" "<<root->sum<<endl;
        if(i == root->l && j == root->r){
        	return root->sum;
        }

        // int mid = root->l + (root->r - root->l) / 2;
        int mid = (root->r + root->l) / 2;
        if(mid < i){
        	return sumRangeUtil(i, j, root->right);
        }
        else if(mid >= j){
        	return sumRangeUtil(i, j, root->left);
        }
        else{
        	return sumRangeUtil(i, mid, root->left) + sumRangeUtil(mid+1, j, root->right);
        }
    }

    int sumRange(int i, int j) {
    	return sumRangeUtil(i, j, root);   
    }
};
