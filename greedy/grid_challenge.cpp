
string gridChallenge(vector<string> grid) {
    int n = grid.size(), m = grid[0].length();
    for(int i=0; i<n; i++){
        sort(grid[i].begin(), grid[i].end());
    }
    for(int j=0; j<grid[0].length(); j++){
        for(int i=1; i<n; i++){
            if(grid[i][j] < grid[i-1][j]){
                return "NO";
            }
        }
    }
    return "YES";
}