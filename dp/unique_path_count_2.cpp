
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