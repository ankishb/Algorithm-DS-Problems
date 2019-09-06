/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void inorder_trans(TreeNode* root, string &s){
        if(root == NULL){
            s += "@#";
            return;
        }
        s += to_string(root->val) + "#";
        inorder_trans(root->left, s);
        inorder_trans(root->right, s);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        inorder_trans(root, s);
        // cout<<s<<endl;;
        return s;
    }
    int string_to_int(string s){
        // cout<<s<<" ";
        bool neg = false;
        int i = 0, value = 0;
        if(s[i] == '-'){
            neg = true;
            i++;
        }
        while(s[i] != '\0'){
            value = value*10 + (s[i]-'0');
            i++;
        }
        // cout<<value<<" ";
        return (neg == true) ? 0-value : value;
    }
    int i = 0;
    TreeNode* deserial(string data){
        if(i >= data.length() || data[i] == '@'){
            return NULL;
        }
        string val = "";
        while(data[i] != '#'){
            val += data[i];
            i++;
        }
        // cout<<data[i]<<" "<<i<<endl;
        int val_ = string_to_int(val);
        TreeNode *root = new TreeNode(val_);
        i += 1; // here index is pointing at #, so increase by 1 only.
        root->left = deserial(data);
        i += 2; // Now index is pointing before #, so we need to increase by 2.
        root->right= deserial(data);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return deserial(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));