
// new try
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length(), count = n;
        if(n == 0) return 0;
        vector<vector<bool>> dp(n, vector<bool>(n,false));
        for(int i=0; i<n; i++) dp[i][i] = 1;
        for(int k=2; k<=n; k++){
            for(int i=0; i<n-k+1; i++){
                int j = i+k-1;
                if(k == 2 && s[i] == s[j]){
                    dp[i][j] = true;
                    count++;
                }
                else if(k > 2 && s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                    count++;
                }
            }
        }
        return count;
    }
};



// old one
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int count = 0;
        int j;
        for(int k=0; k<n; k++){
            for(int i=0; i<n-k; i++){
                j = i+k;
                if(i==j){
                    count++; 
                    dp[i][j] = true;
                }
                else{
                    if(s[i]==s[j] && (i+1==j || dp[i+1][j-1])){
                        dp[i][j] = true;
                        count++;
                    }
                }
            }
        }
        return count;
    }
};




/* an elegant solution
The idea is count the no of different palindromic substrings from their respective middle.

1. When substring can of even len: 
    consider substring s[i-j, ..., i+j], where i is the middle
1. When substring can of odd len: 
    consider substring s[i-1-j, ..., i+j], where both (i-1, i) are middle indices
*/
    int countSubstrings(string s) {
        int res = 0, n = s.length();
        for(int i = 0; i < n; i++){
            for(int j = 0; i-j >= 0 && i+j < n && s[i-j] == s[i+j]; j++)res++; //substring s[i-j, ..., i+j]
            for(int j = 0; i-1-j >= 0 && i+j < n && s[i-1-j] == s[i+j]; j++)res++; //substring s[i-1-j, ..., i+j]
        }
        return res;
    }

