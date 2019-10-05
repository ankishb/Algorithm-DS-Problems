class NumArray {
public:
    int len=0;
    vector<int> dup;
    vector<int> seg;
    // qsum -> calculates sum between the given range
    int qsum(vector<int> &seg,int &qlow,int &qhigh,int low,int high,int pos){
        if(qlow <= low && qhigh >= high) return seg[pos];
        if(low>qhigh || high<qlow) return 0;
        int mid = low + (high-low)/2;
        return qsum(seg,qlow,qhigh,low,mid,2*pos+1) + qsum(seg,qlow,qhigh,mid+1,high,2*pos+2);
    }
    // segpopulate -> populates the segment tree
    void segpopulate(vector<int> &nums,vector<int> &seg,int low,int high,int pos){
        if(high == low) {seg[pos] = nums[low]; return;} 
        int mid  = low + (high-low)/2;
        segpopulate(nums,seg,low,mid,2*pos+1);
        segpopulate(nums,seg,mid+1,high,2*pos+2);
        seg[pos] = seg[2*pos+1] + seg[2*pos+2];
    }
    //  modify -> makes changes to segment tree
    void modify(vector<int> &seg,int low,int high, int &index, int &target,int pos){
        if(low <= index && high >= index) seg[pos] = seg[pos]+target;
        if(low == high) return;
        if(low>index ||high<index) return ;
        int mid = low + (high-low)/2;
        modify(seg,low,mid,index,target,2*pos+1);
        modify(seg,mid+1,high,index,target,2*pos+2);
    }
    NumArray(vector<int> nums) {
        dup = nums;
        len = nums.size();
        if(len ==0) return;
        int s = log2(len);
        if(pow(2,s)!= len) s++;
        s = pow(2,s);
        s = 2*s -1;
        seg = vector<int>(s,0);
        // segpopulate(given-array, tree, low, high, cur-pos){
        segpopulate(nums,seg,0,nums.size()-1,0);
    }
    
    void update(int i, int val) {
        int diff = val - dup[i];
        dup[i] = val;
        modify(seg,0,len-1,i,diff,0);
    }
    
    int sumRange(int i, int j) {
        return qsum(seg,i,j,0,len-1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */











class NumArray {
public:
    int n, sum;
    vector<int> cum_sum;
    vector<int> nums_;
    NumArray(vector<int>& nums) {
        nums_ = nums;
        n = nums.size();
        sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            cum_sum.push_back(sum);
        }
    }
    
    void update(int i, int val) {
        for(int idx=i; idx<n; idx++){
            cum_sum[idx] += (val - nums_[i]);
        }
        nums_[i] = val;
    }
    
    int sumRange(int i, int j) {
        sum = cum_sum[j];
        if(i<1) return sum;
        return (sum - cum_sum[i-1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */





















References:

Binary Indexed Trees (BIT or Fenwick tree):

https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/

Segment Tree | Set 1 (Sum of given range)

http://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/

// Binary Index Tree - 7ms
// A BIT node : sum of all its left descendent and itself

//* BIT[] as a binary tree:
//     *            ______________*
//     *            ______*
//     *            __*     __*
//     *            *   *   *   *
//     * indices: 0 1 2 3 4 5 6 7 8

// Note NumArray query index i, and BIT index j has i + 1 = j; So be clear about it.


public class NumArray {
    int bit[];
    int arr[];
    int n;
    
    public NumArray(int[] nums) {
        n = nums.length;
        arr = Arrays.copyOf(nums, n);
        bit = new int[n + 1];
        for (int i = 0; i < n; i++) updateBIT(i + 1, arr[i]);
    }

    void update(int i, int val) {
        int diff = val - arr[i];
        arr[i] = val;
        updateBIT(i + 1, diff);
    }
    
    void updateBIT(int j, int diff) { 
        while (j <= n) {
            bit[j] += diff;
            j += j & -j;
        }
    }

    public int sumRange(int i, int j) {
        return getSum(j + 1) - getSum(i);
    }
    
    int getSum(int j) {
        int sum = 0;
        while (j > 0) {
            sum += bit[j];
            j -= j & -j;
        }
        return sum;
    }
}


// Your NumArray object will be instantiated and called as such:
// NumArray numArray = new NumArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);



/* Segment Tree - Array Implementation - 14ms

// important key is for a range [l,r] of [0, n - 1], 
// [l, r] is bound to segment index iSeg = 0;
// [l, mid] is bound to segment index iSeg*2 + 1;
// [mid+1, r] is bound to segment index iSeg*2 + 2;
// whenener [l,r] has l == r, it is a leaf and seg[iSeg] = arr[l];

public class NumArray {
    int[] seg, arr;
    int nSeg, n;

    public NumArray(int[] nums) {
        n = nums.length;
        int rank = (int)Math.ceil(Math.log(n) / Math.log(2));
        nSeg = (1 << rank + 1) - 1;
        arr = Arrays.copyOf(nums, n);        //arr = new int[n];
        seg = new int[nSeg];
        makeTree(0, n - 1, 0);
    }
    
    int makeTree(int l, int r, int iSeg) {
        if (l > r) return 0;
        if (l == r) {
            seg[iSeg] = arr[l];
            return seg[iSeg];
        }
        int mid = getMid(l, r);
        seg[iSeg] = makeTree(l, mid, iSeg * 2 + 1)
                + makeTree(mid + 1, r, iSeg * 2 + 2);
        return seg[iSeg];
    }
    
    int getMid(int l, int r) {
        return (l + r) / 2;
    }

    void update(int i, int val) {
        int diff = val - arr[i];
        arr[i] = val;
        updateTree(0, n - 1, i, diff, 0);
    }
    
    void updateTree(int l, int r, int i, int diff, int iSeg) {
        seg[iSeg] +=diff;
        if (l == r) return;
        int mid = getMid(l, r);
        if (i > mid)
            updateTree(mid + 1, r, i, diff, iSeg * 2 + 2);
        else
            updateTree(l, mid, i, diff, iSeg * 2 + 1);
    }

    public int sumRange(int i, int j) {
        return getSum(0, n - 1, i, j, 0);
    }
    
    int getSum(int l, int r, int i, int j, int iSeg) {
        if (l > j || r < i) return 0;
        if (l >= i && r <= j) return seg[iSeg];
        int mid = getMid(l, r);
        return getSum(l, mid, i, j, iSeg * 2 + 1)     //search left chd
        + getSum(mid + 1, r, i, j, iSeg * 2 + 2); //search right chd
    }
}
*/


// Segment Tree - SegTreeNode Implementation - 20ms

public class NumArray {
    private class SegTreeNode {
        int sum, l, r;
        SegTreeNode left, right;
        
        public SegTreeNode(int sum1, int l1, int r1) {
            sum = sum1; l = l1; r = r1;
        }
    }
    
    SegTreeNode root;

    public NumArray(int[] nums) {
        root = makeTree(0, nums.length - 1, nums);
    }
    
    private SegTreeNode makeTree(int l, int r, int[] nums) {
        if (l > r) return null;
        if (l == r) return new SegTreeNode(nums[l], l, l);
        int mid = (l + r) / 2, sum = 0;
        SegTreeNode left = makeTree(l, mid, nums);
        SegTreeNode right = makeTree(mid + 1, r, nums);
        if (left != null) sum += left.sum;
        if (right != null) sum += right.sum;
        SegTreeNode root = new SegTreeNode(sum, l, r);
        root.left = left; 
        root.right = right;
        return root;
    }

    void update(int i, int val) {
        updateTree(i, val, root);
    }
    
    private void updateTree(int i, int val, SegTreeNode r) {
        if (r.l == i && r.r == i) {
            r.sum = val;
            return;
        }
        SegTreeNode chd = (i > (r.l + r.r) / 2) ? r.right : r.left;
        int oldsum = chd.sum;
        updateTree(i, val, chd);
        r.sum += chd.sum - oldsum;
    }

    public int sumRange(int i, int j) {
        return sumRange(i, j, root);
    }
    
    private int sumRange(int i, int j, SegTreeNode r) {
        if (r == null || i > j) return 0;
        if (i == r.l && j == r.r) return r.sum;
        
        int mid = (r.l + r.r) / 2;
        if (mid < i) 
            return sumRange(i, j, r.right);
        else
        if (mid >= j)
            return sumRange(i, j, r.left);
        else
            return sumRange(i, mid, r.left) + sumRange(mid + 1, j, r.right);
    }
    
    
}




















class NumArray {
public:
    int n;
    vector<int> tree, dup;
    NumArray(vector<int> &A){
        dup = A;
        n = A.size();
        if(n == 0) return ;
        // cout<<" hii! ";
        // we need to assign memory to segArray such that it can fit all the parents e.g.
        // for n = 13, we need [16*2 - 1], 
        // for n = 17, we need [32*2 - 1]
        int s = log2(n);
        if(pow(2, s) != n) s++;
        s = (2*pow(2, s)) - 1;
        // cout<<s;
        tree.resize(s, 0);
        // makeTreeItr();
        makeTreeRec(0, n-1, 0);\
        printTree();
    }
    void printTree(){
        for(auto itr : tree) cout<< itr <<" ";
        cout<<endl;
    }
    
    void makeTreeItr(){
        for(int i=0; i<n; i++){
            tree[n+i] = dup[i];
        }
        // cout<< "hii ";
        // pow(2,i)   = i<<1
        // pow(2,i)+1 = i<<1 | 1
        for(int i=n-1; i>0; --i){
            // cout<<i<<" "<<tree[pow(2,i)]<<" "<<tree[pow(2,i)+1]<<endl;
            // tree[i] = tree[pow(2,i)] + tree[pow(2,i)+1];
            tree[i] = tree[i<<1] + tree[i<<1|1] ;
        }
        // for(auto itr : tree) cout << itr <<" ";
    }
    void makeTreeRec(int left, int right, int pos){
        if(left == right){ 
            tree[pos] = dup[left];
            return ;
        }
        int mid = left + (right - left)/2;
        makeTreeRec(left, mid, (2*pos)+1);
        makeTreeRec(mid+1, right, (2*pos)+2);
        tree[pos] = tree[(2*pos)+1] + tree[(2*pos)+2];
    }
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
    void update(int idx, int value){
        int diff = value - dup[idx];
        dup[idx] = value;
        updateRecHelper(0, n-1, idx, 0, diff);
    }
    int sumRangeItr(int l, int r){
        printTree();
        int res = 0;
        for(l += n, r += n; l<r; l = l>>1, r = r>>1){
            if(l&1) { res += tree[l++]; }
            if(r&1) { res += tree[--r]; }
        }
        return res;
    }
    int sumRange(int qLow, int qHigh){
        return sumRangeHelper(qLow, qHigh, 0, n-1, 0);
    }
    int sumRangeHelper(int qLow, int qHigh, int low, int high, int pos){
        if(qLow <= low && qHigh >= high){
            return tree[pos];
        }
        if(low > qHigh || high < qLow) return 0;
        int mid = low + (high - low)/2;
        int leftAns = sumRangeHelper(qLow, qHigh, low, mid, 2*pos+1);
        int rightAns = sumRangeHelper(qLow, qHigh, mid+1, high, 2*pos+2);
        return leftAns + rightAns;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
//  */
// class numRange{
// public:
//     int n;
//     vector<int> tree, dup;
//     numRange(vector<int> A){
//         dup = A;
//         n = A.size();
//         if(n == 0) return ;
//         // we need to assign memory to segArray such that it can fit all the parents e.g.
//         // for n = 13, we need [16*2 - 1], 
//         // for n = 17, we need [32*2 - 1]
//         int s = log2(n);
//         if(pow(2, s) != len) s++;
//         s = (2*pow(2, s)) - 1;
//         tree.resize(s, 0);
//         makeTreeIter();
//         // makeTreeRec(0, n-1, 0);
//     }
//     void makeTreeIter(){
//         for(int i=0; i<n; i++){
//             tree[n+i] = dup[i];
//         }
//         // pow(2,i)   = i<<1
//         // pow(2,i)+1 = i<<1 | 1
//         for(int i=n-1; i>=0; i--){
//             tree[i] = tree[pow(2,i)] + tree[pow(2,i)+1];
//         }
//     }

//     // in recursive, we start with root and go down in recusion
//     /*
//                     0
//                   /   \
//                  1     2
//                 / \   / \
//                3   4 5   6

//     */
//     void makeTreeRec(int left, int right, int pos){
//         if(high == low){ 
//             tree[pos] = dup[low];
//             return ;
//         }
//         int mid = left + (right - left)/2;
//         makeTreeRec(left, mid, (2*pos)+1);
//         makeTreeRec(mid+1, right, (2*pos)+2);
//         tree[pos] = tree[(2*pos)+1] + tree[(2*pos)+2];
//     }

//     // note that to update, we go up and update all the node(parent, grand-parent and so on..), till we hit the root
//     void updateItr(int idx, int value){
//         int child, parent = idx+n;
//         for(int i=parent; i>1; i=i>>1){
//             child = i/2;
//             tree[i] = value;
//             tree[child] = tree[child*2] + tree[child*2 + 1];
//         }
//     }
//     void updateRecHelper(int low, int high, int idx, int pos, int diff){
//         if(low <= idx && high >= idx){
//             tree[pos] = tree[pos] + diff;
//         }
//         if(low > idx || high < idx) return ;
//         int mid = low + (high - low)/2;
//         updateRecHelper(low, mid, idx, 2*pos+1, diff);
//         updateRecHelper(mid+1, high, idx, 2*pos+2, diff);

//     }
//     void updateRec(int idx, int value){
//         int diff = value - dup[i];
//         dup[idx] = value;
//         modify(0, n-1, idx, 0, diff);
//     }

//     /*
//     1. if child is odd, then it is right child of its parent, and it include value at child and we move to next of its parent and add this if right range boundary doesn't interfere.
//     2. if child is even then we include its parent if right boundary doesn't interefere.
//     */
//     int sumRange(int l, int r){
//         int res = 0;
//         for(l += n, r += n; l<r; l = l>>1, r = r>>1){
//             if(l&1) { res += tree[l++]; }
//             if(r&1) { res += tree[--r]; }
//         }
//         return res;
//     }

//     int sumRangeRec(int qLow, int qHigh, int low=0, int high=n-1; int pos=0){
//         if(qLow <= low && qHigh >= high){
//             return tree[pos];
//         }
//         if(low > qHigh || high < qLow) return 0;
//         int mid = low + (high - low)/2;
//         int leftAns = sumRangeRec(qLow, qHigh, low, mid, 2*pos+1);
//         int rightAns = sumRangeRec(qLow, qHigh, mid+1, high, 2*pos+2);
//         return leftAns + rightAns;
//     }
// };