class triplet{
public:
    int x, y, moves;
    triplet(){};
    triplet(int x_, int y_, int m_) : x(x_), y(y_), moves(m_) {}
    // void fill(int x_, int y_, int m_){
    //     x = x_, y = y_, moves = m_;
    // }
};

int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    int n=grid.size();
    if(n==0) return 0;
    int m=grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m,0));
    queue<triplet> q;
    triplet front;
    q.push(triplet(goalX, goalY, 0));
    vis[goalX][goalY] = true;
    int x, y, x1, y1, moves, i, j;
    
    pair<int,int> ipair;
    while(!q.empty()){
        front = q.front();
        q.pop();
        x = front.x;
        y = front.y;
        moves = front.moves;
        // cout<<x<<" "<<y<<" "<<moves<<endl;
        if(x==startX && y==startY) return moves;

        // go left
        x1 = x;
        if(y-1>=0 && grid[x][y-1]!='X' && vis[x][y-1]==false){
            for(y1=y-1; y1>=0; y1--){
                if(vis[x1][y1] || grid[x1][y1]=='X') break;
                vis[x1][y1] = true;
            }
            // cout<<":: "<<x1<<" "<<y1+1<<" ::";
            q.push(triplet(x1,y1+1,moves+1));
        }

        // go right
        x1 = x;
        if(y+1<m && grid[x][y+1]!='X' && vis[x][y+1]==false){
            for(y1=y+1; y1<m; y1++){
                if(vis[x1][y1] || grid[x1][y1]=='X') break;
                vis[x1][y1] = true;
            }
            // cout<<":: "<<x1<<" "<<y1-1<<" ::";
            q.push(triplet(x1,y1-1,moves+1));
        }

        // go top
        y1 = y;
        if(x-1>=0 && grid[x-1][y]!='X' && vis[x-1][y]==false){
            for(x1=x-1; x1>=0; x1--){
                if(vis[x1][y1] || grid[x1][y1]=='X') break;
                vis[x1][y1] = true;
            }
            // cout<<":: "<<x1+1<<" "<<y1<<" ::";
            q.push(triplet(x1+1,y1,moves+1));
        
        }
        // go down
        y1 = y;
        if(x+1<n && grid[x+1][y]!='X' && vis[x+1][y]==false){
            for(x1=x+1; x1<n; x1++){
                if(vis[x1][y1] || grid[x1][y1]=='X') break;
                vis[x1][y1] = true;
            }
            // cout<<":: "<<x1-1<<" "<<y1<<" ::";
            q.push(triplet(x1-1,y1,moves+1));
        }
    }
    return -1;
}