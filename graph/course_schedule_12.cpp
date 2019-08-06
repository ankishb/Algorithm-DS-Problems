
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