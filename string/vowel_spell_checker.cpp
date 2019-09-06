class Solution {
public:
    bool isvowel(char ch){
        ch = tolower(ch);
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') return true;
        return false;
    }
    
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> bucket[26], ans;
        for(auto s : wordlist){
            if(isvowel(s[0])) bucket[0].push_back(s);
            else bucket[tolower(s[0])-'a'].push_back(s);
        }
        // exception, if first character of query is missing
        for(auto q : queries){
            vector<string> subset;
            if(isvowel(q[0])) subset = bucket[0];
            else subset = bucket[tolower(q[0])-'a'];
            if(subset.size() == 0){
                ans.push_back("");
                continue;
            }
            // first check if same(case sensitive) word exist
            bool found_all = false;
            for(auto s : subset){
                if(s == q){ 
                    found_all = true; 
                    ans.push_back(s);
                    break; 
                }
            }
            if(found_all) continue;
            // search for other two cases
            // 1. captalization
            // 2. Vowel match
            bool found_cap = false;
            for(auto s : subset){
                if(s.length() != q.length()) continue;
                int i;
                for(i=0; i<s.length(); i++){
                    if(tolower(s[i]) == tolower(q[i])) continue;
                    // else if(isvowel(s[i]) && isvowel(q[i])) continue;
                    else{
                        break;
                    }
                }
                if(i == s.length()){
                    found_cap = true;
                    ans.push_back(s);
                    break;
                }
            }
            if(found_cap) continue;
            bool found_vowel = false;
            for(auto s : subset){
                if(s.length() != q.length()) continue;
                int i;
                for(i=0; i<s.length(); i++){
                    // if(tolower(s[i]) == tolower(q[i])) continue;
                    if(tolower(s[i]) == tolower(q[i]) 
                       || isvowel(s[i]) && isvowel(q[i])) continue;
                    else{
                        break;
                    }
                }
                if(i == s.length()){
                    found_vowel = true;
                    ans.push_back(s);
                    break;
                }
            }
            if(!found_vowel) ans.push_back("");
        }
        return ans;
    }
};