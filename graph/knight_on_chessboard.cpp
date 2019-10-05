
// leetcode
/* BFS
1. Explore all possiblies states from current state
2. Maintain a visiting set/matrix to keep track the repeated/looing cases
*/
int Solution::knight(int n, int m, int x1, int y1, int x2, int y2){
    queue<vector<int>> q;
    // make 0 based indexing
    x1--; y1--; x2--; y2--;
    q.push({x1,y1,0});
    vector<vector<bool>> vis(n, vector<bool>(m,false));

    // knight can make 8 possible moves at a position
    // left-top, up-left, up-right, right-top
    // left-down, down-left, down-right, right-down
    int ys[] = {-2,-1,1,2,-2,-1, 1, 2};
    int xs[] = { 1, 2,2,1,-1,-2,-2,-1};
    while(!q.empty()){
        vector<int> p = q.front();
        int x = p[0], y = p[1], mv = p[2];
        // cout<<x<<" "<<y<<" "<<mv<<endl;
        if(x == x2 && y == y2) return mv;
        q.pop();
        if(vis[x][y] == true) continue;
        vis[x][y] = true;
        
        for(int i=0; i<8; i++){
            int xn = x+xs[i], yn = y+ys[i];
            // cout<<"--"<<xn<<" "<<yn<<" "<<m<<" "<<n<<endl;
            if(xn >= 0 && xn < n && yn >= 0 && yn < m && vis[xn][yn] == false){
                q.push({xn, yn, mv+1});
            }
        }
    }
    return -1;
}


// hackerrank
#include <bits/stdc++.h>
using namespace std;

/* BFS
1. Explore all possiblies states from current state
2. Maintain a visiting set/matrix to keep track the repeated/looing cases
*/
int knight_moves(int n, int a, int b){
    queue<vector<int>> q;
    int x1 = 0, y1 = 0, x2 = n-1, y2 = n-1;
    q.push({x1,y1,0});
    vector<vector<bool>> vis(n, vector<bool>(n,false));

    // knight can make 8 possible moves at a position
    // left-top, up-left, up-right, right-top
    // left-down, down-left, down-right, right-down
    int ys[] = {-a,-b,b,a,-a,-b, b, a};
    int xs[] = { b, a,a,b,-b,-a,-a,-b};
    while(!q.empty()){
        vector<int> p = q.front();
        int x = p[0], y = p[1], mv = p[2];
        // cout<<x<<" "<<y<<" "<<mv<<endl;
        if(x == x2 && y == y2) return mv;
        q.pop();
        if(vis[x][y] == true) continue;
        vis[x][y] = true;
        
        for(int i=0; i<8; i++){
            int xn = x+xs[i], yn = y+ys[i];
            // cout<<"--"<<xn<<" "<<yn<<" "<<m<<" "<<n<<endl;
            if(xn >= 0 && xn < n && yn >= 0 && yn < n && vis[xn][yn] == false){
                q.push({xn, yn, mv+1});
            }
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> result(n, vector<int>(n,0));
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            if(result[i][j] != 0){
                cout<<result[i][j]<<" ";
            }
            else{
                int moves = knight_moves(n, i, j);
                result[j][i] = moves;
                cout<<moves<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
