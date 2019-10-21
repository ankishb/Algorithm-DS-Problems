
// super-newest
/*This is a function problem.You only need to complete the function given below*/
/*  Function to implement Dijkstra
*   graph: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/
#define inf INT_MAX
#define pii pair<int,int>

class helper{
public:
    vector<int> dist;
    vector<bool> vis;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
        
    void run(vector<pii> adj[], int src, int n){
        dist.resize(n, inf);
        dist[src] = 0;
        vis.resize(n,false);
        pq.push({0,src});
        while(!pq.empty()){
            int w = pq.top().first;
            int u = pq.top().second;
            // cout<<u<<" "<<w<<" "<<vis[u]<<endl;
            pq.pop();
            if(vis[u]) continue;
            vis[u] = true;
            
            for(auto itr : adj[u]){
                int v = itr.first;
                int d = itr.second;
                // cout<<v<<" :: "<<d<<endl;
                if(!vis[v] && dist[v] > dist[u]+w){
                    dist[v] = dist[u] + d;
                    pq.push({dist[u]+d, v});
                }
            }
        }
    }
};
void dijkstra(vector<vector<int>> graph, int src, int V){
    vector<pii> adj[V];
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(i==j || graph[i][j]==0) continue;
            adj[i].push_back({j,graph[i][j]});
        }
    }
    // for(int i=0; i<V; i++){
    //     cout<<i<<" :: ";
    //     for(auto v : adj[i]){
    //         cout<<v<<" ";
    //     }
    //     cout<<endl;
    // }
    
    helper h;
    h.run(adj, src, V);
    for(auto d : h.dist){
        cout<<d<<" ";
    }
    // cout<<endl;
}



//super new
vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {
    int u, v, w;
    vector<pair<int,int>> adj[n+1];
    for(auto e : edges){
        adj[e[0]].push_back({e[1], e[2]});
        adj[e[1]].push_back({e[0], e[2]});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, 
    greater<pair<int,int>>> pq; // {dist, v}
    unordered_map<int,int> map; // store result
    for(int i=1; i<=n; i++){
        map[i] = -1;
    }
    pq.push({0, s});
    vector<bool> vis(n+1);
    while(!pq.empty()){
        pair<int,int> p = pq.top();
        w = p.first;
        u = p.second;
        pq.pop();
        if(vis[u] == true) continue;
        vis[u] = true;
        map[u] = w;
        
        for(auto itr : adj[u]){
            if(vis[itr.first] == false){
                pq.push({w+itr.second, itr.first});
            }
        }
    }
    vector<int> ans;
    for(int i=1; i<=n; i++){
        if(i == s) continue;
        ans.push_back(map[i]);
    }
    return ans;
}


// new try
vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {
    int u, v, w;
    vector<pair<int,int>> adj[n+1];
    for(auto e : edges){
        adj[e[0]].push_back({e[1], e[2]});
        adj[e[1]].push_back({e[0], e[2]});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, 
    greater<pair<int,int>>> pq; // {dist, v}
    unordered_map<int,int> dist; // store result
    for(int i=1; i<=n; i++){
        dist[i] = INT_MAX;
    }
    pq.push({0, s});
    dist[s] = 0;
    vector<bool> vis(n+1);
    while(!pq.empty()){
        pair<int,int> p = pq.top();
        u = p.second;
        pq.pop();
        if(vis[u] == true) continue;
        vis[u] = true;
        
        
        for(auto itr : adj[u]){
            v = itr.first;
            w = itr.second;
            if(!vis[v] && dist[v] > dist[u]+w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    vector<int> ans;
    int wts;
    for(int i=1; i<=n; i++){
        if(i == s) continue;
        if(dist[i] == INT_MAX) wts = -1;
        else wts = dist[i];
        ans.push_back(wts);
    }
    return ans;
}


// old one
// Complete the shortestReach function below.
vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {
    vector<int> dist(n+1, INT_MAX);
    vector<bool> vis(n+1, false);
    vector<pair<int,int>> adj[n+1];
    int u, v, w;
    for(auto e : edges){
        u = e[0], v = e[1], w = e[2];
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    dist[s] = 0;
    pq.push(make_pair(0, s));
    pair<int, int> temp;
    while(!pq.empty()){
        temp = pq.top();
        pq.pop();
        u = temp.second;
        if(vis[u] == true) continue;
        vis[u] = true;
        for(int i=0; i<adj[u].size(); i++){
            v = adj[u][i].first;
            w = adj[u][i].second;
            if(!vis[v] && dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    vector<int> ans;
    for(int i=1; i<n+1; i++){
        if(i == s) continue;
        if(dist[i] == INT_MAX){
            ans.push_back(-1);
        }
        else{
            ans.push_back(dist[i]);
        }
    }
    return ans;
}