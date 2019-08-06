
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


// light-weight
int Solution::numTrees(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int dp[A+1];
    dp[0] = 1;
    for(int i=1;i<=A;i++){
        dp[i]=0;
        for(int j=1;j<=i;j++)
            dp[i] += dp[j-1]*dp[i-j];
    }
    return dp[A];
    
}


//fastest