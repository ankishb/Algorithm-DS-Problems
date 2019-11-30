
// constant space approach, with O(n*m) time complexity

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vii vector<vector<int>>
#define f first
#define s second
#define ll long long int 

// creat a signature function here

void convert_1_to_0(vector<vector<int>> arr){
    int n = arr.size(), m = arr[0].size();
    bool row1 = false, col1 = false;
    for(int i=0; i<n; i++){
        if(arr[i][0] == 1){
            col1 = true;
            break;
        }
    }
    for(int i=0; i<m; i++){
        if(arr[0][i] == 1){
            row1 = true;
            break;
        }
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(arr[i][j] == 1){
                arr[0][j] = 1;
                arr[i][0] = 1;
            }
        }
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(arr[0][j] == 1 || arr[i][0] == 1){
                arr[i][j] = 1;
            }
        }
    }
    if(row1){
        for(int i=0; i<m; i++){
            arr[0][i] = 1;
        }
    }
    if(col1){
        for(int j=0; j<n; j++){
            arr[j][0] = 1;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}


int main()
 {
	int test;
	cin>>test;
	while(test--){
	    // input and call signature function
	    int n, m;
	    cin >> n >> m;
	    vector<vector<int>> arr(n, vector<int>(m));
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            cin >> arr[i][j];
	        }
	    }
	    convert_1_to_0(arr);
	}
	return 0;
}