// Function to construct and print MST for a graph represented using adjacency matrix representation, with V vertices. 
// graph[i][j] = weight if edge exits else INT_MAX

int spanningTree(int V,int E, vector<vector<int> > graph){
    // priority_queue<int, vector<int>, greater<int> > pq;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V, false);
    int u = 0;
    dist[u] = 0;
    pq.push(make_pair(0, u));

    int v, w, cur_dist;
    while(!pq.empty()){
        // print_heap(pq);
        pair<int, int> pair_ = pq.top();
        pq.pop();
        u = pair_.second;
        // cout<<pair_.first<<" : "<<pair_.second<<endl;
        if(dist[u] > pair_.first){
            dist[u] = pair_.first;   
        }
        visited[u] = true;

        for(int j=0; j<V; j++){
            if(graph[u][j] != INT_MAX){
                if(!visited[j]){
                    v = j; w = graph[u][j];
                    pq.push(make_pair(w, v));
                }
            }
        }
    }
    int ans = 0;
    // cout<<endl;
    for(auto itr : dist){
        // cout<<itr<<" ";
        ans += itr;
    }
    return ans;
}
