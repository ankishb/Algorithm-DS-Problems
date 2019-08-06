
class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.length(), m=p.length();
        // if(row==0 && col==0) return true;
        // else if(row==0 && col>0) return false;
        // else if(row>0 && col==0) return true;
        
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;
        for(int j=1; j<m+1; j++){
            if(p[j-1]=='*') dp[0][j]=true;
            else break;
        }
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if((s[i-1]==p[j-1] || p[j-1]=='?')){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*'){
                    dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
                }
            }
        }
        
        // for(auto itr1 : dp){
        //     for(auto itr2 : itr1) cout<<itr2<<" ";
        //     cout<<endl;
        // }
        return dp[n][m];
    }
};




/*
My three C++ solutions (iterative (16ms) & DP (180ms) & modified recursion (88ms))
37
dong.wang.1694's avatar
dong.wang.1694
2339

Last Edit: September 13, 2018 4:35 AM

13.7K VIEWS

The reason that the iterative solution is much faster for this case is we only need to save (and deal with) the positions (iStar for s, jStar for p) of the last "" we met. We only need to do traceback using iStar and jStar and all the previous "" can be ignored since the last "" will cover all the traceback cases for the previous "".
What we need to do are

    if the current p character is '' (i.e. p[j]==''), then we update iStar and jStar with the cureent i and j values. iStar/jStar will be used for traceback. Also we do --i to start the depth first search with the case that '*' represents a null string.
    if p[j]!='', then we check if mismatch occurs (i.e. p[j]!=s[i] and p[j]!='?'), if so we check if we met a '' before (iStar>=0), if not, then we return false since no match can achieve. Otherwise, we traceback to the positions at which the last '*' happens and do the next possible dfs search (i.e. i = iStar++; j = jStar; remember to update iStar too to save the i position to try in the next traceback).
    The loop will quit when we reach the end of s. At last, we need to skip all the '*' in p to see if we can reach the end of p. if so, match, otherwise mismatch

class Solution {
public:
    bool isMatch(string s, string p) {
        int  slen = s.size(), plen = p.size(), i, j, iStar=-1, jStar=-1;

        for(i=0,j=0 ; i<slen; ++i, ++j)
        {
            if(p[j]=='*')
            { //meet a new '*', update traceback i/j info
                iStar = i;
                jStar = j;
                --i;
            }
            else
            { 
                if(p[j]!=s[i] && p[j]!='?')
                {  // mismatch happens
                    if(iStar >=0)
                    { // met a '*' before, then do traceback
                        i = iStar++;
                        j = jStar;
                    }
                    else return false; // otherwise fail
                }
            }
        }
        while(p[j]=='*') ++j;
        return j==plen;
    }
};

A DP solution is also given here. It has O(N^2) time complexity and O(N) space

class Solution {
public:
    bool isMatch(string s, string p) {
        int pLen = p.size(), sLen = s.size(), i, j, k, cur, prev;
        if(!pLen) return sLen == 0;
        bool matched[2][sLen+1];
        fill_n(&matched[0][0], 2*(sLen+1), false);
        
        matched[0][0] = true;
        for(i=1; i<=pLen; ++i)
        {
            cur = i%2, prev= 1-cur;
            matched[cur][0]= matched[prev][0] && p[i-1]=='*';
            if(p[i-1]=='*') for(j=1; j<=sLen; ++j) matched[cur][j] = matched[cur][j-1] || matched[prev][j];
            else for(j=1; j<=sLen; ++j)            matched[cur][j] =  matched[prev][j-1] && (p[i-1]=='?' || p[i-1]==s[j-1]) ;
        }
            return matched[cur][sLen];
    }
};

*/