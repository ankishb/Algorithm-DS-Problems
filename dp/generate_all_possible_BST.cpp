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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0){
            vector<TreeNode*> temp;
            return temp;
        }
        return helper(1, n);
    }
    
    vector<TreeNode*> helper(int start, int end){
        vector<TreeNode*> allTree;
        if(start > end){
            allTree.push_back(NULL);
            return allTree;
        }
        vector<TreeNode*> left, right;
        for(int i=start; i<=end; i++){
            left  = helper(start, i-1);
            right = helper(i+1, end);
            
            for(auto leftTree : left){
                for(auto rightTree : right){
                    TreeNode* root = new TreeNode(i);
                    root->left  = leftTree;
                    root->right = rightTree;
                    allTree.push_back(root);
                }
            }
        }
        return allTree;
    }
};