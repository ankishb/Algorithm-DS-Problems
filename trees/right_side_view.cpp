/*
Best solution is rec_sol1.
    1. init key = 1 and store has size 0, we use this little trick
    2. We are visiting right node first, so 
        1. if size is less than key, store root's data
        2. else just move on
*/
class Solution {
public:
    unordered_set<int> depths;
    vector<int> store;
    
    vector<int> iter_sol(TreeNode* root) {
        if(root == NULL) return store;
        queue<TreeNode*> q;
        q.push(root); q.push(NULL);
        TreeNode *front;
        while(!q.empty()){
            front = q.front(); q.pop();
            if(q.front() == NULL){ store.push_back(front->val); }         
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
            if(q.front() == NULL && q.size() == 1) break;
            if(q.front() == NULL){ q.pop(); q.push(NULL); }
        }
        return store;
    }
    
    void recursion(TreeNode *root, int level){
        if(root==NULL) return ;
        if(store.size()<level) store.push_back(root->val);
        recursion(root->right, level+1);
        recursion(root->left, level+1);
    }
    
    vector<int> rec_sol1(TreeNode *root) {
        recursion(root, 1);
        return store;
    }
    
    void preorder(TreeNode* root, int depth){
        if(root == NULL) return ;
        if(depths.find(depth)  == depths.end()){
            store.push_back(root->val);
            depths.insert(depth);
        }
        preorder(root->right, depth+1);
        preorder(root->left, depth+1);
    }
    vector<int> rec_sol2(TreeNode* root) {
        preorder(root, 0);
        return store;
    }
    
    vector<int> rightSideView(TreeNode* root) {
        // return iter_sol(root);
        return rec_sol1(root);
        // return rec_sol2(root);
    }
};