
// new one (find_max is not working correctly)
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
    bool is_leaf(TreeNode* root){
        return (root->left==NULL && root->right==NULL);
    }
    TreeNode* find_min(TreeNode *root){
        if(root == NULL) return NULL;
        if(is_leaf(root)) return root;
        if(root->left) return find_min(root->left);
        // if(root->right) return find_min(root->right);
        return root;
    }
    TreeNode* find_max(TreeNode *root){
        if(root == NULL) return NULL;
        if(is_leaf(root)) return root;
        // if(root->left) return find_min(root->left);
        if(root->right) return find_max(root->right);
        return root;
    }
    TreeNode* preorder(TreeNode* root, int key){
        if(root == NULL) return root;
        if(root->val < key){
            root->right = preorder(root->right, key);
        }
        else if(root->val > key){
            root->left = preorder(root->left, key);
        }
        else if(root->val == key){
            /* there is 3 cases:
            1. if node doesn't have any child
            2. if node has single child
            3. if node has both children
                find min in right subtree or find max in left subtree
            */
            if(root->left==NULL && root->right == NULL) return NULL;
            else if(root->left == NULL) root = root->right;
            else if(root->right == NULL) root = root->left;
            else{
                // TreeNode *temp = find_min(root->right);
                TreeNode *temp = find_max(root->left);
                // cout<<temp->val<<endl;
                root->val = temp->val;
                // root->right = preorder(root->right, temp->val);
                root->left = preorder(root->left, temp->val);
                // temp = NULL;
            }
        }
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        // cout<<find_min(root)->val<<endl;
        // cout<<find_max(root)->val<<endl;
        return preorder(root, key);
    }
};

// old one
/*
Approach:
First find the node, if exist then proceed to next steps, else we are done.
1. No child: return Null from that node
2. One child: replace the node with that child
3. Both child:
	- Find min child node in Right substree of current node and replace it. Or
	- Find Max child node in Left substree of current node and replace it. Or

- To Do, 3.1, we go to right child, and if left child exist at that node, we go in deep left of that node, otherewise, we replace with current node (i.e. right node of current node)
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
    TreeNode* find_and_delete(TreeNode* root, int data){
    	if(root == NULL) return NULL;
    	if(root->val < data){
    		root->right = find_and_delete(root->right, data);
    	}
    	else if(root->val > data){
    		root->left = find_and_delete(root->left, data);
    	}
    	else{// if(root->val == data){
    		// Now, this is interesting part
    		// case1. no child
    		if(root->left == NULL && root->right == NULL){
    			delete root;
    			root = NULL;
    		}
    		else if(root->left == NULL){
    			TreeNode* temp = root;
    			root = root->right;
    			delete temp;
    		}
    		else if(root->right == NULL){
    			TreeNode* temp = root;
    			root = root->left;
    			delete temp;
    		}
    		// case3: Both child
    		else{
    			// find min element in right subtree
    			TreeNode* right_min = root->right;
				while(right_min->left != NULL){
					right_min = right_min->left;
				}
				root->val = right_min->val;
				root->right = find_and_delete(root->right, right_min->val);
    		}
    	}
    	return root;
    }


    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        return find_and_delete(root, key);
    }
};