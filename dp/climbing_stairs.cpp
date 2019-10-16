
// new try
int main()
 {
    int test;
    cin>>test;
    
    vector<ll> dp(100005, 0);
    dp[1] = 1, dp[2] = 2;
    for(int i=3; i<100005; i++){
        dp[i] = dp[i-2]+dp[i-1];
        dp[i] = dp[i]%mod;
    }
    
    while(test--){
        int n;
        cin>>n;
        cout<<dp[n]<<endl;
    }
    return 0;
}

// old one
class Solution {
public:
    int climbStairs(int n) {
        vector<int> arr(n+1,0);
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 2;
        for(int i=3; i<=n; i++){
            arr[i] = arr[i-2] + arr[i-1];
        }
        return arr.back();
    }
};