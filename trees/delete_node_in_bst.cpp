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