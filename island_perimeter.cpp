
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int peri = 0;
        int n = grid.size();
        if(n==0) return peri;
        int m = grid[0].size();
        
        // vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    if(i-1<0 || grid[i-1][j]==0) peri++;
                    if(i+1>=n || grid[i+1][j]==0) peri++;
                    if(j-1<0 || grid[i][j-1]==0) peri++;
                    if(j+1>=m || grid[i][j+1]==0) peri++;
                } 
            }
        }
        return peri;
    }
};
