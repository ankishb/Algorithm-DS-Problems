/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Approach:
// 1. Use level order transversal
// 2. store sum of each level in vector
// 3. run algo, to maximize sum with no adjacent visit

class Solution {
public:
	int rob_prev(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        int max_el;
        vector<int> ans(nums);
        for(int i=2; i<n; i++){
            max_el = nums[0];
        	for(int j=0; j<=i-2; j++){
        		 max_el = max(max_el, max(nums[j], ans[j]));
        	}
            ans[i] = ans[i] + max_el;
        }

        
        for(int i=0; i<n; i++){
            cout<<ans[i]<<" ";
        	max_el = max(max_el, ans[i]);
        }
        return max_el;
    }


    int rob(TreeNode* root) {
        vector<int> nums;
        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int level = 0;
        TreeNode* top;
        while(true){
        	if(q.size()==1 && q.front()==NULL){
        		break;
        	}
        	top = q.front();
        	q.pop();

        	if(top != NULL){
            	sum += top->val;
                if(top->left != NULL) q.push(top->left);
                if(top->right != NULL) q.push(top->right);
            }
        	if(q.front() == NULL){
        		q.pop(); q.push(NULL);
        		nums.push_back(sum);
        		sum = 0;
        	}
        }
        return rob_prev(nums);
    }
};





/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int tryRob(TreeNode* root, int& l, int& r) {
        if (!root)
            return 0;
            
        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = tryRob(root->left, ll, lr);
        r = tryRob(root->right, rl, rr);
        
        return max(root->val + ll + lr + rl + rr, l + r);
    }

    int rob(TreeNode* root) {
        int l, r;
        return tryRob(root, l, r);
    }
};






/*
f1(node) be the value of maximum money we can rob from the subtree with node as root (we can rob node if necessary)
f2(node) be the value of maximum money we can rob from the subtree with node as root but without robbing node.

f2(node) = f1(node.left) + f1(node.right) and
f1(node) = max( f2(node.left)+f2(node.right)+node.value, f2(node) ).
*/

class Solution {
public:
    int rob(TreeNode* root) {
        return robDFS(root).second;
    }
    pair<int, int> robDFS(TreeNode* node){
        if( !node) return make_pair(0,0);
        auto l = robDFS(node->left);
        auto r = robDFS(node->right);
        int f2 = l.second + r.second;
        int f1 = max(f2, l.first + r.first + node->val);
        return make_pair(f2, f1);
    }
};







/*
Step I -- Think naively

At first glance, the problem exhibits the feature of "optimal substructure": if we want to rob maximum amount of money from current binary tree (rooted at root), we surely hope that we can do the same to its left and right subtrees.

So going along this line, let's define the function rob(root) which will return the maximum amount of money that we can rob for the binary tree rooted at root; the key now is to construct the solution to the original problem from solutions to its subproblems, i.e., how to get rob(root) from rob(root.left), rob(root.right), ... etc.

Apparently the analyses above suggest a recursive solution. And for recursion, it's always worthwhile figuring out the following two properties:

    Termination condition: when do we know the answer to rob(root) without any calculation? Of course when the tree is empty ---- we've got nothing to rob so the amount of money is zero.

    Recurrence relation: i.e., how to get rob(root) from rob(root.left), rob(root.right), ... etc. From the point of view of the tree root, there are only two scenarios at the end: root is robbed or is not. If it is, due to the constraint that "we cannot rob any two directly-linked houses", the next level of subtrees that are available would be the four "grandchild-subtrees" (root.left.left, root.left.right, root.right.left, root.right.right). However if root is not robbed, the next level of available subtrees would just be the two "child-subtrees" (root.left, root.right). We only need to choose the scenario which yields the larger amount of money.

Here is the program for the ideas above:
*/

public int rob(TreeNode root) {
    if (root == null) return 0;
    
    int val = 0;
    if (root.left != null) {
        val += rob(root.left.left) + rob(root.left.right);
    }
    if (root.right != null) {
        val += rob(root.right.left) + rob(root.right.right);
    }
    
    return Math.max(val + root.val, rob(root.left) + rob(root.right));
}

/*
However the solution runs very slowly (1186 ms) and barely got accepted (the time complexity turns out to be exponential, see my comments below).

Step II -- Think one step further

In step I, we only considered the aspect of "optimal substructure", but think little about the possibilities of overlapping of the subproblems. For example, to obtain rob(root), we need rob(root.left), rob(root.right), rob(root.left.left), rob(root.left.right), rob(root.right.left), rob(root.right.right); but to get rob(root.left), we also need rob(root.left.left), rob(root.left.right), similarly for rob(root.right). The naive solution above computed these subproblems repeatedly, which resulted in bad time performance. Now if you recall the two conditions for dynamic programming: "optimal substructure" + "overlapping of subproblems", we actually have a DP problem. A naive way to implement DP here is to use a hash map to record the results for visited subtrees.

And here is the improved solution:
*/

