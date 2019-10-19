
bool run_bfs(int G[][MAX], int V, int src){
    int color[V];
    for(int i=0; i<V; i++){
        color[i] = -1;
    }
    color[src] = 0;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v=0; v<V; v++){
            if(G[u][v] == 0) continue;
            // self loop
            if(G[v][v] == 1) return false;
            
            // if already colored (check if that is good)
            if(color[v] != -1){
                if(color[u] == color[v]){
                    return false;   
                }
            }
            else{
                color[v] = 1-color[u];
                q.push(v);
            }
        }
    }
    return true;
}

bool isBipartite(int G[][MAX],int V){
    for(int i=0; i<V; i++){
        if(!run_bfs(G, V, i)) return false;
    }
    return true;
}