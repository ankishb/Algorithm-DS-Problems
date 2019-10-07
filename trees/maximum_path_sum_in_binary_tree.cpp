
/*
At each node, 
For cur_sum we have 
    1. either current node
    2. cur_node + max(left, right)
For max_sum, we need to check
    1. if left subarray contain maximum path sum
    2. If right subarray contain maximum path sum
    3. If cur_node can give max sum
    4. If cur_node with left and right can give max_sum
Note: To avoid too many check, we can save max_sum at each node

To verify all cases in max_sum, follow this exp.
               1
              /   
             2
            / \
           3   4
*/
vector<int> helper(TreeNode* root){
    if(root == NULL) return {INT_MIN, INT_MIN};
    vector<int> l = helper(root->left);
    vector<int> r = helper(root->right);
    
    int val = root->val;
    // maxsum = max({maxsum, max(0,l[0]) + max(0,r[0]) + val});
    // node->val += max({0, leftsum, rightsum});
    int cur_sum = max(val, val+max(l[0],r[0]));
    int max_sum = max({l[1], r[1], val, val+l[0]+r[0]});


    return {cur_sum, max_sum};
}

int Solution::maxPathSum(TreeNode* root){
    if(root == NULL) return 0;
    vector<int> v = helper(root);
    return v[1];
}
