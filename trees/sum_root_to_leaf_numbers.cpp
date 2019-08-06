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
	void util(TreeNode* root, int cur_sum, int &sum){
		if(root == NULL) return ;
		if(cur_sum == 0) cur_sum = root->val;
		else cur_sum = cur_sum*10 + root->val;
		
		if(root->left == NULL && root->right == NULL){
			sum += cur_sum;
		}
		util(root->left, cur_sum, sum);
		util(root->right, cur_sum, sum);
	}
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        util(root, 0, sum);
        return sum;
    }
};