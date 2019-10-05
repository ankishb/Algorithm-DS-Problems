// new try
int prims(int n, vector<vector<int>> edges, int start) {
    vector<pair<int,int>> adj[n+1];
    int u, v, w;
    for(auto e : edges){
        u = e[0], v = e[1], w = e[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, 
    greater<pair<int,int>>> pq;
    vector<bool> vis(n+1, false);
    unordered_map<int,int> dist;
    pq.push({0, start});

    while(!pq.empty()){
        pair<int,int> p = pq.top();
        u = p.second;
        w = p.first;
        pq.pop();
        if(vis[u] == true) continue;
        vis[u] = true;
        dist[u] = w;
        
        for(auto e : adj[u]){
            v = e.first;
            w = e.second;
            if(vis[v] == false){
                pq.push({w, v});
            }
        }
    }
    int total_wt = 0;
    for(auto itr : dist){
        total_wt += itr.second;
    }
    return total_wt;
}

// old one
// Complete the prims function below.
int prims(int n, vector<vector<int>> edges, int start) {
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
    dist[start] = 0;
    int minWeight = 0;
    pq.push(make_pair(0, start));
    pair<int, int> temp;
    while(!pq.empty()){
        temp = pq.top();
        pq.pop();
        u = temp.second;
        if(vis[u] == true) continue;
        vis[u] = true;
        minWeight += temp.first;
        for(int i=0; i<adj[u].size(); i++){
            v = adj[u][i].first;
            w = adj[u][i].second;
            if(!vis[v] && dist[v] > w){
                dist[v] = w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    return minWeight;
}