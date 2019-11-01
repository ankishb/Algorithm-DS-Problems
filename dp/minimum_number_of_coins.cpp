#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vii vector<vector<int>>
#define f first
#define s second
#define ll long long int 

/*
3
7 2
2 1
7540 46
13 96 38 43 17 31 53 85 59 87 22 100 12 24 63 79 36 93 73 14 34 54 3 95 46 15 40 88 58 81 99 51 35 11 41 55 42 97 10 77 48 16 44 76 18 84
8777 5
86 7 43 67 6

Its Correct output is:
4
76
103
*/

// creat a signature function here
int min_coins(vector<int> A, int sum){
    int n = A.size();
    const int inf = 1e9;
    sort(A.begin(), A.end());
    vector<int> dp(sum+1, 0);
    for(int i=1; i<=sum; i++){
        if(i%A[0] == 0) dp[i] = i/A[0];
        else dp[i] = inf;
    }
    for(int i=1; i<n; i++){
        for(int j=A[i]; j<=sum; j++){
            if(j%A[i] == 0) dp[j] = j/A[i];
            else dp[j] = min(dp[j], 1+dp[j-A[i]]);
        }
    }
    return (dp[sum] == inf) ? -1 : dp[sum];
}

int min_coins2(vector<int> A, int sum){
    int n = A.size();
    sort(A.begin(), A.end());
    vector<int> cur(sum+1, 0), prev(sum+1, 0);
    for(int i=1; i<=sum; i++){
        if(i%A[0] == 0) prev[i] = i/A[0];
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<=sum; j++){
            if(j < A[i]){
                cur[j] = prev[j];
                continue;
            }
            if(j%A[i] == 0) cur[j] = j/A[i];
            else if(cur[j-A[i]] == 0){
                if(prev[j] == 0) cur[j] = 0;
                else cur[j] = prev[j];
            }
            else{
                cur[j] = 1 + cur[j-A[i]];
                if(prev[j] != 0) cur[j] = min(cur[j], prev[j]);
            }
        }
        prev = cur;
        cur.resize(sum+1, 0);
    }
    if(prev.back() == 0) return -1;
    return prev.back();
}


int main()
 {
    int test;
    cin>>test;
    while(test--){
        // input and call signature function
        int sum, n;
        cin>>sum>>n;
        vector<int> A(n);
        for(int i=0; i<n; i++){
            cin>>A[i];
        }
        cout<<min_coins(A, sum)<<endl;
    }
    return 0;
}