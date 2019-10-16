
// new try
/*
1. At each move, we collect energy on current step
2. we walk forward and check if someother element 
	can improve(fill more) energy, that can take us 
	more futher, if yes, we collect it 
*/
int get_minimum_count(vector<int> A){
    if(A[0] == 0) return -1;
    int i = 0, count = 1, j, n = A.size();
    while(i < n){
        j = i+1;
        if(i+A[i] >= n-1) return count;
        for(int k=i+1; k<=i+A[i]; k++){
            if(k+A[k] >= j+A[j]) j = k;
        }
        // cout<<i<<" "<<j<<" "<<count<<endl;
        count++;
        i = j;
        if(i < n && A[i] == 0) return -1;
    }
    return count;
}




// old one
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