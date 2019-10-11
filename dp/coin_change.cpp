
/* We need to number of possible sets, whose sum will be given number(k)
There are four possibilities to consider
1. If we have just one coin, then either we can make it or we not
2. If the current coin is greater than sum, just continue
3. if cur_coin is a multiple of cur_sum, then we can make 1 more case
4. If cur_coin > cur_sum, we check number of possiblities for 
    the remaining sum(after including current one)
*/
long new_sol(vector<long> c, int k){
    int n = c.size();
    vector<long> dp(k,0);
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            if(i == 0) dp[j] = ((j+1)%c[i] == 0) ? 1 : 0;
            else if((j+1) < c[i]) continue;
            else if(c[i]%(j+1) == 0) dp[j] = dp[j] + 1;
            else dp[j] = dp[j] + dp[j-c[i]];
        }
    }
    // for(auto el : dp) cout<<el<<" "; cout<<endl;
    return dp[k-1];
}


/*
In the following solution, we need to tackle the starting point 
to save some edge cases
    1. If we start from j=1----k, then it may cause some weirdness,
        for coins starting from {2---}, as [1-2 = -1], it overlook
        in the memory.(So start with first coin to handle it.)
    2. Init 0th place with 1.
*/
long new_sol2(vector<long> c, int k){
    int n = c.size();
    vector<long> dp(k+1,0);
    dp[0] = 1;
    for(int i=0; i<n; i++){
        for(int j=c[i]; j<=k; j++){
            dp[j] = dp[j] + dp[j-c[i]];
        }
    }
    for(auto el : dp) cout<<el<<" "; cout<<endl;
    return dp[k];
}


// recursive solution (to get all possible cases)
#include <bits/stdc++.h>
using namespace std;

class solution{
public:
    int count = 0;
    vector<int> cur;

    void count_poss(vector<int> coins, int k, int cur_sum){
        if(cur_sum > k) return;
        if(cur_sum == k){
            count++;
            return;
        }
        int n = coins.size();
        for(int i=0; i<n; i++){
            if(cur.size() == 0){
                cur.push_back(coins[i]);
                count_poss(coins, k, cur_sum+coins[i]);
                cur.pop_back();
            }
            else if(cur.back() <= coins[i]){
                cur.push_back(coins[i]);
                count_poss(coins, k, cur_sum+coins[i]);
                cur.pop_back();
            }
        }
    }
};

int main()
{
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        vector<int> coins(n);
        for(int i=0; i<n; i++){
            cin>>coins[i];
        }
        int k; 
        cin>>k;
        
        sort(coins.begin(), coins.end());
        solution s;
        s.count = 0;
        s.count_poss(coins, k, 0);
        cout<<s.count<<endl;
    }
    return 0;
}



long optimized1(int k, vector<long> c){
    int n = c.size();
    vector<vector<long>> dp(n, vector<long>(k,0));
    // fill first row
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            if(i == 0) dp[i][j] = ((j+1) % c[i] == 0) ? 1 : 0;
            else{
                if((j+1) < c[i]) dp[i][j] = dp[i-1][j];
                else if((j+1) == c[i]) dp[i][j] = 1 + dp[i-1][j];
                else{
                    dp[i][j] = dp[i][j-c[i]] + dp[i-1][j];
                }
            } 
        }
    }
    return dp[n-1][k-1];
}

long optimized2(int k, vector<long> c){
    int n = c.size();
    vector<long> dp(k,0);
    // fill first row
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            if(i == 0) dp[j] = ((j+1) % c[i] == 0) ? 1 : 0;
            else{
                if((j+1) < c[i]) dp[j] = dp[j];
                else if((j+1) == c[i]) dp[j] += 1;
                else{
                    dp[j] += dp[j-c[i]];
                }
            } 
        }
    }
    return dp[k-1];
}

long getWays(int k, vector<long> c) {
    // return optimized1(k, c);
    return optimized2(k, c);
}