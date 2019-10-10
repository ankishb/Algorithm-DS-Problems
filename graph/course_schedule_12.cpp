/*
To track cycle, we can keep a flag for each node, which represent
    1. in a visiting(progress) state
    2. visited state

As we are on a node, if we come at that node again, that represent cycle
*/
// new one (course-schedule-2)
class Solution {
public:
    vector<int> vis, ans;
    stack<int> s;
    bool cycle;
    
    void topoSortUtil(vector<int> adj[], int u){
        vis[u] = -1; // in visiting state
        for(auto v : adj[u]){
            if(vis[v] == 1) continue;
            if(vis[v] == -1){
                cycle = true;
                break;
            }
            topoSortUtil(adj, v);
        }
        vis[u] = 1;
        s.push(u);
    }
    
    vector<int> findOrder(int nc, vector<vector<int>>& pre) {
        vis.resize(nc, 0);
        vector<int> adj[nc];
        cycle = false;
        int u, v;
        for(auto e : pre){
            u = e[1], v = e[0];
            adj[u].push_back(v);
        }
        for(u=0; u<nc; u++){
            if(vis[u] == 1) continue;
            topoSortUtil(adj, u);
            if(cycle) return {};
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};


// new one (course-schedule-1)
class Solution {
public:
    vector<int> vis;
    bool flag;
    void topSortUtil(vector<int> adj[], int u){
        vis[u] = -1; // in a visiting state
        for(auto v : adj[u]){
            if(vis[v] == 1) continue;
            if(vis[v] == -1){
                // visiting again
                flag = false;
                break;
            }
            topSortUtil(adj, v);
        }
        vis[u] = 1;
    }
    
    bool canFinish(int nc, vector<vector<int>>& pre) {
        vector<int> adj[nc];
        vis.resize(nc, 0);
        flag = true;
        int u, v;
        for(auto e : pre){
            u = e[1], v = e[0];
            adj[u].push_back(v);
        }
        
        for(u=0; u<nc; u++){
            if(vis[u] == 1) continue;
            topSortUtil(adj, u);
        }
        return flag;
    }
};







// old one
class Solution {
private:
    vector<vector<int>> adj;
    vector<int> vis;
    stack<int> store;
    
public:
    bool helper(int i){
        vis[i] = -1; // visiting (in progress)
        for(auto itr : adj[i]){
            if(vis[itr] == -1) return false;
            if(!vis[itr]){
                if(helper(itr) == false) return false;
            }
        }
        vis[i] = 1; // visited
        store.push(i);
        return true;
    }
    
    void topological_sort(int n, bool &cycle){
        vis.resize(n, false);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(helper(i) == false){
                    cycle = true;
                    break;
                }
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
        
        bool cycle = false;
        topological_sort(n, cycle);
        vector<int> ans;
        if(cycle) return ans;
        while(!store.empty()){
            ans.push_back(store.top());
            store.pop();
        }
        return ans;
    }
};




// another nice solution
vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        queue<int> nodes;
        vector<int> indegrees(numCourses, 0);
        int visit_node_size = 0;
        vector<int> result;
        
        for (auto item : prerequisites) {
            graph[item.second].push_back(item.first);
            ++ indegrees[item.first];
        }
        for (int node_id = 0; node_id < indegrees.size(); ++ node_id) {
            if (indegrees[node_id] == 0) {
                nodes.push(node_id);
            }
        }
        while (!nodes.empty()) {
            ++ visit_node_size;
            int node_id = nodes.front();
            nodes.pop();
            result.push_back(node_id);
            for (auto neighber_id : graph[node_id]) {
                -- indegrees[neighber_id];
                if (indegrees[neighber_id] == 0) {
                    nodes.push(neighber_id);
                }
            }
        }
        
        return visit_node_size == numCourses ? result : vector<int>();
    }