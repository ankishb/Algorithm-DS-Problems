
#include <bits/stdc++.h>
using namespace std;

void fill_color(vector<int> adj[], int u, vector<int> &colors, vector<bool> &vis, vector<set<int>> &color_done){
    for(auto v : adj[u]){
        if(vis[v]) continue;
        int c = 0;
        while(color_done[v].find(c) != color_done[v].end()) c++;
        colors[v] = c;
        for(auto u_ : adj[v]){
            color_done[u_].insert(c);
        }
        vis[v] = true;
        fill_color(adj, v, colors, vis, color_done);
    }
}

int main()
{
    int V; cin>>V;
    int E; cin>>E;
    vector<int> adj[V];
    int u, v;
    for(int i=0; i<E; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> colors(V,INT_MAX);
    vector<set<int>> color_done;
    color_done.resize(V);
    vector<bool> vis(V, 0);
    vis[0] = true;
    colors[0] = 0;
    for(auto v : adj[0]){
        color_done[v].insert(0);
    }
    fill_color(adj, 0, colors, vis, color_done);
    for(auto c : colors) cout<<c<<" ";
    return 0;
}


/*
10 14
0 1
1 2
2 3
3 4
4 9
9 6
1 6
0 5
5 7
5 8
7 2
8 3
7 9
6 8
*/