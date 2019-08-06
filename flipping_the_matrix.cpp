
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