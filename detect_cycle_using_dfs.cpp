/*
the reason why this algorithm doesn't work for directed graphs is that in a directed graph 2 different paths to the same vertex don't make a cycle. For example: A-->B, B-->C, A-->C - don't make a cycle whereas in undirected ones: A--B, B--C, C--A does.

Find a cycle in undirected graphs

An undirected graph has a cycle if and only if a depth-first search (DFS) finds an edge that points to an already-visited vertex (a back edge).

Find a cycle in directed graphs

In addition to visited vertices we need to keep track of vertices currently in recursion stack of function for DFS traversal. If we reach a vertex that is already in the recursion stack, then there is a cycle in the tree
*/
#include <bits/stdc++.h>
using namespace std;

class Graph{
	int n_vertices;
	vector<int> *adj;
	bool is_cyclic_util(int n_vertices, bool visited[], int parent);
public:
	Graph(int V){
		this->n_vertices = V;
		adj = new vector<int>[V];
	}
	void add_edge(int u, int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	void DFS_util2(bool visited[], int u){
		bool visited[n_vertices];
		memeset(visited, 0, sizeof(visited));
		visited[u] = true;
		cout<<u<<" ";
		stack<int> s;
		s.push(u);
		int top, v;
		bool found;
		while(!s.empty()){
			top = s.top();
			v = adj[top];
			found = false;
			// pick the neighbour of start
			for(int i=0; i<v.size(); i++){
				if(!visited[v[i]]){
					visited[v[i]] = true;
					s.push(v[i]);
					cout<<v[i]<<" ";
					found = true;
					break;
				}
			}
			if(!found){
				s.pop();
			}
		}
	}
	void DFS_util(bool visited[], int u){
		visited[start] = true;
		cout<<start<<" ";
		int v;
		for(int i=0; i<adj[u].size(); i++){
			v = adj[u][i];
			if(!visited[v]){
				DFS_util(visited, v);
			}
		}
	}

	void DFS(int start){
		bool visited[n_vertices];
		memset(visited, 0, sizeof(visited));
		DFS_util(visited, start)
	}
};

int main()
{
	Graph g1(5);
	g1.add_edge(1, 0);
	g1.add_edge(0, 2);
	g1.add_edge(2, 0);
	g1.add_edge(0, 3);
	g1.add_edge(3, 4);
	

	return 0;
}