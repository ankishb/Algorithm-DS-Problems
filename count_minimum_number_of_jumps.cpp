#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)

void solve(){
	int n;
	cin>>n;
	vector<int> A(n,0);
	loop(i, 0, n){
		cin>>A[i];
	}

	vector<int> path_cost(n, 0);
	// cout<<"\n check path cost init: \n";
	// for(auto itr : path_cost){
	// 	cout<<itr<<" ";
	// }
	cout<<endl;

	vector<int> path(n, 0);
	for(int i=1; i<A.size(); i++){
		for(int j=0; j<i; j++){
			if(j+A[j]-i >=0){
				if(path_cost[i] == 0){
					path_cost[i] = path_cost[j]+1;
					path[i] = j;
				}
				else if(path_cost[i] >= path_cost[j]+1){
					path[i] = j;
					path_cost[i] = path_cost[j]+1;
				}
			}
		}
	}

	cout<<"Path Cost: \n";
	for(auto itr : path_cost){
		cout<<itr<<" ";
	}
	cout<<endl;
	cout<<"Path: \n";
	for(auto itr : path){
		cout<<itr<<" ";
	}
	cout<<endl;
}


int main()
 {
	int test;
	cin>>test;
	while(test--){
	    solve();
	}
	return 0;
}