class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(); if(n == 0) return 0;
        int m = text2.length(); if(m == 0) return 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                dp[i][j] = (text1[i-1] == text2[j-1]) 
                                        ? dp[i-1][j-1] + 1 
                                        : max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};



#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)

void solve(){
	int n1, n2;
	cin>>n1>>n2;
	cin.ignore(1);
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);

	int T[n1+1][n2+1];
	memset(T, 0, sizeof(T[0][0])*(n1+1)*(n2+1));
	for(int i=1; i<=n1; i++){
		for(int j=1; j<=n2; j++){
			if(s1[i-1] == s2[j-1]){
				T[i][j] = 1 + T[i-1][j-1];
			}
			else{
				T[i][j] = max(T[i-1][j], T[i][j-1]);
			}
		}
	}
	cout<<T[n1][n2]<<endl;
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