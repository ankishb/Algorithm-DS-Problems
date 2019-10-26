
int count_min_steps(string s1, string s2, int n){
    unordered_map<char, int> freq;
    for(auto ch : s1){
        freq[ch]++;
    }
    for(auto ch : s2){
        freq[ch]--;
    }
    int count = 0;
    for(auto itr : freq){
        count += abs(itr.second);
    }
    return count/2;
}