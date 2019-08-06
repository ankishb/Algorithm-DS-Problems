
// mine
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define mod 1003

int store_path(vector<int> path){
    int sum = 0;
    for(auto itr:path){
        sum=((sum*10)%mod + itr)%mod;
        // sum = sum*10 + itr;
    }
    return sum;
}

void get_path(TreeNode* root, vector<int> &cur_path, vector<int> &store){
    if(root == NULL) return;
    
    cur_path.push_back(root->val);
    if(root->left==NULL && root->right==NULL){
        int path_ = store_path(cur_path);
        store.push_back(path_);
    }
    get_path(root->left, cur_path, store);
    get_path(root->right, cur_path, store);
    cur_path.pop_back();
}

int Solution::sumNumbers(TreeNode* root) {
    vector<int> cur_path;
    vector<int> store;
    get_path(root, cur_path, store);
    int sum = 0;
    for(auto itr:store){
        sum += itr;
        sum = sum%mod;
    }
    return sum;
}



// fastest
void findLeafSum(TreeNode * node , int sum , int & total)
{
    if (node == nullptr)
        return;
    sum = ((sum * 10) % 1003 + node->val) % 1003;
    if (node->left == nullptr && node->right == nullptr)
    {
        total = (total + sum) % 1003;
        return;
    }
    findLeafSum(node->left , sum , total);
    findLeafSum(node->right , sum , total);
}

int Solution::sumNumbers(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int total = 0;
    findLeafSum(A , 0 , total);
    return total;
}
