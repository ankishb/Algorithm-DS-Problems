
#define ipair pair<int,int>
class Solution {
public:
	int bfsUtil(vector<int> adj[], int u, int n){
		vector<int> vis(n,0);
		queue<ipair> q;
		q.push(make_pair(u, 0));
		int v, d;
		pair<int, int> front;
		int ans = 0;
		while(!q.empty()){
			front = q.front();
			u = front.first;
			d = front.second;
			if(vis[u] == true) continue;
			ans += d;
			for(auto vt : adj[u]){
				if(!vis[vt]){
					q.push(make_pair(vt, d+1));
				}
			}
		}
		return ans;
	}

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
    	vector<int> adj[N], ans(N);
    	int u, v, d;
    	for(auto e : edges){
    		u = e[0], v = e[1];
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	for(int i=0; i<N; i++){
    		d = bfsUtil(adj, i, N);
    		ans[i] = d;
    	}
    	return ans;
    }
};