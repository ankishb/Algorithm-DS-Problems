





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



// another elegant solution
/*
The idea is count the number of different palindromic substrings from their respective middle.

In the following code, when we consider the substring s[i-j, ..., i+j], i is the middle index of the substring; When we consider the substring s[i-1-j, ..., i+j], (i-1, i) is the middle index of the substring.

C++ version:
*/
    int countSubstrings(string s) {
        int res = 0, n = s.length();
        for(int i = 0; i < n; i++){
            for(int j = 0; i-j >= 0 && i+j < n && s[i-j] == s[i+j]; j++)res++; //substring s[i-j, ..., i+j]
            for(int j = 0; i-1-j >= 0 && i+j < n && s[i-1-j] == s[i+j]; j++)res++; //substring s[i-1-j, ..., i+j]
        }
        return res;
    }

