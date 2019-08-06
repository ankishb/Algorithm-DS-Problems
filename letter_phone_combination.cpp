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