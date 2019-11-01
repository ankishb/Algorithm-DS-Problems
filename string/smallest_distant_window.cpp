
int smallest_window(string s){
    unordered_set<char> uni;
    for(auto ch : s) uni.insert(ch);
    int n = s.length(), m = uni.size();
    uni.clear();
    unordered_map<char, int> freq;
    int i = 0, j = 0, len = n;
    for(j=0; j<n; j++){
        freq[s[j]]++;
        if(freq.size() == m){
            while(i <= j && freq[s[i]] > 1){
                freq[s[i]]--;
                i++;
            }
            len = min(len, j-i+1);
        }
    }
    return len;
}