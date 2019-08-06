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
// 1. use postorder tranversal
// 2. Remove the leaf node, if it is 0

TreeNode* pruning(TreeNode* root){
	if(root == NULL) return NULL;
    
	root->left = pruning(root->left);
	root->right = pruning(root->right);
	// cout<<root->val<<" ";
	if(root->left==NULL && root->right==NULL && root->val==0){
		return NULL;
	}
	else{
        return root;
    }
}

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        return pruning(root);
    }
};