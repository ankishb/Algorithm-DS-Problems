
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
// We follow the sum of nodes, from root to leaf nodes, and check if sum is not exceeding from the given limit, if it exceed, delete that nodes

TreeNode* correct_tree(TreeNode* root, int limit){
	if(root == NULL) return NULL;
    
	if(root->left==NULL && root->right==NULL){
        if(root->val<limit) return NULL;
        return root;
    }
	
    if(root->left != NULL){
        root->left = correct_tree(root->left, limit-root->val);
    }
    if(root->right != NULL){
        root->right = correct_tree(root->right, limit-root->val);
    }
    // this is compulsary to check, it may be possible that, we have removed both its child as well as root node, this statement will kick away that null nodes case.
    if(root->left == root->right) return NULL;
    return root;
}

class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        int sum = 0;
        return correct_tree(root, limit);
    }
};