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
    
    void inorder(TreeNode* root){
        if(root == NULL) return ;
        
        inorder(root->left);
        inorder(root->right);
        
        TreeNode* temp = root->right;
        if(root->left != NULL){
            // make right connection
            root->right = root->left;
            // delete left node
            root->left = NULL;
            // reach at the end of right node
            while(root->right != NULL){
                root = root->right;
            }
            // make right connection
            root->right = temp;
        }
    }
    
    void iterative1(TreeNode* root){
        while(root != NULL){
            if(root->left != NULL && root->right != NULL){
                TreeNode* temp = root->left;
                // go deeep right from this left node
                while(temp->right != NULL){
                    temp = temp->right;
                }
                // make a new connection from root->right to current temp
                temp->right = root->right;
                root->right = NULL;
            }
            // break left connection and add it to right node
            if(root->left != NULL){
                root->right = root->left;
            }
            root->left = NULL;
            root = root->right;
        }
    }
    void iterative2(TreeNode *root) {
		TreeNode* now = root;
		while (now)
		{
			if(now->left)
			{
                //Find current node's prenode that links to current node's right subtree
				TreeNode* pre = now->left;
				while(pre->right)
				{
					pre = pre->right;
				}
				pre->right = now->right;
                //Use current node's left subtree to replace its right subtree(original right 
                //subtree is already linked by current node's prenode
				now->right = now->left;
				now->left = NULL;
			}
			now = now->right;
		}
    }
    void flatten(TreeNode* root) {
        // inorder(root);
        // iterative1(root);
        iterative2(root);
    }
};