// new try
#define ll long long
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& A) {
        int m = A.size();
        if(m == 0) return 0;
        int n = A[0].size();
        vector<vector<ll>> dp(m,vector<ll>(n,0));
        
        for(int i=0; i<m; i++){
            if(A[i][0] == 1) break;
            dp[i][0] = 1;
        }
        for(int j=0; j<n; j++){
            if(A[0][j] == 1) break;
            dp[0][j] = 1;
        }
        
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(A[i][j] == 1) continue;
                if(A[i-1][j] != 1) dp[i][j] += dp[i-1][j];
                if(A[i][j-1] != 1) dp[i][j] += dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

// old try
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row=obstacleGrid.size();
        if(!row)return 0;
        int col=obstacleGrid[0].size();
        vector<vector<long long>> dp(row,vector<long long>(col,0));
        for(int i=0;i<row;++i){
            if(obstacleGrid[i][0]==0) dp[i][0]=1;
            else break;
        }
        for(int i=0;i<col;++i){
            if(obstacleGrid[0][i]==0) dp[0][i]=1;
            else break;
        }
        for(int i=1;i<row;++i){
            for(int j=1;j<col;++j){
                if(obstacleGrid[i][j]==0)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[row-1][col-1];
    }
};