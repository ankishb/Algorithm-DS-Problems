
string hackerrankInString(string s1) {
    string s2 = "hackerrank";
    int n1 = s1.length();
    int n2 = s2.length();
    char ch1, ch2;
    vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));
    for(int i=1; i<=n1; i++){
        for(int j=1; j<=n2; j++){
            ch1 = s1[i-1];
            ch2 = s2[j-1];
            if(ch1 == ch2) dp[i][j] = 1 + dp[i-1][j-1];
            else{
                dp[i][j] = max({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
            }
        }
    }
    return (dp[n1][n2] == n2) ? "YES" : "NO";
}