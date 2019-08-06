/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void deepest_tree(TreeNode* root, TreeNode* ans, int level, int depth){
	if(root == NULL) return;
	if(level > depth && root->left!=NULL && root->right != NULL){
		ans = root;
		depth = level;
	}

	deepest_tree(root->left, ans, level+1, depth);
	deepest_tree(root->right, ans, level+1, depth);
}

class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        TreeNode* ans = NULL;
        deepest_tree(root, ans, 1, 0);
        return ans;
    }
};