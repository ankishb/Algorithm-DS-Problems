
class Solution {
public:
    bool is_leaf(TreeNode* root){
        return (root->left == NULL && root->right == NULL);
    }
    
    void get_sum(TreeNode* root, int flag, int &sum){
        if(root == NULL) return ;
        if(is_leaf(root) && flag == -1){
            sum += root->val;
        }
        get_sum(root->left, -1, sum);
        get_sum(root->right, +1, sum);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        get_sum(root, 0, sum);
        return sum;
    }
};



class Solution {
public:
    bool is_leaf(TreeNode* root){
        return (root->left==NULL && root->right==NULL);
    }
    void get_sum(TreeNode* root, int &sum){
        if(root == NULL) return ;
        get_sum(root->left, sum);
        get_sum(root->right, sum);
        
        if(root->left != NULL && is_leaf(root->left)){
            sum += root->left->val;
        }
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        get_sum(root, sum);
        return sum;
    }
};




int sumOfLeftLeaves(TreeNode* root, bool isleft = false) {
    if (!root) return 0;
    if (!root->left && !root->right) return isleft ? root->val : 0;
    return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
}