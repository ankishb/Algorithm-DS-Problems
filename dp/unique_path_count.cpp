
// new try
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 || j == 0) dp[i][j] = 1;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};




// old one
int Solution::uniquePaths(int n, int m){
    if(n == 0 || m == 0) return 0;
    vector<vector<int>> dp(n, vector<int>(m,0));
    for(int i=0; i<n; i++){
        dp[i][0] = 1;
    }
    for(int j=0; j<m; j++){
        dp[0][j] = 1;
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[n-1][m-1];
}


// elegant solution with constant memory
int uniquePaths(int m, int n) {
    // m+n-2 C n-1 = (m+n-2)! / (n-1)! (m-1)! 
    long long ans = 1;
    for (int i = n; i < (m + n - 1); i++) {
        ans *= i;
        ans /= (i - n + 1);
    }
    return (int)ans;
}


// another elegant and easy to understand with memory: O(n) 
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(n == 0 || m == 0) return 0;
        vector<vector<int>> dp1(m, vector<int>(n,0));
        vector<vector<int>> dp2(m, vector<int>(n,0));
                
        for(int i=m-1; i>=0; i--) dp2[i][0] = 1;
        for(int i=n-1; i>=0; i--) dp2[0][i] = 1;
        
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp2[i][j] = dp2[i-1][j] + dp2[i][j-1];
            }
        }
        return dp2[m-1][n-1];
    }
};