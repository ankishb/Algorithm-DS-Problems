
/*
In lower-case and upper-case, there is diff of 32 number,
which can be represent as 100000(2^5), which can be 
written as (1 << 5), so only operation need is Xor as

    ch ^= (1 << 5); lower->upper || upper->lower

*/
class Solution {
public:
    vector<string> simple_sol(string s) {
        int n = s.length();
        // if(n == 0) return {""};
        vector<string> ans({s});
        // ans.push_back(s);
        for(int i=0; i<n; i++){
            if(s[i] >= '0' && s[i] <= '9') continue;
            int m = ans.size();
            for(int j=0; j<m; j++){
                string s_new = ans[j];
                if(s_new[i] >= 'a' && s_new[i] <= 'z'){
                    s_new[i] = toupper(s_new[i]);
                }
                else if(s_new[i] >= 'A' && s_new[i] <= 'Z'){
                    s_new[i] = tolower(s_new[i]);
                }
                ans.push_back(s_new);
            }
        }
        return ans;
    }
    
    vector<string> store;
    void recusion(string s, int idx){
        if(idx > s.length()) return;
        if(idx == s.length()){
            store.push_back(s);
            return;
        }
        // don't do anything
        recusion(s, idx+1);
        // if alphabet, toggle its state
        if(isalpha(s[idx])){
            s[idx] = islower(s[idx]) ? toupper(s[idx]) : tolower(s[idx]);
            // s[idx] ^= (1 << 5);
            recusion(s, idx+1);
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        // recusion(s, 0);
        // return store;
        // return bit_manipulation(s);
        return simple_sol(s);
    }
    vector<string> bit_manipulation(string s_) {
        vector<string> ans({s_});
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