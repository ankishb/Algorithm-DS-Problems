int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    int n1 = A.size();
    int n2 = A[0].size();
    int dp[n1][n2];
    
    //fill bottom down corner cell
    if(A[n1-1][n2-1] > 0) dp[n1-1][n2-1] = A[n1-1][n2-1];
    else dp[n1-1][n2-1] = abs(A[n1-1][n2-1])+1;
    
    for(int i=n1-2; i>=0; i--){
        dp[i][n2-1] = max(dp[i+1][n2-1] - A[i][n2-1], 1);
    }
    for(int j=n2-2; j>=0; j--){
        dp[n1-1][j] = max(dp[n1-1][j+1] - A[n1-1][j], 1);
    }
    
    for(int i=n1-2; i>=0; i--){
        for(int j=n2-2; j>=0; j--){
            dp[i][j] = max(min(dp[i+1][j], dp[i][j+1]) - A[i][j], 1);
        }
    }
    
    for(int i=0; i<n1; i++){
        for(int j=0; j<n2; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[0][0];
}



int min3(int a, int b, int c){
    return min(a, min(b,c));
}
int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    int n = A.size();
    if(n==0) return 0;
    int m = A[0].size();
    
    vector< vector<int> > dp(n, vector<int>(m, 0));
    dp[n-1][m-1] = min(A[n-1][m-1],0);
    for(int i=(m-2); i>=0; i--){
        dp[n-1][i] = min3(0, A[n-1][i], A[n-1][i] + dp[n-1][i+1]);
    }
    for(int i=(n-2); i>=0; i--){
        dp[i][m-1] = min3(0, A[i][m-1], A[i][m-1] + dp[i+1][m-1]);
    }
    for(int i=(n-2); i>=0; i--){
        for(int j=(m-2); j>=0; j--){
            int bestNeighbor = max(dp[i][j+1], dp[i+1][j]);
            dp[i][j] = min3(0, A[i][j], A[i][j] + bestNeighbor);
        }
    }
    
    return ((int) abs(dp[0][0])+1);   
}



// Approach:
// We check that, if we have enough power in the current cell to reach the next cell. The way to check is we count the power need to reach next cell as "current_cell_power - next_cell_power", if it is greater than 0, then we need no power, otherwise, we need that much amount of power to proceed.
// Note that, we proceed in bottom-up manner, so we check for "next_cell_power - current_cell_power", so condition change with negative sign.

int calculateMinimumHP(vector<vector<int> > &dungeon) {
    int M = dungeon.size();
    int N = dungeon[0].size();
    // hp[i][j] represents the min hp needed at position (i, j)
    // Add dummy row and column at bottom and right side
    vector<vector<int> > hp(M + 1, vector<int>(N + 1, INT_MAX));
    hp[M][N - 1] = 1;
    hp[M - 1][N] = 1;
    for (int i = M - 1; i >= 0; i--) {
        for (int j = N - 1; j >= 0; j--) {
            int need = min(hp[i + 1][j], hp[i][j + 1]) - dungeon[i][j];
            hp[i][j] = need <= 0 ? 1 : need;
        }
    }
    return hp[0][0]; 
}