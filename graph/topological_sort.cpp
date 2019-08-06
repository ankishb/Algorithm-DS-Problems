

class Solution {
private:
    vector<vector<int>> adj;
    vector<bool> vis;
    stack<int> store;
    
public:
    void helper(int i){
        vis[i] = true;
        for(auto itr : adj[i]){
            if(!vis[itr]){
                helper(itr);
            }
        }
        store.push(i);
    }
    void topological_sort(int n){
        vis.resize(n, false);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                helper(i);
            }
        }
    }

    // numCourses: n  prerequisites: pre
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        adj.resize(n);
        int u, v;
        for(int i=0; i<pre.size(); i++){
            v = pre[i][0], u = pre[i][1];
            adj[u].push_back(v);
        }
        
        topological_sort(n);
        vector<int> ans;
        
        while(!store.empty()){
            ans.push_back(store.top());
            store.pop();
        }
        return ans;
    }
};
