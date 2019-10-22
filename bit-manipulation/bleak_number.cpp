
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vii vector<vector<int>>
#define f first
#define s second
int dp[10005];
unordered_set<int> uni;

void build_count_bits(){    
    dp[0] = 0;
    dp[1] = 1;
    int j;
    while(true){
        int size = 2;
        for(j=0; j<size && (size+j < 105); j++){
            dp[size+j] = 1 + dp[j];
        }
        if(size+j >= 105) break;
        size *= 2;
    }
    for(int i=0; i<105; i++){
        uni.insert(i+dp[i]);
    }
    for(auto a : uni){
        cout<<a<<" ";
    }
}

// creat a signature function here
int is_bleak(int n){
    return (uni.find(n) != uni.end());
}


int main()
 {
	int test;
	cin>>test;
	// build dp array
	build_count_bits();
	while(test--){
	    // input and call signature function
	    int n;
	    cin>>n;
	    cout<<is_bleak(n)<<endl;
	}
	return 0;
}