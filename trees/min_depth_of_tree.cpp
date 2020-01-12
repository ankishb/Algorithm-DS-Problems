
/*
    This is little tricky, only for the case when there is
    only single path from root to leaf.
    
    Best way is to find the length of the path from root to
    leaf and always keep minimum value.
*/
class Solution {
public:
    bool is_leaf(TreeNode* root){
        return (!root->left && !root->right);
    }
    
    void min_depth(TreeNode* root, int &ans, int d){
        if(root == NULL) return ;
        if(is_leaf(root)){
            ans = min(ans, d);
            return ;
        }
        min_depth(root->left, ans, d+1);
        min_depth(root->right, ans, d+1);
    }
    
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        if(is_leaf(root)) return 1;
        int depth = INT_MAX;
        min_depth(root, depth, 1);
        return depth;
        
    }
};


// new try
class Solution {
public:
    void get_depth(TreeNode* root, int d, int &depth) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            depth = min(depth, d);
        }
        get_depth(root->left, d+1, depth);
        get_depth(root->right, d+1, depth);
    }
    
    int minDepth(TreeNode* root){
        int depth=INT_MAX;
        if(root == NULL) return 0;
        get_depth(root, 1, depth);
        return (depth == INT_MAX) ? 1 : depth;
    }
};


// old and complicated, my solution
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
