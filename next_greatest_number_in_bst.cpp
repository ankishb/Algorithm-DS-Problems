
// new try 
// O(N) time complexity (Not good, if tree is very very large)
void helper(TreeNode* root, int value, TreeNode* &ans, bool &found){
    if(found || root == NULL) return ;
    
    helper(root->left, value, ans, found);
    if(root->val > value && found == false){
        found = true;
        ans = root;
        return ;
    }
    helper(root->right, value, ans, found);
}

TreeNode* Solution::getSuccessor(TreeNode* root, int value) {
    bool found = false;
    TreeNode* ans = NULL;
    helper(root, value, ans, found);
    return ans;
}


// old one
TreeNode* searchNode(TreeNode* root, int B){
    if(root->val == B){
        return root;
    }
    else if(root->val < B){
        return searchNode(root->right, B);
    }
    return searchNode(root->left, B);
}
 
TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    TreeNode* required = searchNode(A, B);
    TreeNode* prev = NULL;
    TreeNode* ancestor = A;
    TreeNode* successor = NULL;
    
    if(required == NULL){
        return NULL;
    }
    else if(required->right != NULL){
        prev = required->right;
        TreeNode* temp = required->right;
        while(temp != NULL){
            prev = temp;
            temp = temp->left;
        }
        return prev;
    }
    else{
        while(ancestor != required){
            if(ancestor->val < B){
                ancestor = ancestor->right;
            }
            else{ // ancestor->val > B
                successor = ancestor;
                ancestor = ancestor->left;
            }
        }
    }
    
    return successor;
    
}