/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void inorder(TreeNode* root, int k, vector<int> &ans){
    if(ans.size()==k){
        return ;
    }
    if(root==NULL){
        return ;
    }
    inorder(root->left, k, ans);
    if(ans.size() != k){
        ans.push_back(root->val);
    }
    inorder(root->right, k, ans);
}
int Solution::kthsmallest(TreeNode* A, int B) {
    vector<int> ans;
    inorder(A, B, ans);
    // for(auto itr : ans){
    //     cout<<itr<<" ";
    // }
    // cout<<endl;
    return ans[ans.size()-1];
}



// constant space
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void inorder(TreeNode* root, int k, int &ans, int &count){
    // we can also use the following uncommented part,
    // but not helpful (it still run for entire tree O(N))
    // if(count == k){
    //     return;
    // }
    if(root==NULL){
        return ;
    }
    inorder(root->left, k, ans, count);
    count++;
    if(count == k){
        ans = root->val;
        return ;
    }
    inorder(root->right, k, ans, count);
}
int Solution::kthsmallest(TreeNode* A, int B) {
    int ans;
    int count = 0;
    inorder(A, B, ans, count);
    
    return ans;
}





// 
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int kthsmallestRes(TreeNode *root, int k, int &current) {
    if(root->left != NULL) {
        int res = kthsmallestRes(root->left, k, current);        
        if(current == k)
            return res;
    }
    ++current;
    if(current == k)
        return root->val;

    if(root->right != NULL) {
        int res = kthsmallestRes(root->right, k, current);        
        if(current == k)
            return res;
    }    
} 

int Solution::kthsmallest(TreeNode* root, int k) {
    int level = 0;
    return kthsmallestRes(root, k, level);
    
}




// editorial
void inorder(TreeNode* root, int& smallest, int k, int& it)
{
    if (!root)
        return;
    inorder(root->left, smallest, k, it);
    ++it;
    if (it == k)
    {
        smallest = root->val;
        return;
    }
    inorder(root->right, smallest, k, it);
}
int Solution::kthsmallest(TreeNode* root, int k) {
    int smallest = -1;
    int it = 0;
    inorder(root, smallest, k, it);
    return smallest;
}

