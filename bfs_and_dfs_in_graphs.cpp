
#include <bits/stdc++.h>
using namespace std;
#define vvec vector<vector<int> >
#define vec vector<int>

void print_adjacency_list1(vector<int> graph[], int vertices){
	cout<<"\n ---- adjacency list ----\n";
	for(int i=0; i<vertices; i++){
		cout<<i;
		for(int j=0; j<graph[i].size(); j++){
			cout<<"->"<<graph[i][j];
		}
		cout<<"\n";
	}
}

void print_adjacency_list2(set<int> graph[], int vertices){
	cout<<"\n ---- adjacency list ----\n";
	for(int i=0; i<vertices; i++){
		cout<<i;
		set<int>::iterator it;
		for(it=graph[i].begin(); it!=graph[i].end(); ++it){
			cout<<"->"<<*it;
		}
		// for(int j=0; j<graph[i].size(); j++){
		// 	cout<<"->"<<graph[i][j];
		// }
		cout<<"\n";
	}
	cout<<"---- adjacency list ----\n";
}

void BFS(int start_node, vector<int> adj[], bool vis[]){
	cout<<"\n ---- BFS Transversal ----\n";
	queue<int> q;
	q.push(start_node);
	vis[start_node] = true;
	while(!q.empty()){
		int top = q.front();
		cout<<top<<" ";
		q.pop();
		for(int i=0; i<adj[top].size(); i++){
			if(vis[adj[top][i]] == false){
				q.push(adj[top][i]);
				vis[adj[top][i]] = true;
			}
		}
	}
	cout<<"\n ---- BFS Transversal ----\n";
}

void DFS(int s, vector<int> g[], bool vis[]){
	stack<int> stack_;
	stack_.push_back(s);
	vis[s] = true;
	while(!stack_.empty()){
		int u = stack_.top();
		if(adj[u].size() >0){
			for(int i=0; i<adj[u].size(); i++){
				if(vis[adj[u][i]] == false){
					stack_.push_back(adj[u][i]);
					vis[adj[u][i]] = true;
					break;
				}
			}
		}
		else{
			stack_.pop();
		}
	}
}

void solve1(){
	int vertices, edges;
	cin>>vertices>>edges;

	vector<int> graph[vertices];
	int u, v;
	for(int i=0; i<edges; i++){
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	print_adjacency_list1(graph, vertices);
	
	bool visited[vertices] = {0};
	BFS(0, graph, visited);
}

void solve2(){
	int vertices, edges;
	cin>>vertices>>edges;

	set<int> graph[vertices];
	int u, v;
	for(int i=0; i<edges; i++){
		cin>>u>>v;
		graph[u].insert(v);
		graph[v].insert(u);
	}

	print_adjacency_list2(graph, vertices);
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		solve1();
		// solve2();
	}
	return 0;
}