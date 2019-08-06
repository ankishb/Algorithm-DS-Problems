
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Approach:
// For serialize: we just do a inorder & postorder transversal and concatenate each string with '_', and to distinguish each element, we seperated them '#'
// For deserialize: we construct tree using both transversal strings

class Codec {
public:
	string convert_int_to_string(int data){
		string ans = "";
		while(data != 0){
			ans += (ans%10 + '0');
			ans = ans/10;
		}
		return ans;
	}
	void inorder(TreeNode* root, string &ans){
		if(root == NULL) return;
		inorder(root->left);
		ans += convert_int_to_string(root->val);
		ans += '#';
		inorder(root->right);
	}

	void postorder(TreeNode* root, string &ans){
		if(root == NULL) return;
		postorder(root->left);
		postorder(root->right);
		ans += convert_int_to_string(root->val);
		ans += '#';
	}
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        inorder(root, ans);
        ans += "_";
        postorder(root, ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));