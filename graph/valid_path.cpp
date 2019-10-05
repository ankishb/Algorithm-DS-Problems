string Solution::solve(int x, int y, int n, int r, vector<int> &xs, vector<int> &ys) {
    vector<vector<bool>> A(x+1, vector<bool>(y+1,false));
    // for(int i=0; i<n; i++){
    //     int x1 = xs[i], y1 = ys[i];
    //     int lx = max(0, x1-r);
    //     int rx = min(x, x1+r);
    //     int dy = max(0, y1-r);
    //     int uy = min(y, y1+r);
    //     // cout<<x1<<" "<<y1<<" "<<lx<<" "<<rx<<" "<<uy<<" "<<dy<<endl;
    //     for(int ii=lx; ii<=rx; ii++){
    //         for(int jj=dy; jj<=uy; jj++){
    //             A[ii][jj] = true;
    //         }
    //     }
    // }
    
     for(int i=0; i<=x; i++){
        for(int j=0; j<=y; j++){
            for(int k=0; k<n; k++){
                if(sqrt(pow(xs[k]-i, 2) + pow(ys[k]-j, 2)) <= r){
                    A[i][j] = true;
                    break;
                }
            }
        }
     }
    
    for(int ii=0; ii<=x; ii++){
        for(int jj=0; jj<=y; jj++){
            cout<<A[ii][jj]<<" ";
        }
        cout<<endl;
    }
    
    if(A[0][0] == true) return "NO";
    if(A[x][y] == true) return "NO";
    
    int xss[] = {-1,-1,0,1,1, 1, 0,-1};
    int yss[] = { 0, 1,1,1,0,-1,-1,-1};
    queue<pair<int,int>> q;
    q.push({0,0});
    
    while(!q.empty()){
        pair<int,int> p = q.front(); q.pop();
        // cout<<p.first<<" "<<p.second<<endl;
        if(p.first == x && p.second == y) return "YES";
        
        for(int i=0; i<8; i++){
            if(p.first+xss[i] < 0 || p.second+yss[i] < 0) continue;
            if(p.first+xss[i] > x || p.second+yss[i] > y) continue;
            if(A[p.first+xss[i]][p.second+yss[i]]) continue;
            q.push({p.first+xss[i], p.second+yss[i]});
            A[p.first+xss[i]][p.second+yss[i]] = true;
        }
    }
    return "NO";
}
