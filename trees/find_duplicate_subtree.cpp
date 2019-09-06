
// working
class Solution {
public:
    vector<TreeNode*> ans;
    unordered_map<string, vector<TreeNode*>> map;
    string serialize(TreeNode* root){
        if(root == NULL) return "";
        string left  = serialize(root->left);
        string right = serialize(root->right);
        string s = "(" + left + to_string(root->val) + right + ")";
        map[s].push_back(root);
        return s;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // preorder(root);
        string s = serialize(root);
        for(auto itr : map){
            if(itr.second.size() > 1){
                ans.push_back(itr.second[0]);
            }
        }
        return ans;
    }
};



// not working
class Solution {
public:
    vector<TreeNode*> ans;
    unordered_map<int, set<TreeNode*>> m;
    
    bool matched(TreeNode* root1, TreeNode* root2){
        if(root1 == NULL && root2 == NULL) return true;
        if(root1 == NULL || root2 == NULL) return false;
        if(root1->val != root2->val) return false;
        
        bool left = matched(root1->left, root2->left);
        bool right = matched(root1->right, root2->right);
        return (left && right);
    }
    
    void preorder(TreeNode* root){
        if(root == NULL) return ;
        if(m.find(root->val) != m.end()){
            for(auto r : m[root->val]){
                if(matched(root, r)){
                    ans.push_back(r);
                    root->left = NULL;
                    root->right = NULL;
                    break;
                }
                m[root->val].insert(root);
            }
                
        }
        m[root->val].insert(root);
        
        preorder(root->left);
        preorder(root->right);
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        preorder(root);
        return ans;
    }
};