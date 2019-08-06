
// my solution

int get_height(TreeNode *root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    if(root->left == NULL){
        return get_height(root->right)+1;
    }
    if(root->right == NULL){
        return get_height(root->left)+1;
    }
    
    int left_h = get_height(root->left);
    int right_h = get_height(root->right);
    return min(left_h, right_h)+1;
}

int Solution::minDepth(TreeNode* A) {
    return get_height(A);
}



// another good solution
typedef TreeNode node;
void minh(node *A,int curmn,int &mn){
    if(!A)return ;
    if(!A->left && !A->right){
        mn=min(mn,curmn+1);
        return;
    }
    curmn++;
    minh(A->left,curmn,mn);
    minh(A->right,curmn,mn);
   // mn=min(mn,curmn);
    return ;
}
int Solution::minDepth(TreeNode* A) {
    int mn=INT_MAX;
    minh(A,0,mn);
    return mn;
}
