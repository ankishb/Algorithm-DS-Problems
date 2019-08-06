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