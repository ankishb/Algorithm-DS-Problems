#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)
// #define rows 20
int T[20][20];

/*
    A value of cell 1 means Source.
    A value of cell 2 means Destination.
    A value of cell 3 means Blank cell.
    A value of cell 0 means Blank Wall.
*/
struct cell{
    int x, y;
};

bool is_valid(int x, int y, int n){
    return (x>=0 && x<n && y>=0 && y<n);
}

void dfs(int n, int x1, int y1, int x2, int y2, bool &find){
    if(x1 == x2 && y1==y2){
        // cout<<"found\n";
        find = true;
        return;
    }
    // cout<<x1<<" "<<y1<<endl;
    T[x1][y1] = 0;
    int x = x1, y = y1;
    if(is_valid(x-1,y,n) && T[x-1][y] != 0){
        dfs(n, x1-1, y1, x2, y2, find);
    }
    if(is_valid(x,y-1,n) && T[x][y-1] != 0){
        dfs(n, x1, y1-1, x2, y2, find);
    }
    if(is_valid(x+1,y,n) && T[x+1][y] != 0){
        dfs(n, x1+1, y1, x2, y2, find);
    }
    if(is_valid(x,y+1,n) && T[x][y+1] != 0){
        dfs(n, x1, y1+1, x2, y2, find);
    }
}


bool check_path(int n){
    cell src;
    cell dst;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(T[i][j] == 1) src.x = i, src.y = j;
            if(T[i][j] == 2) dst.x = i, dst.y = j;
        }
    }
    bool find = false;
    // cout<<src.x<<" "<<src.y<<" "<<dst.x<<" "<<dst.y<<endl;
    dfs(n, src.x, src.y, dst.x, dst.y, find);
    return find;
}

int main()
 {
	int test;
	cin>>test;
	while(test--){
	    int n;
	    cin>>n;
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            cin>>T[i][j];
	        }
	    }
	    cout<<check_path(n)<<endl;
	}
	return 0;
}