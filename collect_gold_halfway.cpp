#include <bits/stdc++.h>
using namespace std;
// ‘#’ means blocked path
// ‘.’ means walkable path
// ‘*’ means points that you have to collect

void dfs(vector<vector<char>> &A, int x, int y, bool down, int coin, int &max_coin){
    int n = A.size(), m = A[0].size(), x1, y1;
    if(down && x == n-1 && y == n-1){
        max_coin = max(max_coin, coin);
    }
    if(!down && x == 0 && y == 0){
        max_coin = max(max_coin, coin);
    }
    // if(x < 0 && x >= n && y < 0 && y >= m) return;
    
    int xs[2];
    int ys[2];
    if(down == true){ // (i,j) -> (i+1, j) && (i, j+1)
        xs[0] = 1, xs[1] = 0;
        ys[0] = 0, ys[1] = 1;
    }
    else{// (i,j) -> (i-1, j) && (i, j-1)
        xs[0] = -1, xs[1] = 0;
        ys[0] = 0, ys[1] = -1;
    }
    x1 = x+xs[0], y1 = y+ys[0];
    if(x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && A[x1][y1] != '#'){
        if(A[x1][y1] == '*') coin++;
        A[x1][y1] = '#';
        dfs(A, x1, y1, down, coin, max_coin);
    }
    
    x1 = x+xs[1], y1 = y+ys[1];
    if(x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && A[x1][y1] != '#'){
        if(A[x1][y1] == '*') coin++;
        A[x1][y1] = '#';
        dfs(A, x1, y1, down, coin, max_coin);
    }
    
}

int collect_gold(vector<vector<char>> A, int n, int m){
    int c1 = 0, c2 = 0;
    dfs(A, 0, 0, true, 0, c1);
    dfs(A, n-1, m-1, false, 0, c2);
    cout<<c1<<" "<<c2<<endl;
    return c1+c2;
}

int main()
{
    int test;
    cin>>test;
    while(test--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> A(n, vector<char>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>A[i][j];
            }
        }
        cout<<collect_gold(A, n, m);
    }
}