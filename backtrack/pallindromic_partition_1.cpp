
class Solution {
public:
    vector<vector<string>> store;
    vector<string> cur;
    
    bool is_pallindrome(string s, int low, int high){
        while(low < high){
            if(s[low++] != s[high--]) return false;
        }
        return true;
    }
    
    void helper(string s, int idx){
        int n = s.length();
        if(idx == n){
            store.push_back(cur);
            return ;
        }
        for(int i=idx; i<n; i++){
            if(is_pallindrome(s, idx, i)){
                cur.push_back(s.substr(idx, i-idx+1));
                helper(s, i+1);
                cur.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        helper(s, 0);
        return store;
    }
};