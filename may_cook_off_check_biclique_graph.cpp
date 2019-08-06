// https://www.codechef.com/COOK106B/problems/BICLIQUE


#include <bits/stdc++.h>
using namespace std;

bool check_biclique(int edge_store[][2], int vertices, int edges, int k){
	int u, v;
	int adj[vertices][vertices] = {0};

	// cout<<endl<<"============"<<endl;
	// for(int i=0; i<vertices; i++){
	// 	for(int j=0; j<vertices; j++){
	// 		cout<<adj[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	
	for(int i=0; i<edges; i++){
		u = edge_store[i][0];
		v = edge_store[i][1];
		if(adj[u-1][v-1] == 0 && adj[v-1][u-1] == 0){
			// cout<<u-1<<" "<<v-1<<" "<<adj[u-1][v-1]<<endl;
			adj[u-1][v-1] = 1;
			adj[v-1][u-1] = 1;
		}
		else{
			// cout<<u<<" "<<v<<" "<<adj[u-1][v-1]<<endl;
			return false;
		}
	}
	return true;
}
	

int main()
{
	int vertices, edges, k;
	cin>>vertices>>edges>>k;

	int u, v;
	int edge_store[edges][2] = {0};
	for(int i=0; i<edges; i++){
		cin>>edge_store[i][0]>>edge_store[i][1];
	}

	if(check_biclique(edge_store, vertices, edges, k)){
		cout<<"YES \n";
	}
	else{
		cout<<"NO \n";
	}

	return 0;
}