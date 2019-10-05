int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    int n = A.size();
    if(n == 0) return 0;
    int m = A[0].size();
    if(A[0][0] == 1) return 0;
    vector<vector<int>> dp(n, vector<int>(m,0));
    for(int i=0; i<n; i++){
        if(A[i][0] == 1) break;
        dp[i][0] = 1;
    }
    for(int j=0; j<m; j++){
        if(A[0][j] == 1) break;
        dp[0][j] = 1;
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(A[i][j] == 1) dp[i][j] = 0;
            else dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[n-1][m-1];

}



int Solution::uniquePaths(int n, int m){
    if(n == 0 || m == 0) return 0;
    vector<vector<int>> dp(n, vector<int>(m,0));
    for(int i=0; i<n; i++){
        dp[i][0] = 1;
    }
    for(int j=0; j<m; j++){
        dp[0][j] = 1;
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[n-1][m-1];
}


int uniquePaths(int m, int n) {
    // m+n-2 C n-1 = (m+n-2)! / (n-1)! (m-1)! 
    long long ans = 1;
    for (int i = n; i < (m + n - 1); i++) {
        ans *= i;
        ans /= (i - n + 1);
    }
    return (int)ans;
}








void fillMatrix(vector<vector<int>> &dp, int i, int j){
    if(i < 0 || j < 0) return;
    if(i-1 >= 0) dp[i-1][j] = 1 + dp[i][j];
    if(j-1 >= 0) dp[i][j-1] = 1 + dp[i][j];

    fillMatrix(dp, i-1, j);
    fillMatrix(dp, i, j-1);
}

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(n == 0 || m == 0) return 0;
        vector<vector<int>> dp1(m, vector<int>(n,0));
        vector<vector<int>> dp2(m, vector<int>(n,0));
        
        // fillMatrix(dp1, m-1, n-1);
        
        for(int i=m-1; i>=0; i--) dp2[i][0] = 1;
        for(int i=n-1; i>=0; i--) dp2[0][i] = 1;
        
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                // dp2[i][j] = (dp1[i-1][j] == dp1[i][j-1]) 
                //           ? (dp2[i-1][j] + dp2[i][j-1]) 
                //           : max(dp2[i-1][j], dp2[i][j-1]);
                dp2[i][j] = dp2[i-1][j] + dp2[i][j-1];
            }
        }
        return dp2[m-1][n-1];
    }
};
