
/*(subsequence shouldn't have to be distinct)
Idea here is to maintain matrix to count subsequence as including char at [i-j]
1. if s[i] == s[j], then include count of [i+1 - j] & [i - (j-1)] & 1(which comes by combining both)
2. if not equal, then we include [i+1 - j] & [i - (j-1)] and substract [(i+1) - (j-1)]

For exp: "aba" 
	1 2 []
	0 1 2
	0 0 1

	At [0][1], we have "a", "b"
	At [1][2], we have "b", "a"

	So [0][2], we have "a", "b", "b", "a", "aba"

*/


#define mod 1000000007
int Solution::solve(string s){
    int n = s.length();
    if(n <= 1) return n;
    vector<vector<int>>dp(n, vector<int>(n,0));
    for(int k=0; k<n; k++){
        for(int i=0; i<n-k; i++){
            int j = i+k;
            if(i == j) dp[i][j] = 1;
            else if(s[i] == s[j]){
                dp[i][j] = 1 + dp[i+1][j] + dp[i][j-1];
            }
            else{
                dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
            }
            dp[i][j] = dp[i][j]%mod;
        }
    }
    return dp[0][n-1];
}
