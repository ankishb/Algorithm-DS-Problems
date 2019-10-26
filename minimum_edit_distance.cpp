
 /*To get the character detail, which is replaced, deleted and all that
int get_min_cost(string s1, string s2, int c1, int c2){
    int n1 = s1.length();
    int n2 = s2.length();
    vii dp(n1+1, vi(n2+1,0));
    for(int i=0; i<=n1; i++) dp[i][0] = i;
    for(int i=0; i<=n2; i++) dp[0][i] = i;
    for(int i=1; i<=n1; i++){
        for(int j=1; j<=n2; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1+min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            }
        }
    }
    // collect cost by tranversing from back
    
    // 1. if s1[i] == s2[j], go left diag, no cost
    // 2. else
    //     1. if comes from left, delete s2[j]
    //     2. if comes from up, delete s1[i]
    //     3. if comes from left diag, delete both s1[i], s2[i]
    
    int i = n1, j = n2, cost = 0;
    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            i--; j--;
        }
        else if(dp[i][j] == 1+dp[i-1][j-1]){
            cost += (c1 + c2);
            i--; j--;
        }
        else if(dp[i][j] == 1+dp[i-1][j]){
            cost += c1; // delete s1[i]
            i--;
        }
        else if(dp[i][j] == 1+dp[i][j-1]){
            cost += c2;
            j--;
        }
    }
    return cost;
}
*/


// new try
/* There are 3 operation to take care:
1. Insert  : It involves adding a character(not much imp for us)
2. Delete  : We can either delete from s1 or s2. So check which gives min
3. Replace : Replace one chacter with another, if don't match

So in concise:
1. If current character i & j match, check for min-op for one less char
2. If don't match, we do following
    1. either replace
    2. or delete ith char from s1
    3. or delete jth char from s2

Note that, cur sol has memory complexity: O(n1*n2), 
    but it can be done in O(n2). As, at each cell, we need
    only three cell(left, up, left diag) to make decision

*/
class Solution {
public:
    int minDistance(string w1, string w2) {
        int n1 = w1.size(), n2 = w2.size();
        if(n1 == 0 && n2 == 0) return 0;
        if(n1 == 0 || n2 == 0) return (n1==0)?n2:n1;
        vector<vector<int>> dp(n1+1, vector<int>(n2+1));
        for(int i=0; i<=n1; i++) dp[i][0] = i;
        for(int j=0; j<=n2; j++) dp[0][j] = j;
        
        int wi, wj;
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                wi = i-1;
                wj = j-1;
                if(w1[wi] == w2[wj]) dp[i][j] = dp[i-1][j-1];
                else{
                    dp[i][j] = min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
                    dp[i][j] += 1;
                }
            }
        }
        return dp[n1][n2];
    }
};


int Solution::minDistance(string s1, string s2) {
    int n1 = s1.length(), n2 = s2.length();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
    for(int i=0; i<=n1; i++){
        for(int j=0; j<=n2; j++){
            if(i == 0) dp[i][j] = j;
            else if(j == 0) dp[i][j] = i;
            else if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1+min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            }
        }
    }
    return dp[n1][n2];
}


// old one
/*
1. If s1[i] == s2[j], edit-dist = dp[i-1][j-1]
2. else either we replace chacter or we delete it.
    Now to check minimum steps, we check:
    1. min steps if we delete s1[i]: dp[i-1][j]
    2. min steps if we delete s2[j]: dp[i][j-1]
    3. min steps if we replace it  : dp[i-1][j-1]
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        if(n == 0 && m == 0) return 0;
        if(n == 0) return m;
        if(m == 0) return n;
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        for(int i=0; i<=n; i++) dp[i][0] = i;
        for(int j=0; j<=m; j++) dp[0][j] = j;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                    dp[i][j] += 1;
                }
            }
        }
        // for(auto v : dp){
        //     for(auto el : v) cout<<el<<" "; cout<<endl;
        // }
        return dp[n][m];
    }
};






// another Light-weight Solution

int Solution::minDistance(string A, string B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int lengthA = A.length();
    int lengthB = B.length();
    
    if (lengthA == 0 || lengthB == 0)
    {
        return max(lengthA, lengthB);
    }
    
    vector<int> cache(lengthB + 1);
    for (int i = 0; i <= lengthB; i++)
    {
        cache[i] = i;
    }
    
    int lastImpNo;
    for (int i = 1; i <= lengthA; i++)
    {
        lastImpNo = cache[0];
        cache[0] = i;
        for (int j = 1; j <= lengthB; j++)
        {
            int oldVal = cache[j];
            
            if (A[i - 1] == B[j - 1])
            {
                cache[j] = lastImpNo;
            }
            else
            {
                cache[j] = min(min(lastImpNo, cache[j - 1]), cache[j]) + 1;
            }
            
            lastImpNo = oldVal;
        }
    }
    
    return cache[lengthB];
}

