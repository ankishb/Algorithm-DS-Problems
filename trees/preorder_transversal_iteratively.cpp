
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if(root == NULL) return preorder;
        deque<TreeNode*> q;
        q.push_front(root);
        TreeNode* front;
        while(!q.empty()){
            front = q.front(); q.pop_front();
            preorder.push_back(front->val);
            if(front->right) q.push_front(front->right);
            if(front->left) q.push_front(front->left);
            
        }
        return preorder;
    }
};