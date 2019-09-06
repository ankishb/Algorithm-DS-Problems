

class Codec {
public:
    void preorder(TreeNode* root, string &s){
        if(root == NULL){
            s += "@#"; return;
        }
        s += to_string(root->val) + "#";
        preorder(root->left, s);
        preorder(root->right, s);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        preorder(root, s);
        // cout<<s<<endl;
        return s;
    }
    int string_to_int(string s){
        int i = 0, value = 0;
        bool neg = false;
        if(s[i] == '-'){
            neg = true;
            i++;
        }
        while(s[i] != '\0'){
            value = value*10 + (s[i] - '0');
            i++;
        }
        return (neg == true) ? -value : value;
    }
    
    int i = 0;
    TreeNode* deserial(string data){
        if(i >= data.length() || data[i] == '@'){
            i++;
            return NULL;
        }
        string val = "";
        while(data[i] != '#'){
            val += data[i];
            i++;
        }
        int val_ = string_to_int(val);
        // cout<<val<<" "<<val_<<endl;
        TreeNode* root = new TreeNode(val_);
        i++;
        TreeNode* left = deserial(data);
        i++;
        TreeNode* right = deserial(data);
        
        if(root && left && root->val > left->val) root->left = left;
        else if(root && left && root->val < left->val) root->right = left;

        if(root && right && root->val > right->val) root->left = right;
        else if(root && right && root->val < right->val) root->right = right;

        // inorder(root); cout<<endl;
        return root;
    }
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return deserial(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));