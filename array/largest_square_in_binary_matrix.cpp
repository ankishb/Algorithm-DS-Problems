class Solution {
public:
    int maximalSquare(vector<vector<char>>& A) {
        int n = A.size();
        if(n == 0) return 0;
        int m = A[0].size(), area = 0;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                dp[i][j] = (A[i][j] == '0') ? 0 : 1;
                if(dp[i][j] == 1) area = 1;
            }
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(A[i][j] == '0') continue;
                if(A[i-1][j]=='1' && A[i][j-1]=='1' && A[i-1][j-1]=='1'){
                    dp[i][j] = 1+min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                    area = max(area, dp[i][j]*dp[i][j]);
                }
            }
        }
        return area;
    }
};

// last try
class Solution {
public:
    int maximalSquare(vector<vector<char>>& Ab){
        vector<vector<int>> A;
        vector<int> B;
        int max_size = 0;
        for(auto row : Ab){
            for(auto col : row){
                int el = (col == '1') ? 1 : 0;
                if(el == 1) max_size = 1;
                B.push_back(el);
            }
            A.push_back(B);
            B.clear();
        }
        int n = A.size(); 
        if(n == 0) return 0;
        int m = A[0].size();
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(A[i][j] == 0) continue;
                A[i][j] = 1 + min({A[i-1][j], A[i][j-1], A[i-1][j-1]});
                max_size = max(max_size, A[i][j]);
            }
        }
        return (max_size <= 1) ? max_size : max_size*max_size;
    }
};



// new try
void solve(){
    int n, m;
    cin>>n>>m;
    int T[n][m];
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>T[i][j];
            if(T[i][j] == 1) ans = 1;
        }
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(T[i][j] == 0) continue;
            T[i][j] = 1+min({T[i-1][j], T[i][j-1], T[i-1][j-1]});
            ans = max(ans, T[i][j]);
        }
    }
    cout<<ans<<endl;
}


// old one
#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)
int T[55][55];

// 1
// 2 24
// 0 0 0 1 0 1 1 1 1 1 0 1 1 1 0 1 1 0 1 1 1 1 1 1
// 0 0 0 0 1 0 0 0 0 0 1 1 0 0 0 1 0 1 1 0 1 0 1 1


void solve(){
	int n, m;
	cin>>n>>m;
	loop(i, 0, n){
		loop(j, 0, m){
			cin>>T[i][j];
		}
	}

	int result[n+1][m+1] = {0};
	// memset(result, 0, sizeof(result[0][0]) * (n+1) * (m+1));
	memset(result, 0, sizeof(result));

	loop(i, 0, n+1){
		loop(j, 0, m+1){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	int max_el = INT_MIN;
	loop(i, 1, n+1){
		loop(j, 1, m+1){
			if(T[i-1][j-1] == 1){
				result[i][j] = 1 + min(min(result[i-1][j-1], result[i-1][j]), result[i][j-1]);
				max_el = max(max_el, result[i][j]);
			}
			else{
				result[i][j] = 0;
			}
		}
	}


	cout<<endl<<"-- resultant matrix --"<<endl;
	loop(i, 1, n+1){
		loop(j, 1, m+1){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<max_el<<endl;
}


int main()
 {
	int test;
	cin>>test;
	while(test--){
	    solve();
	    // check();
	}
	return 0;
}