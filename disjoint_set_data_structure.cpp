
#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
	int *rank;
	int parent;
	int n;

public:
	DisjointSet(int n){
		rank = new int[n];
		parent = new int[n];
		this->n = n;
		makeset();
	}

	void makeset(){
		for(int i=0; i<n; i++){
			parent[i] = i;
		}
	}

	void find(int x){
		if(parent[x] != x){
			parent[x] = find(parent[x])
		}
		return parent[x];
	}

	void union(int x, int y){
		int x_set = find(x);
		int y_set = find(y);
		// if both element belong to same set
		if(x_set == y_set){
			return ;
		}
		// find rank of them, take union according
		// 1. Choose parent to that set, which have higher rank
		// 2. If rank equal, run path compression algo
		if(rank[x_set] < rank[y_set]){
			parent[x_set] = y_set;
		}
		else if(rank[x_set] > rank[y_set]){
			parent[y_set] = x_set;
		}
		else{
			parent[y_set] = x_set;
			rank[x_set] = rank[x_set]+1;
		}
	}
}

int main()
{
	DisjointSet set(5);
	set.union(0, 2);
	set.union(4, 2);
	set.union(3, 1);

}



class DisjointSet{
	vector<int> rank;
	vector<int> parent;
	int n;

public:
	DisjointSet(int n_){
		vector<int> temp(n_, 0);
		rank = temp;
		parent = temp;
		n = n_;
		makeset();
	}

	void makeset(){
		for(int i=0; i<n; i++){
			parent[i] = i;
		}
	}

	void print_parent(){
        for(auto itr : parent) cout<<itr<<" ";
		cout<<endl;
	}

	void find(int x){
		if(parent[x] != x){
			parent[x] = find(parent[x])
		}
		return parent[x];
	}

	void union_(int x, int y){
		int x_set = find(x);
		int y_set = find(y);
		// if both element belong to same set
		if(x_set == y_set){
			return ;
		}
		// find rank of them, take union according
		// 1. Choose parent to that set, which have higher rank
		// 2. If rank equal, run path compression algo
		if(rank[x_set] < rank[y_set]){
			parent[x_set] = y_set;
		}
		else if(rank[x_set] > rank[y_set]){
			parent[y_set] = x_set;
		}
		else{
			parent[y_set] = x_set;
			rank[x_set] = rank[x_set]+1;
		}
	}
};

