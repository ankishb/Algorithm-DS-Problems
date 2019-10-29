
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
    bool search_bst(TreeNode* root, int val){
        if(root == NULL) return false;
        if(root->val == val) return true;
        if(val > root->val){
            return search_bst(root->right, val);
        }
        else{
            return search_bst(root->left, val);
        }
        return false;
    }
    bool preorder(TreeNode* root1, TreeNode* root2, int target){
        if(root1 == NULL) return false;
        int cur = root1->val;
        if(search_bst(root2, target-cur)) return true;
        
        bool left = preorder(root1->left, root2, target);
        bool right= preorder(root1->right, root2, target);
        return (left || right);
    }
    
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        return preorder(root1, root2, target) || preorder(root2, root1, target);
    }
};