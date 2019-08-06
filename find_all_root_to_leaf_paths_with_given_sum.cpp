
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int get_sum(vector<int> vect){
    int sum = 0;
    for(auto itr:vect){
        // cout<<itr<<" ";
        sum += itr;
    }
    // cout<<endl;
    return sum;
}

void collect_path(TreeNode* root, int k, vector<int> &cur_path, 
        vector<vector<int>> &store){
    if(root == NULL) return ;
    
    cur_path.push_back(root->val);
    if(root->left==NULL && root->right==NULL){
        int debug_sum = get_sum(cur_path);
        if(debug_sum == k){
            store.push_back(cur_path);
        }
        // cur_path.pop_back();
        // return ;
    }
    collect_path(root->left, k, cur_path, store);
    collect_path(root->right, k, cur_path, store);
    cur_path.pop_back();
    
}


vector<vector<int> > Solution::pathSum(TreeNode* root, int k) {
    vector<vector<int> > store;
    vector<int> cur_path;

    collect_path(root, k, cur_path, store);
    return store;
}
