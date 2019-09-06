
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        if(root == NULL) return inorder;
        stack<TreeNode*> s;
        unordered_set<TreeNode*> vis;
        s.push(root);
        vis.insert(root);
        TreeNode* top;
        while(!s.empty()){
            top = s.top();
            if(top->left && vis.find(top->left) == vis.end()){
                s.push(top->left);
                vis.insert(top->left);
                continue;
            }
            else{
                inorder.push_back(top->val);
                s.pop();
                if(top->right && vis.find(top->right) == vis.end()){
                    s.push(top->right);
                    vis.insert(top->right);
                }   
            }
        }
        return inorder;
    }
};



// previous code for geekforgeeks
void inorder_transversal(node* root){
	stack<node*> s;
	node* cur_node = root;
	while(cur_node != NULL || !s.empty()){

		while(cur_node != NULL){
			s.push(cur_node);
			cur_node = cur_node->left;
		}

		// now it reach at the leaf, print it and go one node back, that is the parent of this leaf node.
		cur_node = s.top();
		s.pop();
		cout<<cur_node->data<<" ";
		cur_node = cur_node->right;
	}
}