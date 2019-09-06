
class Solution {
public:
    string longestPalindrome(string s) {
        // return optimized1(s);
        return optimized2(s);
    }
    string optimized1(string s) {
        string T = "#";
        int n = s.length();
        for(int i=0; i<n; i++){
            T += s[i];
            T += "#";
        }
        
        int max_len = 0, m = T.length();
        vector<int> len(m,0);
        for(int i=0; i<m; i++){
            int c = i, l = c-1, r = c+1;
            while(l>=0 && r<=m-1 && T[l] == T[r]){
                l--; r++; len[c]++;
            }
            max_len = max(max_len, len[c]);
        }
        int i;
        for(i=0; i<m; i++){
            if(len[i] == max_len) break;
        }
        
        string ans = "";
        for(int j=i-len[i]; j<=i+len[i]; j++){
            if(T[j] == '#') continue;
            ans += T[j];
        }
        return ans;
    }
    string optimized2(string s) {
        int n = s.length(), max_len = 1, start_idx = 0;
        vector<vector<bool>> dp(n, vector<bool>(n,false));
        
        for(int k=0; k<n; k++){
            for(int i=0; i<n-k; i++){
                int j = i+k;
                if(i == j) dp[i][j] = true;
                else if(k < 2 && s[i] == s[j]){
                    start_idx = i;
                    max_len = 2;
                    dp[i][j] = true;
                }
                else{
                    if(s[i] == s[j] && dp[i+1][j-1]){
                        dp[i][j] = true;
                        if(k+1 > max_len){
                            max_len = k+1;
                            start_idx = i;
                        }
                    }
                }
            }
        }
        // for(auto v : dp){ for(auto el : v) cout<<el<<" "; cout<<endl; }
        
        return s.substr(start_idx, max_len);
    }
};