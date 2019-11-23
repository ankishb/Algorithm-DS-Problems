#include <bits/stdc++.h>
using namespace std;

/*
-3 -2 -1 1 
-2 2 3 4 
4 5 7 8 
4
-3 -2 -1 
-2 -2 -1 
-1 0 2 
0 1 2 
7
*/

int main()
{
    int test;
    cin>>test;
    while(test--){
        int n, m;
        cin>>n>>m;
        int T[n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>T[i][j];
            }
        }
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<<T[i][j]<<" ";
            }
            cout<<endl;
        }
        int i=0, j=m-1;
        while(i < n && j >= 0){
            if(T[i][j] >= 0) j--;
            else{
                count += j+1;
                i++;
            }
        }
        cout<< count << endl;
    }
    return 0;
}