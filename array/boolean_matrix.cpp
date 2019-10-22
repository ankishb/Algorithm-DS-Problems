
void naive(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> A(n, vector<int>(m));
    queue<pair<int,int>> q;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>A[i][j];
            if(A[i][j] == 1){
                q.push({i,j});
            }
        }
    }
    while(!q.empty()){
        pair<int,int> f = q.front();
        q.pop();
        if((f.x-1 >= 0 && A[f.x-1][f.y] == 1)
        && (f.y-1 >= 0 && A[f.x][f.y-1] == 1)
        && (f.x+1 < n  && A[f.x+1][f.y] == 1)
        && (f.y+1 < m  && A[f.x][f.y+1] == 1)){
            continue;
        }
        for(int i=0; i<n; i++){
            A[i][f.y] = 1;
        }
        for(int j=0; j<m; j++){
            A[f.x][j] = 1;
        }
        
    }
    
    for(auto row : A){
        for(auto col : row){
            cout<<col<<" ";
        }
        cout<<endl;
    }
}

void optimal(){
    int el, n, m;
    cin>>n>>m;
    vector<int> row(n,0), col(m,0);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>el;
            if(el == 1){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            (row[i] == 1 || col[j] == 1) ? cout<<"1 " : cout<<"0 ";
        }
        cout<<endl;
    }
}