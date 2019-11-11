
string max_len_pallindrome(string s){
    int n = s.length();
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    int idx = 0, len = 0;
    for(int k=0; k<n; k++){
        for(int i=0; i<n-k; i++){
            int j = i+k;
            if(i == j) dp[i][j] = 1;
            else if(k == 1){
                if(s[i] == s[j]) dp[i][j] = 2;
                else dp[i][j] = 1;
            }
            else{
                if(s[i] == s[j] && s[i+1] == s[j-1] && dp[i+1][j-1] > 0){
                    dp[i][j] = 2 + dp[i+1][j-1];
                }
                // else{
                //     dp[i][j] = max({dp[i][j], dp[i+1][j], dp[i][j-1]});
                // }
                
            }
            if(dp[i][j] > len){
                len = dp[i][j];
                idx = i;
            }
        }
    }
    return s.substr(idx, len);
}



// new try
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(), len = 1, idx = 0;
        if(n == 0) return "";
        vector<vector<bool>> dp(n, vector<bool>(n,false));
        for(int i=0; i<n; i++) dp[i][i] = 1;
        for(int k=2; k<=n; k++){
            for(int i=0; i<n-k+1; i++){
                int j = i+k-1;
                if(k == 2 && s[i] == s[j]){
                    dp[i][j] = true;
                    if(len < k){
                        len = k;
                        idx = i;
                    }
                }
                else if(k > 2 && s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                    if(len < k){
                        len = k;
                        idx = i;
                    }
                }
            }
        }
        return (len==1)?s.substr(0,1):s.substr(idx, len);
    }
};

// old one
string Solution::longestPalindrome(string s){
    int n = s.length();
    if(n < 1) return "";
    int max_len = 1, idx = 0;
    vector<vector<bool>> dp(n, vector<bool>(n,false));
    for(int k=0; k<n; k++){
        for(int i=0; i<n-k; i++){
            int j = i+k;
            if(k == 0) dp[i][i] = true;
            else if(k == 1 && s[i] == s[j]){
                dp[i][j] = true;
                if(k+1 > max_len){
                    max_len = k+1; 
                    idx = i;
                }
            }
            else{
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                    if(k+1 > max_len){
                        max_len = k+1; 
                        idx = i;
                    }
                }
            }
        }
    }
    return s.substr(idx, max_len);
}

/* 
substring can be odd or even length.
1. At each index, find two substring for both case(odd and even)
2. Also track maximum length substring
*/
string expandAroundCenter(string s, int c1, int c2) {
    int l = c1, r = c2;
    int n = s.length();
    while (l >= 0 && r <= n-1 && s[l] == s[r]) {
        l--;
        r++;
    }
    return s.substr(l+1, r-l-1);
}

string longestPalindrome(string s) {
    int n = s.length();
    if (n == 0) return "";
    string longest = s.substr(0, 1);  // a single char itself is a palindrome
    for (int i = 0; i < n-1; i++) {
        string p1 = expandAroundCenter(s, i, i);
        if (p1.length() > longest.length())
            longest = p1;

        string p2 = expandAroundCenter(s, i, i+1);
        if (p2.length() > longest.length())
            longest = p2;
    }
    return longest;
}




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
