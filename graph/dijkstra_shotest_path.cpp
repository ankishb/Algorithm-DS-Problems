

// C++ program to find the shortest path 
// with minimum edges in a graph 
#include <iostream> 
using namespace std; 
#define INFINITY 9999 
#define n 5 
#define s 0 
#define d 3 
#define NILL -1 
int MinDistance(int*, int*); 
void PrintPath(int*, int); 
  
// Function to find the shortest path 
// with minimum edges in a graph 
void Dijkstra(int Graph[n][n], int _n, int _s, int _d) 
{ 
  
    int i, u, v, count; 
    int dist[n]; 
    int Blackened[n] = { 0 }; 
    int pathlength[n] = { 0 }; 
    int parent[n]; 
  
    // The parent Of the source vertex is always equal to nill 
    parent[_s] = NILL; 
  
    // first, we initialize all distances to infinity. 
    for (i = 0; i < n; i++) 
        dist[i] = INFINITY; 
  
    dist[_s] = 0; 
    for (count = 0; count < n - 1; count++) { 
        u = MinDistance(dist, Blackened); 
  
        // if MinDistance() returns INFINITY, then the graph is not 
        // connected and we have traversed all of the vertices in the 
        // connected component of the source vertex, so it can reduce 
        // the time complexity sometimes 
        // In a directed graph, it means that the source vertex 
        // is not a root 
        if (u == INFINITY) 
            break; 
        else { 
  
            // Mark the vertex as Blackened 
            Blackened[u] = 1; 
            for (v = 0; v < n; v++) { 
                if (!Blackened[v] && Graph[u][v] 
                    && dist[u] + Graph[u][v] < dist[v]) { 
                    parent[v] = u; 
                    pathlength[v] = pathlength[parent[v]] + 1; 
                    dist[v] = dist[u] + Graph[u][v]; 
                } 
                else if (!Blackened[v] && Graph[u][v] 
                         && dist[u] + Graph[u][v] == dist[v] 
                         && pathlength[u] + 1 < pathlength[v]) { 
                    parent[v] = u; 
                    pathlength[v] = pathlength[u] + 1; 
                } 
            } 
        } 
    } 
  
    // Printing the path 
    if (dist[_d] != INFINITY) 
        PrintPath(parent, _d); 
    else
        cout << "There is no path between vertex "
             << _s << "to vertex " << _d; 
} 
  
int MinDistance(int* dist, int* Blackened) 
{ 
    int min = INFINITY, min_index, v; 
    for (v = 0; v < n; v++) 
        if (!Blackened[v] && dist[v] < min) { 
            min = dist[v]; 
            min_index = v; 
        } 
    return min == INFINITY ? INFINITY : min_index; 
} 
  
// Function to print the path 
void PrintPath(int* parent, int _d) 
{ 
    if (parent[_d] == NILL) { 
        cout << _d; 
        return; 
    } 
    PrintPath(parent, parent[_d]); 
    cout << "->" << _d; 
} 
  
// Driver code 
int main() 
{ 
    // INFINITY means that u and v are not neighbors. 
    int Graph[n][n] = { { 0, 1, INFINITY, INFINITY, 10 }, 
                        { 1, 0, 4, INFINITY, INFINITY }, 
                        { INFINITY, 4, 0, 7, INFINITY }, 
                        { INFINITY, INFINITY, 7, 0, 2 }, 
                        { 10, INFINITY, INFINITY, 2, 0 } }; 
    Dijkstra(Graph, n, s, d); 
    return 0; 
} 




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