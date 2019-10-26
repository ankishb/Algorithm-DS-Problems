
/*
To get maximum sum, we can't include its neighbours.
1. First, we get maximum of column's element
2. Now, we know that we can add all but adjacent element
	To do that we use [i-2]th element, which we store as
	maximum of all the previous

For exp: 2, 1, 3, 4 --> 2, 2, 2+3, 2+4 = 6 is our ans
*/
int Solution::adjacent(vector<vector<int> > &A) {
    int n = A[0].size(), ans = 0;
    vector<int> dp(n, 0);
    for(int i=0; i<n; i++){
        dp[i] = max(A[0][i], A[1][i]);
        if(i >= 2) dp[i] += dp[i-2];
        if(i >= 1) dp[i] = max(dp[i], dp[i-1]);
        ans = max(ans, dp[i]);
    }
    return ans;
}
