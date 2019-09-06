/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void fillMap(TreeNode *root, int l, unordered_map<int,vector<int>> &myMap){
    if(root == NULL) return ;
    if(myMap.find(l) != myMap.end()){
        myMap[l].push_back(root->val);
    }
    else myMap[l] = vector<int> ({root->val});
    fillMap(root->left, l-1, myMap);
    fillMap(root->right, l+1, myMap);
}
 
// vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* root) {
vector<vector<int> > randomOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    unordered_map<int,vector<int>> myMap;
    fillMap(root, 0, myMap);
    vector<int> level;
    for(auto itr : myMap){
        level.push_back(itr.first);
    }
    sort(level.begin(), level.end());
    for(auto l : level){
        ans.push_back(myMap[l]);
    }
    return ans;
}



// correct order answer
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* root) {
    vector<vector<int>> ans;
    vector<int> temp;
    if(root == NULL) return ans;
    unordered_map<int,vector<int>> myMap;
    
    queue<pair<TreeNode*, int>> q;
    TreeNode* null = NULL;
    int nulll = INT_MAX, l;
    q.push(make_pair(root,0)); q.push(make_pair(null,nulll));
    TreeNode *front;
    pair<TreeNode*, int> p;

    while(!q.empty()){
        p = q.front();
        l = p.second;
        front = p.first;
        if(myMap.find(l) != myMap.end()){
            myMap[l].push_back(front->val);
        }
        else myMap[l] = vector<int> ({front->val});
        q.pop();
        if(front->left)  q.push(make_pair(front->left, l-1));
        if(front->right) q.push(make_pair(front->right, l+1));

        if(q.front().first == null && q.front().second == nulll){
            q.pop(); q.push(make_pair(null, nulll));
        }
        if(q.size() == 1 && q.front().first == null && q.front().second == nulll) break;
    }
    vector<int> level;
    for(auto itr : myMap){
        level.push_back(itr.first);
    }
    sort(level.begin(), level.end());
    for(auto l : level){
        ans.push_back(myMap[l]);
    }
    return ans;
}
