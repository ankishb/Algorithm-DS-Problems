
// new one ( O(N) )
class Solution {
public:
    vector<int> countBits(int n) {
        if(n == 0) return {0};
        int size = 1 + log2(n);
        
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        for(int i=1; i<size; i++){
            int len = pow(2,i);
            for(int j=0; j<len; j++){
                dp[len+j] = dp[j]+1;   
                if(len+j == n) return dp;
            }
        }
        return dp;
    }
};

// old try
class Solution {
public:
    vector<int> countBits1(int n) {
        vector<int> dp(n+1, 0);
        if(n == 0) return {0};
        if(n == 1) return {0,1};
        dp[0] = 0; dp[1] = 1;
        int close_2s, rem;
        
        for(int i=2; i<=n; i++){
            close_2s = pow(2, (int)log2(i));
            rem = i - close_2s;
            // cout<<i<<" "<<close_2s<<" "<<rem<<endl;
            if(i == close_2s) dp[i] = 1;
            else dp[i] = dp[close_2s] + dp[rem];
        }
        return dp;
    }
    
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for ( int i = 1; i <= num; i++ ) {
            ret[i] = ret[i/2] + i % 2;
            // res[i] = res[i >> 1] + (i & 1);
        }
        return ret;
    }
};