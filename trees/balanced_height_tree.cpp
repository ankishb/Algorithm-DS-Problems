
/*
naive_solution: O(n^2)
optimized_sol: O(n)
The idea is as follows for optimized-solution:
    1. Keep iterate over each node
    2. Get height of the subtree (from down to up approach)
    3. check if each subtree is balanced (again from down to up)
    
    down to up means: it goes in recurion and start moving upwards
*/
int get_height(TreeNode* root){
    if(root == NULL) return 0;
    int lh = get_height(root->left);
    int rh = get_height(root->right);
    return max(lh, rh) + 1;
}

int naive_solution(TreeNode* root) {
    if(root == NULL) return 1;
    int lh = get_height(root->left);
    int rh = get_height(root->right);
    if(abs(lh - rh) > 1) return 0;
    
    int lc = naive_solution(root->left);
    int rc = naive_solution(root->right);
    
    return (lc == rc && lc == 1);
}


int optimized_approach(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    int left_h = optimized_approach(root->left);
    if(left_h == -1) return -1;

    int right_h = optimized_approach(root->right);
    if(right_h == -1) return -1;
    
    // if(left_h == -1 || right_h == -1) return -1;
    if(abs(left_h - right_h) > 1) return -1;
    
    return max(left_h, right_h) + 1;
}

bool optimized_sol(TreeNode* root, int &h){
    if(root == NULL){
        h = 0; return true;
    }
    int lh = 0, rh = 0;
    int lc = optimized_sol(root->left,  lh);
    int rc = optimized_sol(root->right, rh);
    h = max(lh, rh) + 1;
    return (lc && rc && (abs(lh - rh) <= 1));
}

int Solution::isBalanced(TreeNode* root) {
    // return naive_solution(root);
    // return (optimized_approach(root) != -1) ;
    int h = 0;
    return optimized_sol(root, h);
}

