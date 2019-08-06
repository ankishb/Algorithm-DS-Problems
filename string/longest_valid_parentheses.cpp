
class Solution {
public:
    int longestValidParentheses(string str) {
        int count = 0;
        int max_len = 0;
        stack<int> s;
        int n = str.length();
        for(int i=0; i<n; i++){
        	if(!s.empty() && str[i] == ')' && s.top()=='('){
        		s.pop();
        		count += 2;
                
        	}
        	else{
        		s.push(str[i]);
        	}
        }
        return count;
    }
};