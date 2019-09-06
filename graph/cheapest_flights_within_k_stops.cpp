
#define iPair pair<int, int>
class Solution {
public:
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> dist;
    vector<int> parent;
    vector<bool> vis;
    int u, v, w, stopsCount;
    // int minCost = INT_MAX;
    
    void minSpanningTree(vector<iPair> adj[], int src, int dst){
        dist[src] = 0;
        pq.push(make_pair(0, src));
        while(!pq.empty()){
            iPair temp = pq.top();
            pq.pop();
            u = temp.second;
            if(vis[u] == true) continue;
            vis[u] = true;
            
            for(int i=0; i<adj[u].size(); i++){
                v = adj[u][i].first, w = adj[u][i].second;
                if(vis[v] == false && dist[v] > w){
                    dist[v] = w;
                    parent[v] = u;
                    pq.push(make_pair(w, v));
                }
            }
        }
    }
    
    void getMinCostPath(vector<iPair> adj[], int src, int dst, int wts, int stops, int &minCost){
        // cout<< src <<" "<< dst <<" "<< wts <<" "<< stops <<endl;
        if(stops < -1) return ;
        if(src == dst && stops >= -1){
            minCost = min(minCost, wts);
            return ;
        }
        
        int u = src;
        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i].first;
            // cout<< u <<" "<< v <<" "<< wts+adj[u][i].second <<" "<< stops-1 <<endl;
            // wts = wts + adj[u][i].second;
            // stops -= 1;
            getMinCostPath(adj, v, dst, wts + adj[u][i].second, stops-1, minCost);
            // wts = wts - adj[u][i].second;
            // stops += 1;
        }
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // return previous_solution(n, flights, src, dst, K);
        // return new_solution(n, flights, src, dst, K);
        return bellman_ford(n, flights, src, dst, K);
    }
    
    int bellman_ford(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int inf = INT_MAX;
        vector<int> dist(n, inf);
        dist[src] = 0;
        
        for(int i=0; i<=k; i++){
            vector<int> Dist(dist);
            for(auto e : flights){
                u = e[0], v = e[1], w = e[2];
                Dist[v] = min(Dist[v], dist[u] + w);
            }
            dist = Dist;
        }
        return dist[dst] == inf ? -1 : dist[dst];
    }
    
    
    int previous_solution(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<iPair> adj[n];
        dist.resize(n, INT_MAX);
        vis.resize(n, false);
        parent.resize(n, -1);
        
        
        for(auto flight : flights){
            u=flight[0], v=flight[1], w=flight[2];
            adj[u].push_back(make_pair(v,w));
        }
        
        // minSpanningTree(adj, src, dst);
        // cout<<"dist array: ";
        // for(auto d : dist) cout<< d <<" ";
        // cout<<"\nparent array: ";
        // for(auto p : parent) cout<< p <<" ";
        // cout<<endl;
        
        // v = dst;
        // u = parent[v];
        // w = 0;
        // stopsCount = 0;
        // while(u != src){
        //     stopsCount++;
        //     w += dist[v];
        //     u = parent[u];
        // }
        // if(stopsCount <= k) return w;
        w = 0;
        int minCost = INT_MAX;
        getMinCostPath(adj, src, dst, w, K, minCost);
        return (minCost == INT_MAX) ? -1 : minCost;
    }
    
    
    
    void helper(vector<iPair> adj[], int u, int dst, int K, int steps, int cost, int &minCost, vector<bool> &vis){
        if(steps > K) return;
        if(steps <= K && u == dst){
            cout<<u<<" "<<steps<<endl;
            minCost = min(minCost, cost);
            return;
        }
        for(auto pair : adj[u]){
            if(steps < K){
                int v = pair.first;
                int w = pair.second;
                if(vis[v] == true) continue;
                vis[v] = true;
                helper(adj, v, dst, K, steps+1, cost+w, minCost, vis);
            }
        }
    }
    
    int new_solution(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<iPair> adj[n];
        vis.resize(n, false);
        int minCost = INT_MAX;
        int steps = 0;
        for(auto flight : flights){
            u=flight[0], v=flight[1], w=flight[2];
            adj[u].push_back(make_pair(v,w));
        }
        helper(adj, src, dst, K+1, steps, 0, minCost, vis);
        
        return (minCost == INT_MAX) ? -1 : minCost;
    }
};
