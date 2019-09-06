class Solution {
public:
    void helper(vector<string> &store, string s, int idx){
        if(idx > s.length()) return;
        if(idx == s.length()){
            store.push_back(s);
            return;
        }
        // don't do anything
        helper(store, s, idx+1);
        // if alphabet, toggle its state
        if(isalpha(s[idx])){
            s[idx] = islower(s[idx]) ? toupper(s[idx]) : tolower(s[idx]);
            // s[idx] ^= (1 << 5);
            helper(store, s, idx+1);
        }
    }
    
    vector<string> letterCasePermutation1(string s) {
        vector<string> store;
        helper(store, s, 0);
        return store;
    }
    vector<string> letterCasePermutation1(string s_) {
        // vector<string> ans({s_});
        queue<string> ans;
        ans.push(s_);
        int n = s_.length();
        string s, s_new;
        for(int j=0; j<n; j++){
            for(int i=0; i<ans.size(); i++){
                s = ans[i];
                if(isalpha(s[j])){
                    s_new = s;
                    s_new[j] ^= (1 << 5);
                    cout<<s_new<<" ";
                    ans.push_back(s_new);
                }
            }
        }
        
        return ans;
    }
};