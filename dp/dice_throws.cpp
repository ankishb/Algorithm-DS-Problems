
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vii vector<vector<int>>
#define f first
#define s second
#define ll long long int 

/*
For ech dice, we can use [1-6] faces each as different 
case to obtain sum. For example count(6,2,9) with 2 dice, 
to get a sum of 9, we use count(6,1,8) + count(6,1,7),---- 
*/
ll dp[55][55];
ll count_ways(int m, int n, int x){
    // cout<<m<<" "<<n<<" "<<x<<endl;
    if(x == 0 && n == 0){
        dp[n][x] = 1;
        return 1;
    }
    if(x < 0 || n == 0) return 0;
    if(dp[n][x] != -1) return dp[n][x];
    
    ll value = 0;
    for(int i=1; i<=m; i++){
        value += count_ways(m, n-1, x-i);
    }
    dp[n][x] = value;
    return value;
}


int main()
 {
	int test;
	cin>>test;
	while(test--){
	    // input and call signature function
	    int m, n, x;
	    cin>>m>>n>>x;
	    for(int i=0; i<=n; i++){
	        for(int j=0; j<=x; j++){
	            dp[i][j] = -1;
	        }
	    }
	    cout<<count_ways(m, n, x)<<endl;
	}
	return 0;
}