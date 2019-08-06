/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* check_tree(TreeNode* root, int limit){
    if(root->left == NULL && root->right == NULL){
        if(root->val < limit){
            return NULL;
        }
        return root;
    }
    if(root->left != NULL){
        root->left = check_tree(root->left, limit - root->val);
    }
    if(root->right != NULL){
        root->right = check_tree(root->right, limit - root->val);
    }

    if(root->left == root->right){
        root = NULL;
    }
    return root;
}

class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return check_tree(root, limit);
    }
};


//////////////////////////////////////////////////////////
// simple approach
class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if (root->left == root->right)
            return root->val < limit ? NULL : root;
        if (root->left)
            root->left = sufficientSubset(root->left, limit - root->val);
        if (root->right)
            root->right = sufficientSubset(root->right, limit - root->val);
        return root->left == root->right ? NULL : root;
    }
};