public int rob(TreeNode root) {
    return robSub(root, new HashMap<>());
}

private int robSub(TreeNode root, Map<TreeNode, Integer> map) {
    if (root == null) return 0;
    if (map.containsKey(root)) return map.get(root);
    
    int val = 0;
    
    if (root.left != null) {
        val += robSub(root.left.left, map) + robSub(root.left.right, map);
    }
    
    if (root.right != null) {
        val += robSub(root.right.left, map) + robSub(root.right.right, map);
    }
    
    val = Math.max(val + root.val, robSub(root.left, map) + robSub(root.right, map));
    map.put(root, val);
    
    return val;
}

/*
The runtime is sharply reduced to 9 ms, at the expense of O(n) space cost (n is the total number of nodes; stack cost for recursion is not counted).

Step III -- Think one step back

In step I, we defined our problem as rob(root), which will yield the maximum amount of money that can be robbed of the binary tree rooted at root. This leads to the DP problem summarized in step II.

Now let's take one step back and ask why we have overlapping subproblems. If you trace all the way back to the beginning, you'll find the answer lies in the way how we have defined rob(root). As I mentioned, for each tree root, there are two scenarios: it is robbed or is not. rob(root) does not distinguish between these two cases, so "information is lost as the recursion goes deeper and deeper", which results in repeated subproblems.

If we were able to maintain the information about the two scenarios for each tree root, let's see how it plays out. Redefine rob(root) as a new function which will return an array of two elements, the first element of which denotes the maximum amount of money that can be robbed if root is not robbed, while the second element signifies the maximum amount of money robbed if it is robbed.

Let's relate rob(root) to rob(root.left) and rob(root.right)..., etc. For the 1st element of rob(root), we only need to sum up the larger elements of rob(root.left) and rob(root.right), respectively, since root is not robbed and we are free to rob its left and right subtrees. For the 2nd element of rob(root), however, we only need to add up the 1st elements of rob(root.left) and rob(root.right), respectively, plus the value robbed from root itself, since in this case it's guaranteed that we cannot rob the nodes of root.left and root.right.

As you can see, by keeping track of the information of both scenarios, we decoupled the subproblems and the solution essentially boiled down to a greedy one. Here is the program:
*/

public int rob(TreeNode root) {
    int[] res = robSub(root);
    return Math.max(res[0], res[1]);
}

private int[] robSub(TreeNode root) {
    if (root == null) return new int[2];
    
    int[] left = robSub(root.left);
    int[] right = robSub(root.right);
    int[] res = new int[2];

    res[0] = Math.max(left[0], left[1]) + Math.max(right[0], right[1]);
    res[1] = root.val + left[0] + right[0];
    
    return res;
}



rob(TreeNode* root) {
    vector<int> res = robSub(root);
    return max(res[0], res[1]);
}
  
vector<int> robSub(TreeNode* root) {
    if (root == NULL) {
        return vector<int>(2,0);
    }

    vector<int> left = robSub(root->left);
    vector<int> right = robSub(root->right);

    vector<int> res(2,0);
    res[0] = max(left[0], left[1]) + max(right[0], right[1]);
    res[1] = root->val + left[0] + right[0];

    return res;
}









//Itrative version, first build the post-order traversal queue. Then we can replicate the recursive process.

class Solution {
private:
    deque<TreeNode*>* buildQueue(TreeNode* node){
        deque<TreeNode*>* Qptr = new deque<TreeNode*>();
        stack<TreeNode*> st;
        st.push(node);
        while(!st.empty()){
            TreeNode* tempNode = st.top();
            st.pop();
            Qptr->push_front(tempNode);
            if(tempNode->right) st.push(tempNode->right);
            if(tempNode->left) st.push(tempNode->left);
        }
        return Qptr;
    }
    
public:
    int rob(TreeNode* root) {
        if(!root) return 0;
        deque<TreeNode*>* Qptr = buildQueue(root);
        unordered_map<TreeNode*, pair<int, int>> dict;
        //The first element of pair means without robbing the house, the potential maximum profit; second means we robber the house
        dict.insert({nullptr, make_pair(0, 0)});
        for(auto it = Qptr->begin(); it != Qptr->end(); it++){
            //The max profit we can get if we rob the node
            int robNode = dict[(*it)->left].first + dict[(*it)->right].first + (*it)->val;
            //The max profit we can get if we do not rob the node
            int robnNode = max(dict[(*it)->left].first, dict[(*it)->left].second) + max(dict[(*it)->right].first, dict[(*it)->right].second);
            //Save the result to hash table
            dict[(*it)] = make_pair(robnNode, robNode);
        }
        return max(dict[root].first, dict[root].second);
    }
};
