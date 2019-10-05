// new one
int flippingMatrix(vector<vector<int>> M) {
    int ans = 0, n = M.size();
    for(int i=0; i<n/2; i++){
        for(int j=0; j<n/2; j++){
            // top-left, top-right, bottom-left, bottom-right
            //   [i,j]   [i,n-j-1]   [n-i-1,j]   [n-i-1,n-j-1]
            ans += max({M[i][j],M[i][n-j-1],
                    M[n-i-1][j],M[n-i-1][n-j-1]});
        }
    }
    return ans;
}

// new one
int flippingMatrix(vector<vector<int>> A) {
    int sum = 0;
    int n = A.size(), m = A[0].size();
    int cur, right, down, diag, ans;
    for(int i=0; i<n/2; i++){
        for(int j=0; j<m/2; j++){
            cur = A[i][j];
            right = A[i][m-j-1];
            down = A[n-i-1][j];
            diag = A[n-i-1][m-j-1];
            ans = max({cur, right, down, diag});
            sum += ans;
        }
    }
    return sum;
}