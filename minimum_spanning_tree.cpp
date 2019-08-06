#define iPair pair<int, int>
class Solution {
public:
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> dist;
    vector<int> parent;
    vector<bool> vis;
    int u, v, w, stopsCount;
    
    void minSpanningTree(vector<iPair> adj[], int src, int dst){
        dist[src] = 0;
        pq.push(make_pair(0, src));
        while(!pq.empty()){
            iPair temp = pq.top();
            pq.pop();
            u = temp.second;
            if(vis[u] == true) continue;
            vis[u] = true;
            
            for(int i=0; i<adj[u].size(); i++){
                v = adj[u][i].first, w = adj[u][i].second;
                if(vis[v] == false && dist[v] > w){
                    dist[v] = w;
                    parent[v] = u;
                    pq.push(make_pair(w, v));
                }
            }
        }
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<iPair> adj[n];
        dist.resize(n, INT_MAX);
        vis.resize(n, false);
        parent.resize(n, -1);
        
        
        for(auto flight : flights){
            u=flight[0], v=flight[1], w=flight[2];
            adj[u].push_back(make_pair(v,w));
        }
        
        minSpanningTree(adj, src, dst);
        cout<<"dist array: ";
        for(auto d : dist) cout<< d <<" ";
        cout<<"\nparent array: ";
        for(auto p : parent) cout<< p <<" ";
        cout<<endl;
        
        v = dst;
        u = parent[v];
        w = 0;
        stopsCount = 0;
        while(u != src){
            stopsCount++;
            w += dist[v];
            u = parent[u];
        }
        if(stopsCount <= k) return w;
        
        return 1;
        
    }
};




// Given a weighted, undirected and connected graph. The task is to find the sum of weights of  the edges of the Minimum Spanning Tree.

#include<bits/stdc++.h>
using namespace std;

int spanningTree(int V, int e, vector<pair<int, int> > adj[]);

int main()
{
	int t ;
	cin>>t;
	while(t--)
	{
    	int n,e;
        cin >> n>> e;
        int x, y, w;
        
        vector<pair<int, int> > adj[n];
        for(int i = 0;i < e;++i){
        	cin >> x >> y >> w;
        	adj[x].push_back(make_pair(y, w));
        	adj[y].push_back(make_pair(x, w));
        }
            cout << spanningTree(n, e, adj) << endl;
	}
	
    return 0;
}

int spanningTree(int V, int e, vector<pair<int, int> > adj[]){

    // cout<<endl<<"---- adj matrix ----"<<endl;
    // // vector<pair<int, int> >::iterator it;
    // // for(it=adj.begin(); it!=adj.end(); ++it){
    // //     cout<<(*it).first<<" "<<(*it).second<<endl;
    // // }
    // for(int i=1; i<=V; i++){
    //     for(auto it : adj[i]){
    //         cout<<i<<" "<<it.first<<" "<<it.second<<endl;
    //     }
    // }
    // cout<<endl<<"---- adj matrix ----"<<endl;

    // for(int i=0; i<adj.size(); i++){
    //     cout<<"------------------- \n";
    //     for(int j=0; j<adj[i].size(); j++){
    //         cout<<i<<" "<<adj[i][j].first<<" "<<adj[i][j].second<<endl;
    //     }
    // }

    int source = 1;
    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, source));
    visited[0] = true;

    int u, v, w, ans=0;
    while(!pq.empty()){
        u = pq.top().second;
        ans += pq.top().first;
        visited[u] = true;
        pq.pop();

        for(int i=0; i<adj[u].size(); i++){
            v = adj[u][i].first;
            w = adj[u][i].second;

            if(visited[v] == false && w<dist[u]){
                pq.push(make_pair(w, v));
                dist[u] = w;
            }
        }
    }
    return ans;
}