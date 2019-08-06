/*
After the iteration, for each vertex , we have the shortest path consisting of a maximum of edges from to .
Since, the shortest path to any vertex can consist of atmost edges, we perform another iteration to check if there exists a negative weight cycle in the graph.
The running time of this algorithm is O(K*V)
*/

vector<int> bellmanFord(int source, vector<vector<pair<int, int> > > G)  {
  int INF = (int) 1e9;
  int n = G.size();
  vector<int> D(n, INF);
  for(int i=0; i<n-1; i++)  {
    for(int u=0; u<n; u++)  {
      for(auto edge: G[u])  {
        int v = edge.first, w = edge.second;
        D[v] = min(D[v], D[u] + w);
      }
    }
  } 
  for(int u=0; u<n; u++)  {
    for(auto edge: G[u])  {
      int v = edge.first, w = edge.second;
      if(D[v] < D[u] + w) {
        //Negative Cycle exists!!
        assert(0);
      }
    }
  }
  return D;
}