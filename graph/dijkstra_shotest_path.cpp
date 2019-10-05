
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