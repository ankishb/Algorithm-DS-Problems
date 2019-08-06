
class Solution {
public:
    void visit_adj(vector<vector<char>>& grid, int i, int j){
        int n = grid.size();
        int m = grid[0].size();
        if((i<0 || i>=n) || (j<0 || j>=m)) return;
        grid[i][j] = 0;
        // top     : [i-1][j]
        // bottom  : [i+1][j]
        // left    : [i][j-1]
        // right   : [i][j+1]
        
        if(i-1 >= 0 && grid[i-1][j] =='1') visit_adj(grid, i-1, j);
        if(i+1 < n  && grid[i+1][j] =='1') visit_adj(grid, i+1, j);
        if(j-1 >= 0 && grid[i][j-1] =='1') visit_adj(grid, i, j-1);
        if(j+1 < m  && grid[i][j+1] =='1') visit_adj(grid, i, j+1);
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int n = grid.size();
        if(n==0) return count;
        int m = grid[0].size();
        
        // vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1'){
                    count++;
                    visit_adj(grid, i, j);
                } 
            }
        }
        return count;
    }
};



void visit_group(vector<vector<int> > &pattern, 
    vector<vector<bool> > &visited, int i, int j){
    if(pattern[i][j] == 0) return;
    int n = pattern.size();
    int m = pattern[0].size();
    if(i-1>=0 && !visited[i-1][j] && pattern[i-1][j] == 1){
        visited[i-1][j] = true;
        visit_group(pattern, visited, i-1, j);
    }
    if(j-1>=0 && !visited[i][j-1] && pattern[i][j-1] == 1){
        visited[i][j-1] = true;
        visit_group(pattern, visited, i, j-1);
    }
    if(i+1<n && !visited[i+1][j] && pattern[i+1][j] == 1){
        visited[i+1][j] = true;
        visit_group(pattern, visited, i+1, j);
    }
    if(j+1<m && !visited[i][j+1] && pattern[i][j+1] == 1){
        visited[i][j+1] = true;
        visit_group(pattern, visited, i, j+1);
    }
    // top left diag
    if(i-1>=0 && j-1>=0 && !visited[i-1][j-1] && pattern[i-1][j-1]==1){
        visited[i-1][j-1] = true;
        visit_group(pattern, visited, i-1, j-1);
    }
    // top right diag
    if(i-1>=0 && j+1>=0 && !visited[i-1][j+1] && pattern[i-1][j+1]==1){
        visited[i-1][j+1] = true;
        visit_group(pattern, visited, i-1, j+1);
    }
    // bottom left diag
    if(i+1>=0 && j-1>=0 && !visited[i+1][j-1] && pattern[i+1][j-1] == 1){
        visited[i+1][j-1] = true;
        visit_group(pattern, visited, i+1, j-1);
    }
    // bottom right diag
    if(i+1>=0 && j+1>=0 && !visited[i+1][j+1] && pattern[i+1][j+1] == 1){
        visited[i+1][j+1] = true;
        visit_group(pattern, visited, i+1, j+1);
    }
}

int count_group(vector<vector<int> > pattern){
    int n = pattern.size();
    int m = pattern[0].size();
    int count = 0;
    vector<vector<bool> > visited(n, vector<bool>(m,0));
    // memset(visited, 0, sizeof(visited));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visited[i][j]) continue;
            if(pattern[i][j] == 0){
                visited[i][j] = true;
            }
            else{
                count++;
                visit_group(pattern, visited, i, j);
            }
        }
    }
    return count;
}

int findIslands(vector<int> A[], int N, int M){
    vector<vector<int> > vect;
    for(int i=0; i<N; i++){
        vect.push_back(A[i]);
    }
    return count_group(vect);
}
