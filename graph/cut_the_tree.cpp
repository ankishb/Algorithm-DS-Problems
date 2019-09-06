
void dfs(vector<int> adj[], vector<int> data, int u, vector<bool> &vis, int &sum){
    sum += data[u-1];
    cout<<data[u-1]<<" ";
    vis[u] = true;
    for(auto v : adj[u]){
        if(!vis[v]) dfs(adj, data, v, vis, sum);
    }
}

int cutTheTree(vector<int> data, vector<vector<int>> edges) {
    int e = edges.size();
    vector<int> dist;
    vector<int> adj[data.size()+1];
    for(auto ed : edges){
        adj[ed[0]].push_back(ed[1]);
        adj[ed[1]].push_back(ed[0]);
    }
    // for(auto ed : edges){
    //     cout<<ed[0]<<" "<<ed[1]<<" "<<data
    // }
    for(auto ed : edges){
        vector<bool> vis1(data.size()+1, false);
        int l_sum = 0, r_sum = 0;
        vis1[ed[0]] = true;
        dfs(adj, data, ed[1], vis1, l_sum);
        cout<<endl;
        vector<bool> vis2(data.size()+1, false);
        vis2[ed[1]] = true;
        dfs(adj, data, ed[0], vis2, r_sum);
        cout<<endl<<endl;
        dist.push_back(abs(l_sum - r_sum));
    }
    int min_dist = INT_MAX;
    for(auto d : dist){
        cout<<d<<" ";
        min_dist = min(min_dist, d);
    }
    
    return min_dist;
}