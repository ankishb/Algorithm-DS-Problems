
class Solution {
public:
    int minDistance(string word1, string word2) {
        // return optimal_time(word1, word2);
        return optimal_space1(word1, word2);
        // return optimal_space2(word1, word2);
        
    }
    int optimal_time(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        if(n == 0) return m;
        if(m == 0) return n;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                dp[i][j] = (word1[i-1] == word2[j-1]) 
                           ? (1 + dp[i-1][j-1]) 
                           : max(dp[i-1][j], dp[i][j-1]);
            }
        }
        // for(auto v : dp){ for(auto el : v) cout<<el<<" "; cout<<endl; }
        // cout<<endl;
        return (n - dp[n][m]) + (m - dp[n][m]);
    }
    int optimal_space1(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if(n == 0) return m;
        if(m == 0) return n;
        vector<int> pre(m+1,0), cur(m+1, 0);
        for(int i=1; i<=n; i++){
            cur.clear(); cur.resize(m+1, 0);
            for(int j=1; j<=m; j++){
                cur[j] = (s1[i-1] == s2[j-1]) ? (1 + pre[j-1]) : max(pre[j], cur[j-1]);
            }
            pre = cur;
        }
        // for(auto v : dp){ for(auto el : v) cout<<el<<" "; cout<<endl; }
        // cout<<endl;
        return (n - cur[m]) + (m - cur[m]);
    }
    int optimal_space2(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if(n == 0) return m;
        if(m == 0) return n;
        int prev_upper, cur_upper;
        vector<int> cur(m+1, 0);
        for(int i=1; i<=n; i++){
            prev_upper = cur[0];
            for(int j=1; j<=m; j++){
                cur_upper = cur[j];
                cur[j] = (s1[i-1] == s2[j-1]) ? (1 + prev_upper) : max(cur[j], cur[j-1]);
                cur_upper = prev_upper;
            }
        }
        return (n - cur[m]) + (m - cur[m]);
    }
};