
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
    vector<int> rightSideView(TreeNode* root) {
        // return iterativeSolution(root);
        return recursiveSolution(root);
    }
    vector<int> iterativeSolution(TreeNode* root) {
        vector<int> store;        
        if(root == NULL) return store;
        queue<TreeNode*> q;
        q.push(root); q.push(NULL);
        TreeNode *front;
        while(!q.empty()){
            front = q.front(); q.pop();
            if(q.front() == NULL){ store.push_back(front->val); }         
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
            if(q.front() == NULL && q.size() == 1) break;
            if(q.front() == NULL){ q.pop(); q.push(NULL); }
        }
        return store;
    }
    
    void recursion(TreeNode *root, int level, vector<int> &res){
        if(root==NULL) return ;
        if(res.size()<level) res.push_back(root->val);
        recursion(root->right, level+1, res);
        recursion(root->left, level+1, res);
    }
    
    vector<int> recursiveSolution(TreeNode *root) {
        vector<int> res;
        recursion(root, 1, res);
        return res;
    }
};