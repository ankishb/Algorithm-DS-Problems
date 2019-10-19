
string pangrams(string s) {
    bool hash[26] = {0};
    for(auto ch : s){
        if(ch >= 'a' && ch <= 'z'){
            hash[ch-'a'] = 1;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            hash[ch-'A'] = 1;
        }
    }
    for(int i=0; i<26; i++){
        if(hash[i] == 0) return "not pangram";
    }
    return "pangram";
}