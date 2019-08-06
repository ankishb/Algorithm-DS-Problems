/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int check_trees(TreeNode* A, TreeNode* B){
    if(A==NULL && B==NULL){
        return 1;
    }
    if(A==NULL || B==NULL){
        return 0;
    }
    
    return ((A->val == B->val) && 
            check_trees(A->left, B->left) && 
            check_trees(A->left, B->left));
}
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    return check_trees(A, B);
}
