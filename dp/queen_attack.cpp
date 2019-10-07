void BFS(vector<string> A, int n, int m, int i, int j, vector<vector<int>> &dp){
    int left = j-1;
    while(left >=0){
        dp[i][left]++;
        if(A[i][left] == '1') break;
        left--;
    }
    int right = j+1;
    while(right < m){
        dp[i][right]++;
        if(A[i][right] == '1') break;
        right++;
    }
    int up = i-1;
    while(up >=0){
        dp[up][j]++;
        if(A[up][j] == '1') break;
        up--;
    }
    int down = i+1;
    while(down < n){
        dp[down][j]++;
        if(A[down][j] == '1') break;
        down++;
    }
    // right down diagnol
    int rx = i+1, ry = j+1;
    while(rx >=0 && rx < n && ry >= 0 && ry < m){
        dp[rx][ry]++;
        if(A[rx][ry] == '1') break;
        rx++; ry++;
    }
    // left up diag
    int lx = i-1, ly = j-1;
    while(lx >= 0 && lx < n && ly >= 0 && ly < m){
        dp[lx][ly]++;
        if(A[lx][ly] == '1') break;
        lx--; ly--;
    }
    // right up diag
    rx = i-1, ry = j+1;
    while(rx >=0 && rx < n && ry >= 0 && ry < m){
        dp[rx][ry]++;
        if(A[rx][ry] == '1') break;
        rx--; ry++;
    }
    // left down
    lx = i+1, ly = j-1;
    while(lx >= 0 && lx < n && ly >= 0 && ly < m){
        dp[lx][ly]++;
        if(A[lx][ly] == '1') break;
        lx++; ly--;
    }
    return; 
}

vector<vector<int> > Solution::queenAttack(vector<string> &A) {
    int n = A.size();
    if(n == 0) return {{}};
    int m = A[0].length();
    vector<vector<int>> dp(n, vector<int>(m,0));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(A[i][j] == '1'){
                BFS(A, n, m, i, j, dp);
            }
        }
    }
    return dp;
}
