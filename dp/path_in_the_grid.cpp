
/*
As we can go from (i,j) to 1. (i+1,j), (i+1,j+1), (i+1,j-1),
we will check for three position in the top row(backword) to update current cell.

Note: backword approach will give us optimal solution(this is dp)
*/
#include <bits/stdc++.h>
using namespace std;

int solve(){
    int n;
    cin>>n;
    vector<vector<int>> B, A(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>A[i][j];
        }
        B.push_back(A[i]);
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<n; j++){
            int min_el = B[i-1][j];
            if(j-1 >= 0) min_el = max(min_el, B[i-1][j-1]);
            if(j+1 < n) min_el = max(min_el, B[i-1][j+1]);
        
            B[i][j] += min_el;
        }
    }
    int max_el = B[n-1][0];
    for(int j=0; j<n; j++){
        max_el = max(max_el, B[n-1][j]);
    }
    cout<<max_el<<endl;
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