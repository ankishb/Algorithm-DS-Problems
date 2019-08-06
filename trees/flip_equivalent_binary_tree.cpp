/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool check_mirror_tree(TreeNode* root1, TreeNode* root2){
    if(root1==NULL && root2==NULL) return true;
    if(root1==NULL && root2!=NULL) return false;
    if(root1!=NULL && root2==NULL) return false;
    // cout<<root1->val<<" : "<<root2->val<<endl;
    if(root1->val != root2->val) return false;
    
    bool l_check_flip = check_mirror_tree(root1->left, root2->right);
    bool r_check_flip = check_mirror_tree(root1->right, root2->left);
    bool l_check_same = check_mirror_tree(root1->left, root2->left);
    bool r_check_same = check_mirror_tree(root1->right, root2->right);
    // cout<<l_check<<" : "<<r_check<<endl;
    return (l_check_flip && r_check_flip)||(l_check_same && r_check_same);
}

    
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return check_mirror_tree(root1, root2);
    }
};