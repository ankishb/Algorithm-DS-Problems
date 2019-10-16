
/*
We need a valid definition of binary tree. 
If there is right node, then we represent left node with "NULL", if not present
So we need to represent this case with "()" for valid representation
*/
class Solution {
public:
    string tree2str(TreeNode* t) {
        if(t == NULL) return "";
        if(!t->left && !t->right){
            return to_string(t->val);
        }
        
        string left = tree2str(t->left);
        string right = tree2str(t->right);
        if(t->right){
            right = "(" + right + ")"; 
        }
        left = "(" + left + ")";
        

        return to_string(t->val)+left+right;
    }
};





class Solution {
public:
    string get_str(TreeNode* root){
        if(root == NULL) return "";
        if(root->left==NULL && root->right==NULL){
            string temp = to_string(root->val);
            return temp;
        }
        string left = get_str(root->left);
        string right = get_str(root->right);
        // if(left != "") left = "(" + left + ")";
        if(right != "") right = "(" + right + ")";
        left = "(" + left + ")";
        // right = "(" + right + ")";
        return to_string(root->val) + left + right;
    }
        
        
    string tree2str(TreeNode* t) {
        return get_str(t);
    }
};





public class Solution {
    public String tree2str(TreeNode t) {
        if (t == null) return "";
        
        String result = t.val + "";
        
        String left = tree2str(t.left);
        String right = tree2str(t.right);
        
        if (left == "" && right == "") return result;
        if (left == "") return result + "()" + "(" + right + ")";
        if (right == "") return result + "(" + left + ")";
        return result + "(" + left + ")" + "(" + right + ")";
    }
}