
// new try
int Solution::numTrees(int n) {
    if(n <= 2) return n;
    int dp[n+1];
    // int dp[n+1] = {0}; // doesn't work, use memset
    dp[0] = 0; 
    dp[1] = 1; 
    dp[2] = 2;
    for(int i=3; i<=n; i++){
        // first count edge case
        int total = 2*dp[i-1];
        // now compute for in between cases
        for(int j=2; j<i; j++){
            total += dp[j-1]*dp[i-j];
        }
        dp[i] = total;
    }
    return dp[n];
}

// old one
// my approach
int Solution::numTrees(int n) {
    int T[n+1];
    memset(T, 0, sizeof(T));
    T[0] = 0;
    T[1] = 1;
    T[2] = 2;
    for(int i=3; i<=n; i++){
        for(int j=0; j<i; j++){
            if(j==0) T[i] += T[i-j-1];
            else if(j==i-1) T[i] += T[j];
            else T[i] += T[j]*T[i-j-1];
        }
    }
    // for(int i=0; i<=5; i++){
    //     cout<<T[i]<<" ";
    // }
    // cout<<endl;
    return T[n];
}


// light-weight (editorial)
int Solution::numTrees(int A) {
    int dp[A+1];
    dp[0] = 1;
    for(int i=1;i<=A;i++){
        dp[i]=0;
        for(int j=1;j<=i;j++)
            dp[i] += dp[j-1]*dp[i-j];
    }
    return dp[A];
    
}
