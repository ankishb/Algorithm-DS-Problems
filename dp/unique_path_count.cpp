
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
