

#include <bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f 

void addEdge(vector<pair<int, int> > vect[], int u, int v, int weight){
    vect[u].push_back(make_pair(v, weight));
    vect[v].push_back(make_pair(u, weight));
}

void get_minimum_spanning_tree(vector<pair<int, int> > adj[], int vertices, int source){
    // make priority queue (distance, vertices)
    // priority_queue<int, vector<int>, compare > pq;
    //     1. first int       ==> datatype of heap 
    //     2. 2nd vector      ==> storage vector, which is vector of pair in this case
    //     3. 3rd compare     ==> comapring function to perform on the priority_queue

    // make min-heap:
        // Need vector-pairs to create an key and value to track value.

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    //create a distance vector qand fill with INF
    vector<int> dist(vertices, INF);
    // track the parent of vertices
    vector<int> parent(vertices, -1);

    vector<bool> inMST(vertices, false); 

    // make a pair of distance and corresponding vertices
    pq.push(make_pair(0, source));
    dist[source] = 0;
    inMST[source] = true;


    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;

        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i].first;
            int w = adj[u][i].second;

            if (inMST[v] == false && dist[v] > w) 
            { 
                // Updating key of v 
                dist[v] = w; 
                pq.push(make_pair(dist[v], v)); 
                parent[v] = u; 
            } 
        }
    }
    // cout<endl<<"============="<<endl;
    int i=1;
    vector<int>::iterator itr;
    for(itr=parent.begin()+1; itr!= parent.end(); ++itr){
        cout<<*itr<<" "<<i<<endl;
        i++;
    }
}

int main()
{
    int V = 9; 
    vector<pair<int, int> > adj[V]; 
  
    addEdge(adj, 0, 1, 4); 
    addEdge(adj, 0, 7, 8); 
    addEdge(adj, 1, 2, 8); 
    addEdge(adj, 1, 7, 11); 
    addEdge(adj, 2, 3, 7); 
    addEdge(adj, 2, 8, 2); 
    addEdge(adj, 2, 5, 4); 
    addEdge(adj, 3, 4, 9); 
    addEdge(adj, 3, 5, 14); 
    addEdge(adj, 4, 5, 10); 
    addEdge(adj, 5, 6, 2); 
    addEdge(adj, 6, 7, 1); 
    addEdge(adj, 6, 8, 6); 
    addEdge(adj, 7, 8, 7); 
  
    // for(int i=0; i<V; i++){
    //     for(int j=0; j<adj[i].size(); j++){
    //         cout<<adj[i][j].first<<" "<<adj[i][j].second<<endl;
    //     }
    //     cout<<"==============="<<endl;
    // }
    get_minimum_spanning_tree(adj, V, 0); 
  
    return 0; 
} 

