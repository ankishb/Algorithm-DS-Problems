
int Solution::minPathSum(vector<vector<int> > &A) {
    int i, j;
    for(i=0; i<A.size(); i++){
        for(j=0; j<A[i].size(); j++){
            if(i==0 && j==0) continue;
            else if(i==0) A[i][j] = A[i][j-1]+A[i][j];
            else if(j==0) A[i][j] = A[i-1][j]+A[i][j];
            else A[i][j] += min(A[i-1][j], A[i][j-1]);
        }
    }
    return A[i-1][j-1];
}

// Another Approach (look at logic)
int Solution::minPathSum(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int curr = INT_MAX;
            if (i-1 >= 0) {
                curr = min(curr, A[i-1][j]);
            }
            if (j-1 >= 0) {
                curr = min(curr, A[i][j-1]);
            }
            if (curr != INT_MAX) {
                A[i][j] += curr;
            }
        }
    }
    return A[n-1][m-1];
}
