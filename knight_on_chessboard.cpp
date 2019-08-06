
void getMoves(int n, int i, int j, int a, int b, int &minMoves, int count, vector<vector<bool>> vis){
    cout<<i<<" "<<j<<endl;
    if(i>=n || i<0 || j>=n || j<0) return;
    vis[i][j] = true;
    if(i==n-1 && j==n-1){
        if(minMoves == -1 && count > 0) minMoves = count;
        else minMoves = min(minMoves, count);
        return;
    }
    if((i+a>=n || i+a<0 || j+b>=n || j+b<0) && !vis[i+a][j+b]) 
        getMoves(n, i+a, j+b, a, b, minMoves, count+1, vis);
    if((i-a>=n || i-a<0 || j+b>=n || j+b<0) && !vis[i-a][j+b]) 
        getMoves(n, i-a, j+b, a, b, minMoves, count+1, vis);
    if((i+a>=n || i+a<0 || j-b>=n || j-b<0) && !vis[i+a][j-b]) 
        getMoves(n, i+a, j-b, a, b, minMoves, count+1, vis);
    if((i-a>=n || i-a<0 || j-b>=n || j-b<0) && !vis[i-a][j-b]) 
        getMoves(n, i-a, j-b, a, b, minMoves, count+1, vis);
    if((i+b>=n || i+b<0 || j+a>=n || j+a<0) && !vis[i+b][j+a]) 
        getMoves(n, i+b, j+a, a, b, minMoves, count+1, vis);
    if((i-b>=n || i-b<0 || j+a>=n || j+a<0) && !vis[i-b][j+a]) 
        getMoves(n, i-b, j+a, a, b, minMoves, count+1, vis);
    if((i+b>=n || i+b<0 || j-a>=n || j-a<0) && !vis[i+b][j-a]) 
        getMoves(n, i+b, j-a, a, b, minMoves, count+1, vis);
    if((i-b>=n || i-b<0 || j-a>=n || j-a<0) && !vis[i-b][j-a]) 
        getMoves(n, i-b, j-a, a, b, minMoves, count+1, vis);
    return ;
}   

// Complete the knightlOnAChessboard function below.
vector<vector<int>> knightlOnAChessboard(int n) {
    int minMoves, count;
    vector<vector<int>> ans(n-1, vector<int>(n-1,0));
    // vector<vector<bool>> vis(n-1, vector<bool>(n-1,false));
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            minMoves = -1;
            vector<vector<bool>> vis(n-1, vector<bool>(n-1,false));
            getMoves(n, 0, 0, i, j, minMoves, 0, vis);
            ans[i-1][j-1] = minMoves;
        }
    }
    return ans;
}