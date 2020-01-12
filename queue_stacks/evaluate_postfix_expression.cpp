
class Solution {
public:
    bool is_op(string s){
        return (s == "+" || s == "-"
             || s == "*" || s == "/");
    }
    int evaluate(int a, int b, string s){
        if(s == "+") return a + b;
        if(s == "-") return a - b;
        if(s == "*") return a * b;
        if(s == "/") return a / b;
        return 0;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        int a, b, c;
        for(auto s : tokens){
            if(is_op(s) && nums.size() >= 2){
                b = nums.top(); nums.pop();
                a = nums.top(); nums.pop();
                c = evaluate(a, b, s);
                nums.push(c);
            }
            if(!is_op(s)){
                a = stoi(s);
                nums.push(a);
            }
        }
        return nums.top();
    }
};