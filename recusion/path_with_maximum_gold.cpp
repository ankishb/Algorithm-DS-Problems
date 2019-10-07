
/*
1. Tranverse through each cell, if it contains some gold, find path with maximum gold from that cell
Note: Carefully go through this example, to understand, why we need to run DFS from each cell
Exp: 
    [
     [0,6,0],
     [9,8,7],
     [0,5,0]
    ]
    Path with maximum gold: 9 -> 8 -> 7
*/
class Solution {
public:
    int n, m, global_max;
    bool is_valid(int i, int j){
        return (i>=0 && i<n && j>=0 && j<m);
    }
    void dfs_util(vector<vector<int>> &T, int i, int j, int cur_max){
        cur_max += T[i][j];
        // cout<<T[i][j]<<" "<<cur_max<<endl;
        int value = T[i][j];
        global_max = max(global_max, cur_max);
        T[i][j] = 0; // lock state
        // up
        if(is_valid(i-1,j) && T[i-1][j] != 0){
            dfs_util(T, i-1, j, cur_max);
        }
        // down
        if(is_valid(i+1,j) && T[i+1][j] != 0){
            dfs_util(T, i+1, j, cur_max);
        }
        // left
        if(is_valid(i,j-1) && T[i][j-1] != 0){
            dfs_util(T, i, j-1, cur_max);
        }
        // right
        if(is_valid(i,j+1) && T[i][j+1] != 0){
            dfs_util(T, i, j+1, cur_max);
        }
        cur_max -= T[i][j];
        T[i][j] = value;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size();
        if(n == 0) return 0;
        m = grid[0].size();
        global_max = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0) continue;
                else dfs_util(grid, i, j, 0);
            }
        }
        return global_max;
    }
};