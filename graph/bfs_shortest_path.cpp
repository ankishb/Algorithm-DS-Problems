
vector<int> bfs(int n, int m, vector<vector<int>> edges, int s){
    vector<int> adj[n+1];
    int u, v, w;
    for(auto e : edges){
        u = e[0], v = e[1], w = e[2];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    const int inf = INT_MAX;
    vector<int> cost(n+1, INT_MAX), vis(n+1, 0);
    priority_queue< pair<int,int>, vector<pair<int,int>>, 
        greater<pair<int, int>> > pq;

    pq.push(make_pair(0,s));
    pair<int,int> top;
    while(!pq.empty()){
        top = pq.top(); pq.pop();
        w = top.first; u = top.second;
        if(vis[u] == 1) continue;
        vis[u] = 1;
        cost[u] = min(cost[u], w);
        w++;
        for(auto v : adj[u]){
            if(vis[v] == 0) pq.push(make_pair(w, v));
        }
    }
    vector<int> ans;
    for(int i=1; i<=n; i++){
        if(i == s) continue;
        else if(cost[i] == inf) ans.push_back(-1);
        else ans.push_back(cost[i]*6);
    }
    for(auto c : ans) cout<<c<<" "; cout<<endl;
    return ans;
}