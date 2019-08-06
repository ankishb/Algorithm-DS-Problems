
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    unordered_map<int, TreeNode*> my_map;
public:
    bool matched(TreeNode* root1, TreeNode* root2){
        if(root1==NULL && root2==NULL) return true;
        if(root1==NULL || root2==NULL) return false;
        // cout<< root1->val <<" "<< root2->val << endl;
        bool left = matched(root1->left, root2->left);
        bool right = matched(root1->right, root2->right);
        return (root1->val == root2->val) && left && right ;
    }
    void inorder(TreeNode* root, TreeNode* target, bool &flag){
        if(flag == true) return;
        if(root == NULL) return;
        if(root->val == target->val){
            if(matched(root, target)){
                flag = true;
                return;
            }
        }
        
        if(!flag) inorder(root->left, target, flag);
        if(!flag) inorder(root->right, target, flag);
                
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        bool flag1=false, flag2=false;
        inorder(s, t, flag1);
        if(flag1) return true;
        inorder(t, s, flag2);
        return flag2;
    }
};