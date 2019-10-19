
// newest(but have some bug)
class disjoint_set{
public:
    vector<int> parent;
    disjoint_set(int n){
        for(int i=0; i<n; i++){
            parent.push_back(i);
        }
    }
    int find(int x){
        if(x != parent[x]){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    bool merge(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px == py) return false;
        parent[px] = py;
        return true;
    }
};
bool isCyclic(int V, vector<int> adj[]){
    disjoint_set set(V);
    for(int u=0; u<V; u++){
        for(auto v : adj[u]){
            if(!set.merge(u, v)) return true;
        }
    }
    // for(int i=0; i<V; i++){
    //     cout<<i<<" --> "<<set.parent[i]<<endl;
    // }
    return false;
}






// oldest
// https://www.geeksforgeeks.org/union-find/

#include <bits/stdc++.h>
using namespace std;

class Edge{
public:
	int src, dest;
};

class Graph{
public:
	int V, E;
	Edge* edge;
};

Graph* createGraph(int V, int E){
	Graph* graph = new Graph();
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[graph->E * sizeof(Edge)];
	return graph;
}

// int find(int parent[], int i){
// 	if(parent[i] == -1){
// 		return i;
// 	}
// 	return find(parent, parent[i]);
// }

// void Union(int parent[], int x, int y){
// 	int x_set = find(parent, x);
// 	int y_set = find(parent, y);
// 	if(x_set != y_set){
// 		parent[x_set] = y_set;
// 	}
// }

class naiveFindUnion{
public:
	int *parent;
	naiveFindUnion(Graph* graph){
		parent = new int[graph->V * sizeof(int)];
		memset(parent, -1, sizeof(int)*graph->V);
	}

	int find(int i){
		if(parent[i] == -1){
			return i;
		}
		return find(parent[i]);
	}

	void Union(int x, int y){
		int x_set = find(x);
		int y_set = find(y);
		if(x_set != y_set){
			parent[x_set] = y_set;
		}
	}
};

// union by rank and path compression
// There are 3 cases:
// rank[x] > rank[y], parent[y] = x;
// rank[x] < rank[y], parent[x] = y;
// rank[x] == rank[y], pick anyone, and rank++
class findUnion{
public:
	int *parent;
	int *rank;
	findUnion(Graph* graph){
		parent = new int[graph->V * sizeof(int)];
		rank = new int[graph->V * sizeof(int)];
		for(int i=0; i<graph->V; i++){
			parent[i] = i;
			rank[i] = 0;
		}
	}

	int find(int i){
		if(parent[i] == !i){
			parent[i] = find(parent[i]);
		}
		return parent[i];
	}

	void Union(int x, int y){
		int x_parent = find(x);
		int y_parent = find(y);

		if(rank[x_parent] < rank[y_parent]){
			parent[x_parent] = y_parent;
		}
		else if(rank[x_parent] > rank[y_parent]){
			parent[y_parent] = x_parent;
		}
		else{
			parent[y_parent] = x_parent;
			rank[x_parent]++;
		}
	}
};

// 1. First init a parent array, filled with -1
// 2. Now tranverse through all edges.
// 3. If there parent is same, then we found a cycle, else we we join them using union operation.
int isCycle(Graph* graph){
	findUnion obj_(graph);

	for(int i=0; i<graph->E; i++){
		int x_parent = obj_.find(graph->edge[i].src);
		int y_parent = obj_.find(graph->edge[i].dest);

		if(x_parent == y_parent) return 1;
		obj_.Union(x_parent, y_parent);
	}
	return 0;
}

int main()
{
	int n_vertices=3, n_edges=3;
	Graph* graph =createGraph(n_vertices, n_edges);

	// (0-1)
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	
	// (1-2)
	graph->edge[1].src = 1;
	graph->edge[1].dest = 2;
	
	// (0-2)
	graph->edge[2].src = 0;
	graph->edge[2].dest = 2;

	for(int i=0; i<graph->E; i++){
		cout<<graph->edge[i].src<<" "<<graph->edge[i].dest<<endl;
	}

	// cout<<"naive implementation: ";
	// cout<<isCycle(graph)<<endl;
	
	cout<<"optimal implementation(Rank/Path compression): ";
	cout<<isCycle(graph)<<endl;
	
	return 0;	
}