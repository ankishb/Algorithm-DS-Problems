void fill_matrix(vector<vector<int>> &ans, int ii, int jj, int n, int &count){
    int i, j, itr;
    // top: i+0, j+0 - j+n-1
    i = ii, j = jj, itr=n-1;
    while(itr > 0){
        ans[i][j] = count;
        count++; j++; itr--;
    }
    // right: i+0 - i+n-1, j+n;
    i = ii, j = jj+n-1, itr = n-1;
    while(itr > 0){
        ans[i][j] = count;
        count++; i++; itr--;
    }
    // bottom: i+n-1, j+n - j+1
    i = ii+n-1, j = jj+n-1, itr = n-1;
    while(itr > 0){
        ans[i][j] = count;
        count++; j--; itr--;
    }
    // left: i+n - i+1, j+0
    i = ii+n-1, j = jj, itr = n-1;
    while(itr > 0){
        ans[i][j] = count;
        count++; i--; itr--;
    }
}


vector<vector<int> > Solution::generateMatrix(int n) {
    if(n == 0){
        vector<vector<int>> ans;
        return ans;
    }
    vector<vector<int>> ans(n, vector<int>(n,0));
    
    int count = 1;
    int size = n;
    int start_i=0, start_j=0;
    while(size > 1){
        fill_matrix(ans, start_i, start_j, size, count);
        start_i += 1;
        start_j += 1;
        size -= 2;
    }
    // even: it completely transverse every cell
    // odd: it leave one(centred) cell
    if(n%2 != 0) ans[n/2][n/2] = count;
    return ans;
}
