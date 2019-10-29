
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vii vector<vector<int>>
#define f first
#define s second
#define ll long long int 
int A[105][105];

// creat a signature function here
int get_min_time(int n, int m){
    queue<pii> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>A[i][j];
            if(A[i][j] == 2){
                q.push({i, j});
            }
        }
    }
    int t = 0, x, y;
    q.push({1000,1000});
    while(!q.empty()){
        pii front = q.front();
        x = front.first;
        y = front.second;
        q.pop();
        if(x == 1000 && y == 1000){
            t++;
            if(q.empty()) break;
            else q.push({1000,1000});
            continue;
        }
        // A[x][y] = 2;
        if(x-1 >=0 && A[x-1][y] == 1){
            A[x-1][y] = 2;
            q.push({x-1,y});
        }
        if(x+1 < n && A[x+1][y] == 1){
            A[x+1][y] = 2;
            q.push({x+1,y});
        }
        if(y-1 >=0 && A[x][y-1] == 1){
            A[x][y-1] = 2;
            q.push({x,y-1});
        }
        if(y+1 < m && A[x][y+1] == 1){
            A[x][y+1] = 2;
            q.push({x,y+1});
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(A[i][j] == 1) return -1;
        }
    }
    return t-1;
}



int main()
 {
	int test;
	cin>>test;
	while(test--){
	    // input and call signature function
	    int n, m;
	    cin>>n>>m;
	   // for(int i=0; i<n; i++){
	   //     for(int j=0; j<m; j++){
	   //         cin>>A[i][j];
	   //     }
	   // }
	    cout<<get_min_time(n, m)<<endl;
	}
	return 0;
}