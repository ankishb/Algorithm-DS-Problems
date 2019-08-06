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