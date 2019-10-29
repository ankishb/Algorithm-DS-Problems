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
    int helper(TreeNode* root, int &ans){
        if(root == NULL) return 0;
        int l = helper(root->left, ans);
        int r = helper(root->right, ans);
        ans = max(ans, l+r);
        return max(l, r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        int temp = helper(root, ans);
        return ans;
    }
};