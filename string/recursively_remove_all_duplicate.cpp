string remove_duplicate(string s){
    int n = s.length();
    for(int k=0; k<n; k++){
        bool flag = false;
        int i = 0, j;
        string ans = "";
        n = s.length();
        while(i < n){
            int j = i;
            while(j < n && s[j] == s[i]) j++;
            if(j-i == 1){
                ans += s[i];
                flag = true;
            }
            i = j;
        }
        s = ans;
        if(!flag) break;
        // cout << ans << " ";
    }
    return s;
}