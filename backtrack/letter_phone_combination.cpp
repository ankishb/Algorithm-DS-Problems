
// new one (iterative approach)
class Solution {
public:
    vector<string> letterCombinations(string s) {
        unordered_map<char, string> map({
                {'2', "abc"},
                {'3', "def"},
                {'4', "ghi"},
                {'5', "jkl"},
                {'6', "mno"},
                {'7', "pqrs"},
                {'8', "tuv"},
                {'9', "wxyz"}
        });
        int n = s.length();
        vector<string> store, cur;
        for(int i=0; i<n; i++){
                string map_s = map[s[i]];
                int map_n = map_s.length();
                int store_n = store.size();
                for(int l=0; l<map_n; l++){
                        if(store_n == 0){
                                string temp = string(1, map_s[l]);
                                cur.push_back(temp);
                                continue;
                        }
                        for(int k=0; k<store_n; k++){
                                cur.push_back(store[k]+map_s[l]);
                        }
                }
                // store.clear();
                store = cur;
                cur.clear();
        }
        sort(store.begin(), store.end());
        return store;
    }
};



class Solution {
public:   
    string get_string(vector<char> cur){
        string ans = "";
        for(int i=0; i<cur.size(); i++){
            ans += cur[i];
        }
        return ans;
    }
    void helper(string digits, int i, vector<string>&store, string cur){
        int n = digits.length();
        if(cur.length() == n){
            // string temp = get_string(cur);
            store.push_back(cur);
            return;
        }
        unordered_map<char, string> my_map;
        // my_map['0'] = "0";
        // my_map['1'] = "1";
        my_map['2'] = "abc";
        my_map['3'] = "def";
        my_map['4'] = "ghi";
        my_map['5'] = "jkl";
        my_map['6'] = "mno";
        my_map['7'] = "pqrs";
        my_map['8'] = "tuv";
        my_map['9'] = "wxyz";
        
        string new_ = my_map[digits[i]];
        for(int id=0; id<new_.length(); id++){
            // cur.push_back(new_[id]);
            helper(digits, i+1, store, cur+new_[id]);
            // cur.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {    
        int n = digits.length();
        vector<string> store;
        // vector<char> cur;
        string cur = "";
        if(n == 0) return store;
        helper(digits, 0, store, cur);        

        return store;
    }
};