
/*
Cartesian binary tree:
    - It is defined using heap data structure
    - root is largest(or smallest) in the subtree
    - Doesn't follow the properties of binary tree
*/
int get_largest(vector<int> A, int l, int h){
    int max_i = l;
    for(int i=l; i<=h; i++){
        if(A[i] > A[max_i]) max_i = i;
    }
    return max_i;
}

TreeNode* build_max_heap(vector<int> A, int l, int h){
    if(l > h) return NULL;
    int n = A.size();
    int idx = get_largest(A, l, h);
    TreeNode* root = new TreeNode(A[idx]);
    root->left = build_max_heap(A, l, idx-1);
    root->right = build_max_heap(A, idx+1, h);
    return root;
}

TreeNode* Solution::buildTree(vector<int> &A) {
    int n = A.size();
    return build_max_heap(A, 0, n-1);
}
