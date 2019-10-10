bool helper(string A, int idx, unordered_set<string> set){
    int n = A.length();
    if(idx == n) return true;
    string s = "";
    for(int i=idx; i<n; i++){
        s += A[i];
        if((set.find(s) != set.end()) 
        && helper(A, i+1, set)) return true;
    }
    return false;
}

bool optimal(string s, unordered_set<string> set){
    int n = s.length(); 
    if(n == 0) return true; 
    vector<bool> dp(n+1, false);
    string sub;
    for (int i=1; i<=n; i++) { 
        sub = s.substr(0, i);
        if(dp[i] == false && (set.find(sub) != set.end())){
            dp[i] = true;
        }
        if(dp[i] == false) continue;
        // else we need to check all the cases in [i+1, n]
        if(i == n) return true;
        for(int j=i+1; j<=n; j++){
            sub = s.substr(i, j-i);
            if(dp[j] == false && (set.find(sub) != set.end())){
                dp[j] = true;
            }
            if(dp[j] == true && j == n) return true;
        }
    }
    return false;
}

bool optimal2(string s, unordered_set<string> set){
    int n = s.length();
    vector<bool> dp(n, false);
    for(int i=0; i<n; i++) {
        if (set.find(s.substr(0,i+1)) != set.end()) {
            dp[i] = true;
        } 
        else{
            for (int j=i-1; j>=0; j--) {
                if(dp[j] && set.find(s.substr(j+1, i+1)) != set.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
    }
    return (dp[n-1]) ? 1 : 0;
}

int Solution::wordBreak(string A, vector<string> &B) {
    unordered_set<string> set;
    for(auto a : B){
        set.insert(a);
    }
    // return helper(A, 0, set);
    return optimal2(A, set);
}
