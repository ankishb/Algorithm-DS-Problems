
long optimized1(int k, vector<long> c){
    int n = c.size();
    vector<vector<long>> dp(n, vector<long>(k,0));
    // fill first row
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            if(i == 0) dp[i][j] = ((j+1) % c[i] == 0) ? 1 : 0;
            else{
                if((j+1) < c[i]) dp[i][j] = dp[i-1][j];
                else if((j+1) == c[i]) dp[i][j] = 1 + dp[i-1][j];
                else{
                    dp[i][j] = dp[i][j-c[i]] + dp[i-1][j];
                }
            } 
        }
    }
    return dp[n-1][k-1];
}

long optimized2(int k, vector<long> c){
    int n = c.size();
    vector<long> dp(k,0);
    // fill first row
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            if(i == 0) dp[j] = ((j+1) % c[i] == 0) ? 1 : 0;
            else{
                if((j+1) < c[i]) dp[j] = dp[j];
                else if((j+1) == c[i]) dp[j] += 1;
                else{
                    dp[j] += dp[j-c[i]];
                }
            } 
        }
    }
    return dp[k-1];
}

long getWays(int k, vector<long> c) {
    // return optimized1(k, c);
    return optimized2(k, c);
}