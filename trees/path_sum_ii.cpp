
class Solution {
public:
    vector<vector<int>> store;
    vector<int> path;
    
    bool is_leaf(TreeNode* root){
        return (root->left == NULL && root->right == NULL);
    }
    
    void fill_path(TreeNode* root, int sum, int total){
        if(root == NULL) return ;
        if(is_leaf(root)){
            if(sum == total+root->val){
                path.push_back(root->val);
                store.push_back(path);
                path.pop_back();
            }
            return ;
        }
        path.push_back(root->val);
        total += root->val;
        fill_path(root->left, sum, total);
        fill_path(root->right, sum, total);
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        fill_path(root, sum, 0);
        return store;
    }
};



// new try
class Solution {
public:
    vector<vector<int>> store;
    vector<int> cur;
    bool is_leaf(TreeNode* root){
        return (root->left == NULL && root->right == NULL);
    }
    
    void helper(TreeNode* root, int sum, int cur_sum){
        if(root == NULL) return;
        cur_sum += root->val;
        cur.push_back(root->val);
        if(is_leaf(root) && (sum == cur_sum)){
            store.push_back(cur);
        }
        
        helper(root->left, sum, cur_sum);
        helper(root->right, sum, cur_sum);
        cur_sum -= root->val;
        cur.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        helper(root, sum, 0);
        return store;
    }
};


// old one
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define vv vector<vector<int> > 
#define v vector<int> 

void collect_paths(TreeNode* root, vv &store, v &cur_path, int &path_sum, int x){
    if(root == NULL) return;

    path_sum += root->val;
    cur_path.push_back(root->val);
    if(path_sum == x && root->left==NULL && root->right==NULL){
        store.push_back(cur_path);
    }
    collect_paths(root->left, store, cur_path, path_sum, x);
    collect_paths(root->right, store, cur_path, path_sum, x);
    cur_path.pop_back();
    path_sum -= root->val;
}


class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vv ans;
        v store;
        int path_sum = 0;
        collect_paths(root, ans, store, path_sum, sum);
        // for(auto itr:store) cout<<itr<<" ";
        return ans;
    }
};