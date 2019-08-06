
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void find_max_diff(TreeNode* root, int min_el, int max_el, int &max_diff){
	// Note that we are making local variable in recusion, instead of global variable in recursion, which we usually make by passing vriable by reference
	if(root == NULL) return;
	min_el = min(min_el, root->val);
	max_el = max(max_el, root->val);
	max_diff = max(max_diff, abs(max_el-min_el));
	find_max_diff(root->left, min_el, max_el, max_diff);
	find_max_diff(root->right, min_el, max_el, max_diff);
}

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        find_max_diff(root, INT_MAX, INT_MIN, ans);
        return ans;
    }
};