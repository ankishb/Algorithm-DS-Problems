
// new with dynamic array
/*This is a function problem.You only need to complete the function given below*/
// The Graph structure is as folows
/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*   NOTE: You must return dynamically allocated array 
*/
void util(vector<int> adj[], int u, unordered_set<int> &vis, stack<int> &s){
    vis.insert(u);
    for(auto v : adj[u]){
        if(vis.count(v) == 1) continue;
        util(adj, v, vis, s);
    }
    s.push(u);
}

int* topoSort(int V, vector<int> adj[])
{
    unordered_set<int> vis;
    stack<int> s;
    for(int u=0; u<V; u++){
        if(vis.count(u) == 1) continue;
        util(adj, u, vis, s);
    }
    static int ans[50];
    int i = 0;
    while(!s.empty()){
        ans[i] = s.top();
        s.pop(); i++;
    }
    return ans;
}


// old sol(with vector)
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
