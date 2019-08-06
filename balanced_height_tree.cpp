/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int get_height(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    int left_h = get_height(root->left);
    int right_h = get_height(root->right);
    return max(left_h, right_h)+1;
}
 
bool check_balanced(TreeNode* root){
    if(root == NULL){
        return true;
    }
    int left_h = get_height(root->left);
    int right_h = get_height(root->right);
    if( abs(right_h-left_h)<=1 && 
        check_balanced(root->left) &&
        check_balanced(root->right)){
        return true;
    }
    else{
        return false;
    }
}

int Solution::isBalanced(TreeNode* A) {
    bool ans = check_balanced(A);
    return ans;
}
