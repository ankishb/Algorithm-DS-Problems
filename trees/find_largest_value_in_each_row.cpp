/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Time Complexity: O(n)
// Approach:
// 1. Use level order transversal
// 2. While shifting the level, track its maximum value 

void level_order_tran(TreeNode* root, vector<int> &ans){
    if(root == NULL) return;
	queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);
	TreeNode* top;
	int max_el = INT_MIN;
	while(true){
		if(q.size()==1 && q.front()==NULL) break;
		top = q.front();
        cout<<top->val<<" ";
		q.pop();
		max_el = max(max_el, top->val);
		if(top->left != NULL){
			q.push(top->left);
		}
		if(top->right != NULL){
			q.push(top->right);
		}

		if(q.front() == NULL){
			ans.push_back(max_el);
			max_el = INT_MIN;
			q.pop();
			q.push(NULL);
		}
	}
	return ;
}

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        level_order_tran(root, ans);
        return ans;
    }
};