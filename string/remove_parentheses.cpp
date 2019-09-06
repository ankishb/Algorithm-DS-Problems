class Solution {
public:
    string removeOuterParentheses(string S) {
        int opened = 0;
        string ans = "";
        for(auto ch : S){
            if(ch == '(') opened++;
            if(ch == ')') opened--;
            if(ch == '(' && opened > 1) ans += ch;
            if(ch == ')' && opened > 0) ans += ch;
        }
        return ans;
    }
};