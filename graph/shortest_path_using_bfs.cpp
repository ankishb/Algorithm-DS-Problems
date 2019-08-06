
// Complete the bfs function below.
vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
	vector<bool> vis(n+1, false);
	vector<int> cost(n+1, INT_MAX);
	vector<int> adj[n+1];
    int u, v, w;
    for(auto e : edges){
        u = e[0], v = e[1], w = e[2];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
   	queue<pair<int, int>> q;
	q.push(make_pair(s, 0));
	vis[s] = true;
	while(!q.empty()){
		u = q.front().first;
		if(vis[u]) continue;
		w = q.front().second;
		cost[u] = w;
		for(int i=0; i<adj[u].size(); i++){
			v = adj[u][i];
			if(!vis[v]){
				q.push(make_pair(v, w+1));
			}
		}
	}
	vector<int> ans;
    for(int i=1; i<n+1; i++){
        if(i == s) continue;
        if(cost[i] == INT_MAX){
            ans.push_back(-1);
        }
        else{
            ans.push_back(cost[i]*6);
        }
    }
    return ans;
}








#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

vector<int>dist;
void bfs(int s,vector<vector<int>>a,vector<bool>visited)
{
    visited[s]=true;
    queue<int>q;
    q.push(s);
    dist[s]=0;
    while(!q.empty())
    {
        s=q.front();
        //cout<<s<<" ";
        q.pop();        
        for(int i:a[s])
        {
            if(!visited[i]&&dist[i]==-1)
            {
                dist[i]=dist[s]+1;
                visited[i]=true;
                q.push(i);   
            }
        }
    }
}

int main() {
  int q;
  cin>>q;
  for(int t=0;t<q;t++)
  {
      int n,m;
      cin>>n>>m;
      vector<vector<int>>a(n);
      for(int i=0;i<m;i++)
      {
          int x,y;
          cin>>x>>y;
          a[x-1]b.push_back(y-1);
          a[y-1].push_back(x-1);
      }
      int s;
      cin>>s;
      vector<bool>visited(n+1,false);
      dist.resize(n,-1);
      bfs(s-1,a,visited);
      
      for(int i=0;i<dist.size();i++)
          if(dist[i]==-1)
              cout<<dist[i]<<" ";
          else if(dist[i]!=0)
              cout<<dist[i]*6<<" ";
      cout<<endl;
      dist.clear();
      
  }
    return 0;
}