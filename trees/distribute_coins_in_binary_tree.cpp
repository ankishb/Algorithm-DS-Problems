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
// 1. Use post transversal
// 2. From each node, we return the (cur_coins - 1) and moves will be moves + abs(cur_coins - 1)

int distribute_coins(TreeNode* root, int &sum){
	if(root == NULL) return 1;
	
	int l_moves = distribute_coins(root->left, sum);
	int r_moves = distribute_coins(root->right, sum);
    sum += abs(l_moves-1) + abs(r_moves-1);
	return root->val + (l_moves-1) + (r_moves-1);
}


class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int sum = 0;
        int sth = distribute_coins(root, sum);
        return sum;
    }
};