
int get_min_cost(string s1, string s2, int c1, int c2){
    int n1 = s1.length();
    int n2 = s2.length();
    vii dp(n1+1, vi(n2+1,0));
    for(int i=0; i<=n1; i++) dp[i][0] = 0;
    for(int i=0; i<=n2; i++) dp[0][i] = 0;
    for(int i=1; i<=n1; i++){
        for(int j=1; j<=n2; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max({dp[i-1][j], dp[i][j-1]});
            }
        }
    }
    
    int len = dp[n1][n2]; // longest common subsequence
    return c1*(n1-len) + c2*(n2-len);
}