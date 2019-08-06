
#define ipair pair<int,int>

void bfsUtil(set<ipair> &adj[], int u, int n){
	vector<int> vis(n,0);
	queue<ipair> q;
	q.push(make_pair(u, 0));
	int v, d;
	ipair front;
	int ans = 0;
	while(!q.empty()){
		front = q.front();
        q.pop();
		u = front.first;
		d = front.second;
		if(vis[u] == true) continue;
        vis[u] = true;
		for(auto vt : adj[u]){
			if(!vis[vt.first]){
				q.push(make_pair(vt.first, max(vt.second, d)));
			}
			if(adj[u].find())
		}
	}
	return ans;
}


vector<int> solve(vector<vector<int>> tree, vector<vector<int>> queries) {
	unordered_map<int,int> my_map;
	set<ipair> adj[n];
	for(auto e : tree){
		adj[e[0]].insert(make_pair(e[1],e[2]));
		adj[e[1]].insert(make_pair(e[0],e[2]));
	}



}



class disjointSet{
	int n;
	vector<int> parent, rank;
	disjointSet(int no){
		parent.resize(no);
		rank.resize(no);
		n = no;
		for(int i=0; i<no; i++) 
			parent[i] = i;
	}

	int find(int x){
		if(parent[x] != x){
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}

	void merge(int x, int y){
		int px = find(x);
		int py = find(y);
		if(px == py) return ;
		if(rank[px] < rank[py]){
			rank[px] = py;
		}
		else if(rank[px] > rank[py]){
			rank[py] = px;
		}
		else{
			rank[py] = px;
			rank[px]++;
		}
	}
	void getCount(unordered_map<int,int>&map){
		for(int i=1; i<=2*n; i++){
			map[parent[i]]++;
		}
	}
};

vector<int> componentsInGraph(vector<vector<int>> gb) {
	int n = gb.size();
	disjointSet mySet(2*n+1);
	for(auto e : gb){
		mySet.merge(e[0], e[1]);
	}
	int minc = MAX_INT, maxc = MIN_INT;
	unordered_map<int,int> map;
	mySet.getCount(map);
	for(auto itr : map){
		minc = min(minc, itr.second);
		maxc = max(maxc, itr.second);
	}
	vector<int> ans({minc, maxc});
	return ans;
}


