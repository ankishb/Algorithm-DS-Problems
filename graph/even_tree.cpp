
vector<int> adj[105];
unordered_map<int, int> freq;
vector<bool> visit(105, false);

int dfs(int nv, int u, int &cur){
    if(visit[u]) return freq[u];
    visit[u] = true;
    int c = 0;
    for(auto v : adj[u]){
        if(visit[v]) continue;
        c += dfs(nv, v, cur);
    }
    if((c+1)%2 == 0){
        cur++;
        freq[u] = 0;
        return 0;
    }
    else{
        freq[u] = c+1;
        return c+1;
    }
}

// Complete the evenForest function below.
int evenForest(int t_nodes, int t_edges, vector<int> t_from, vector<int> t_to) {
    int u, v;
    for(int i=0; i<t_edges; i++){
        u = t_from[i];
        v = t_to[i];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 1;
    for(int i=1; i<=t_nodes; i++){
        int cur = 0;
        dfs(t_nodes+1, i, cur);
        ans = max(ans, cur);
    }
    // for(auto itr : freq){
    //     cout<<itr.first<<" "<<itr.second<<endl;
    // }
    return ans-1;
}