/*
1. if s[i] == s[j] : 2 + dp[i+1][j-1] (check if we exclude these two chacter, what would be longest subsequence)
2. Else max(dp[i-1][j], dp[i][j-1])
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length(); if(n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        int j;
        for(int k=0; k<n; k++){
            for(int i=0; i<n-k; i++){
                j = i+k;
                if(i == j){ dp[i][j] = 1; continue; }
                dp[i][j] = (s[i] == s[j]) ? dp[i+1][j-1] + 2 : max(dp[i+1][j], dp[i][j-1]);
            }
        }
        // for(auto v : dp){ for(auto el : v) cout<<el<<" "; cout<<endl; }
        return dp[0][n-1];
    }
};