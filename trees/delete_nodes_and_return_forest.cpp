/*
Approach:
1. Use inorder-transversal
2. if cur_node should be deleted, then put its left and right child in disjoint set and return null
*/

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
	TreeNode* get_disjoint_set(TreeNode* root, unordered_map<int,int> to_delete, vector<TreeNode*> &store){
		if(root == NULL) return NULL;
		root->left = get_disjoint_set(root->left, to_delete, store);
		root->right = get_disjoint_set(root->right, to_delete, store);
        
        int data = root->val;
		// delete node
		if(to_delete.find(data) != to_delete.end()){
			if(root->left != NULL) store.push_back(root->left);
			if(root->right != NULL) store.push_back(root->right);
			root = NULL;
		}
		return root;
	}

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete_) {
        vector<TreeNode*> store;
        TreeNode* temp = NULL;
        int n = to_delete_.size();
        unordered_map<int, int> to_delete;
        for(int i=0; i<n; i++){
        	to_delete.insert({to_delete_[i],1});
        }
        root = get_disjoint_set(root, to_delete, store);
        if(root == NULL) return store;
        else{
        	store.push_back(root);
        	return store;
        }
    }
};











// another elegant solution using BFS
A classic BFS keeping track of the parent and whether the node was left or right from the parent. If the node is to be deleted, set the parent in the queue to nullptr.
When process the node to be deleted, set it to nullptr in the parent and push to the result if the parent on the queue is nullptr.

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> td(begin(to_delete), end(to_delete));
        // deque of node, parent, left child (true) or right child (false)
        deque<tuple<TreeNode*,TreeNode*,bool>> queue {{root, nullptr, false}};
        vector<TreeNode*> res;
        while(!queue.empty())
        {
            auto [node, parent, left] = queue.front();
            queue.pop_front();
            auto del = td.find(node->val) != end(td);
            if(!parent && !del)
                res.push_back(node);
            if(parent && del)
                if(left)
                    parent->left = nullptr;
                else
                    parent->right = nullptr;
            auto second = del ? nullptr : node;
            if(node->left)
                queue.emplace_back(node->left, second, true);
            if(node->right)
                queue.emplace_back(node->right, second, false);
        }
        return res;
    }







/*
// [Python] Recursion, with explanation 【Question seen in a 2016 interview】

The question is composed of two requirements:

    To remove a node, the child need to notify its parent about the child's existance.
    To determine whether a node is a root node in the final forest, we need to know [1] whether the node is removed (which is trivial), and [2] whether its parent is removed (which requires the parent to notify the child)

It is very obvious that a tree problem is likely to be solved by recursion. The two components above are actually examining interviewees' understanding to the two key points of recursion:

    passing info downwards -- by arguments
    passing info upwards -- by return value

Fun fact

I've seen this question in 2016 at a real newgrad interview. It was asked by a very well-known company and was a publicly known question at that time. I highly doubt that the company will ask this question again nowadays.

*/
    
class Solution(object):
    def delNodes(self, root, to_delete):
        to_delete = set(to_delete)
        res = []
        def walk(root, parent_exist):
            if root is None:
                return None
            if root.val in to_delete:
                root.left = walk(root.left, parent_exist=False)
                root.right = walk(root.right, parent_exist=False)
                return None
            else:
                if not parent_exist:
                    res.append(root)
                root.left = walk(root.left, parent_exist=True)
                root.right = walk(root.right, parent_exist=True)
                return root
        walk(root, parent_exist=False)
        return res
