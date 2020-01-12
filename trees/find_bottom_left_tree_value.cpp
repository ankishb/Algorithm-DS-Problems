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
    int ans;
    
    int get_depth(TreeNode* root){
        if(root == NULL) return 0;
        int ld = get_depth(root->left);
        int rd = get_depth(root->right);
        return 1 + max(ld, rd);
    }
    
    void get_ans(TreeNode* root, int d, int depth, bool &found){
        if(root == NULL) return ;
        if(!found && d == depth){
            ans = root->val;
            found = true;
        }
        if(found) return;
        get_ans(root->left, d+1, depth, found);
        get_ans(root->right, d+1, depth, found);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        int d = get_depth(root) - 1;
        // cout<<d<<" ";
        bool flag = false;
        get_ans(root, 0, d, flag);
        return ans;
    }
};