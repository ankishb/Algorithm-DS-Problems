#include <iostream>
using namespace std;

char T[10][10];

void dfs(int n, int m, int x, int y, int &ans, int cur){
    // cout<<cur<<" ";
    if(T[x][y] == 'G'){
        ans = min(ans, cur);
        return ;
    }
    char value = T[x][y];
    T[x][y] = 'V';
    
    
    // move left
    if(y-1 >= 0 && (T[x][y-1] == 'G' || T[x][y-1] == '_')){
        dfs(n, m, x, y-1, ans, cur);
    }
    
    // move right
    if(y+1 < m && (T[x][y+1] == 'G' || T[x][y+1] == '_') ){
        dfs(n, m, x, y+1, ans, cur);
    }
    
    // move up(find a place to put step on)
    int up = x-1;
    while(up >= 0 && T[up][y] == ' ') up--;
    if(up >= 0 && (T[up][y] == 'G' || T[up][y] == '_')){
        dfs(n, m, up, y, ans, max(x-up, cur));
    }
    // move down(find a place to put step on)
    int down = x+1;
    while(down < n && T[down][y] == ' ') down++;
    if(down < n && (T[down][y] == '_' || T[down][y] == 'G')){
        dfs(n, m, down, y, ans, max(down-x, cur));
    }
    
    // put back its original state
    T[x][y] = value;
    
}

int main() {
	int test;
	cin>>test;
	while(test--){
	    int n, m;
	    cin>>n>>m;
	    int dx, dy, el;
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            cin>>el;
	            if(el == 0) T[i][j] = ' ';
	            else if(el == 3) T[i][j] = 'G';
	            else if(el == 1) T[i][j] = '_';
    	       // if(T[i][j] == 'G'){
    	       //     dx = i, dy = j;
    	       // }
	        }
	    }
	    int sx = n-1, sy = 0;
	    int ans = max(n, m);
	    dfs(n, m, sx, sy, ans, 0);
	    
	    
	    
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            if(T[i][j] == ' ') cout<<'S';
    	        else cout<<T[i][j];
	        }cout<<endl;
	    }
	    cout<<ans<<endl;
	}
	return 0;
}