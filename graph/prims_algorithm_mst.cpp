
// with adjacency matrix(simple c/c++ without contains)
#include <iostream>
using namespace std;
#include <cstring>
#define inf 1E9

int T[10][10];

struct queue{
    int w, v;
};

int get_prims_mst_weight(int nv, int src){
    queue q[nv*nv+1];
    int qi = 0;
    int dist[nv+1];
    bool visit[nv+1];
    for(int i=0; i<=nv; i++){
        dist[i] = inf;
        visit[i] = false;
    }
    // memset(dist, inf, sizeof(dist));
    // memset(visit, false, sizeof(visit));
    dist[src] = 0;
    q[qi].w = 0, q[qi].v = 0;
    qi++;
    
    while(qi > 0){
        int min_idx = 0;
        for(int i=1; i<qi; i++){
            if(q[i].w < q[min_idx].w){
                min_idx = i;
            }
        }
        int u = q[min_idx].v;
        int w = q[min_idx].w;
        // remove q[min_idx] & q[qi]
        q[min_idx].w = q[qi].w;
        q[min_idx].v = q[qi].v;
        qi--;
        if(visit[u] == true) continue;
        visit[u] = true;
        dist[u] = w;
        cout<<u<<" :: "<<w<<endl;
        
        // explore neighbour of u
        for(int v=0; v<nv; v++){
            if(T[u][v] == 0) continue;
            // if(visit[v] == true) continue;
            if(!visit[v] && dist[v] > T[u][v]){
            cout<<u<<" "<<v<<" "<<T[u][v]<<" "<<dist[v]<<" "<<qi<<endl;
                q[qi].w = T[u][v], q[qi].v = v;
                qi++;
            }
        }
    }
    cout<<endl;
    int total_w = 0;
    for(int i=1; i<=nv; i++){
        cout<<dist[i]<<" ";
        // total_w += dist[i];
    }
    cout<<endl;
    return total_w;
}

int main()
{
    int test;
    cin>>test;
    while(test--){
        int V;
        cin>>V;
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                cin>>T[i][j];
            }
        }
        cout<<get_prims_mst_weight(V, 0)<<endl;
    }
    return 0;
}


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