/*
Approach:
1. Find the max depth of tree
2. Now find the subtree at depth 1(from downwards), which have its child.
*/
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
public:
	int get_height(TreeNode* root){
		if(root == NULL) return 0;
		int lh = get_height(root->left);
		int rh = get_height(root->right);
		return max(lh, rh) + 1;
	}

	void get_deepest_subtree(TreeNode* root, int height, TreeNode** ans){
		if(root == NULL) return ;
        // cout<<root->val<<" "<<height<<endl;
		if(height==2){
            if(root->left!=NULL && root->right!=NULL){
                *ans = root;
                cout<< "::: " << root->val <<" ::: ";
                return ;
		    }
            else if(root->left!=NULL || root->right!=NULL){
                *ans = (root->left != NULL) ? root->left : root->right;
                return ;
		    }
        }
        
		get_deepest_subtree(root->left, height-1, ans);
		get_deepest_subtree(root->right, height-1, ans);

	}

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int height = get_height(root);
        if(height == 1) return root;
        TreeNode* ans = NULL;
        get_deepest_subtree(root, height, &ans);
        return ans;
    }
};