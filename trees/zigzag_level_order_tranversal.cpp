
// new try
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* root) {
    if(root == NULL) return {{}};
    queue<TreeNode*> q;
    vector<vector<int>> store;
    store.push_back({root->val});
    vector<int> cur;
    q.push(root);
    q.push(NULL);
    int level = 1;
    while(!q.empty()){
        TreeNode* front = q.front();
        q.pop();
        if(front->left) q.push(front->left);
        if(front->right) q.push(front->right);
    
        if(front->left) cur.push_back(front->left->val);
        if(front->right) cur.push_back(front->right->val);
    
        if(q.front() == NULL){
            if(level%2 == 1) reverse(cur.begin(), cur.end());
            if(cur.size() > 0) store.push_back(cur);
            q.pop(); 
            q.push(NULL);
            level++;
            cur.clear();
        }
        if(q.front() == NULL && q.size() == 1) break;
    }
    return store;
}


// old one
class Solution {
public:
    vector<vector<int>> store;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // recursive(root, 0);
        iterative(root);
        return store;
    }
    
    void recursive(TreeNode* root, int level){
        if(root == NULL) return;
        if(store.size() <= level){
            store.push_back({}); // create new level
        }
        if(level % 2 == 0){
            store[level].push_back(root->val);
        }
        else{
            // put value in front(as it should be in reverse order)
            store[level].insert(store[level].begin(), root->val);
        }
        recursive(root->left, level+1);
        recursive(root->right, level+1);
    }
    
    
    void iterative(TreeNode* root) {
        queue<TreeNode*> q;
        if(root == NULL) return ;
        q.push(root);
        store.push_back({root->val});
        q.push(NULL);
        TreeNode* front;
        bool level = 0;
        while(true){
            front = q.front();
            q.pop();
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
            
            if(q.front() == NULL && q.size()==1) break;
            if(q.front() == NULL){
                q.pop();
                store_level(q, level);
                level = 1 - level;
                q.push(NULL);
            }
        }
    }
    void store_level(queue<TreeNode*> q, bool even){
        int n = q.size();
        vector<int> temp(n, 0);
        int i = (even) ? 0 : n-1;
        while(!q.empty()){
            temp[i] = q.front()->val;
            q.pop();
            (even) ? i++ : i--;
        }
        store.push_back(temp);
    }
    
};