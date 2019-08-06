class Solution {
public:
    bool parseBoolExpr(string str) {
        reverse(str.begin(), str.end());
        stack<char> s;
        int i = 0;
        char top;
        bool ans = 0;
        int n = str.length();
        for(int i=0; i<n; i++){
            if(str[i] == '(') str[i] = ')';
            else if(str[i] == ')') str[i] = '(';
        }
        while(i<n){
            if(str[i] == ','){
                i++;
                continue;
            }
            cout<<str[i]<<" ";
            if(str[i] == '('){
                s.push(str[i]);
            }
            else if(str[i] == ')'){
                // we run the operation that is just outside the bracket
                if(str[i+1] == '!'){
                    ans = ((s.top()=='f')?1:0);
                }
                else if(str[i+1] == '|'){
                    top = 0;
                    while(s.top() != '('){
                        top = ((s.top()=='f')?0:1)|top;
                        s.pop();
                    }
                    ans = top;
                }
                else if(str[i+1] == '&'){
                    top = 1;
                    while(s.top() != '('){
                        top = ((s.top()=='f')?0:1)&top;
                        s.pop();
                    }
                    ans = top;
                }
                s.pop();
                s.push((ans==0)?'f':'t');
                cout<<s.top()<<" -- ";
                i++;
            }
        else{
            s.push(str[i]);
        }
            i++;
        }
        return (s.top()=='f')?false:true;
    }
};










class Solution {
public:
    bool f_not(const string& s,int& i){
        i+=2;
        auto ret = f(s,i);
        i++;
        return !ret;
    }
    
    bool f_and(const string& s,int& i){
        i+=2;
        bool ret = true;
        ret &= f(s,i);
        while(s[i]!=')'){
            i++;
            ret &= f(s,i);
        }
        i++;
        return ret;
    }
    
    bool f_or(const string& s,int& i){
        i+=2;
        bool ret = false;
        ret |= f(s,i);
        while(s[i]!=')'){
            i++;
            ret |= f(s,i);
        }
        i++;
        return ret;
    }
    
    bool f(const string& s, int& i){
        if(s[i] == 't'){
            i++;
            return true;
        } else if(s[i] == 'f'){
            i++;
            return false;
        } else if(s[i] == '!'){
            return f_not(s,i);
        } else if(s[i] == '&'){
            return f_and(s,i);
        } return f_or(s,i);
    }
    bool parseBoolExpr(string expression) {
        int i = 0;
        return f(expression,i);
    }
};







#include <bits/stdc++.h>
class Solution 
{
public:
    bool parseBoolExpr(string exp) 
    {
        int n = exp.size();
        vector<char> ev;
        for(int i = 0; i < n; i++)
        {
            if(exp[i] != ',')
            {
                ev.push_back(exp[i]);
            }
        }
        
        n = ev.size();
        deque<char> res;
        for(int i = 0; i < n; i++)
        {
            if(ev[i] != ')')
            {
                res.push_back(ev[i]);
            }
            else
            {
                deque<char> eval_stk; // stack stored for evaluation   
                while(res.size() && res.back() != '&' && res.back() != '|' && res.back() != '!') // push back the operands
                {
                    cout << "res_back " << res.back() << '\n';
                    if(res.back() == 't' || res.back() == 'f')
                    {
                        eval_stk.push_back(res.back());
                    }
                    res.pop_back();
                }
                
                char op = res.back(); // get operator
                res.pop_back(); // pop that operator out
                bool on = (eval_stk.back() == 't') ? 1 : 0; // first answer
                cout <<"on " << on << " op " << op << "res.size() " << res.size() << '\n';
                
                if(op == '|') // or operator
                {
                    while(eval_stk.size())
                    {
                        if((eval_stk.back() == 't'))
                        {
                            on |= 1; // early stopping if encounter OR 1
                            break;
                        }
                        else
                        {
                            on |= 0;
                        }
                        eval_stk.pop_back();
                    }
                }
                else if(op == '&') // and operator
                {
                    while(eval_stk.size())
                    {
                        if((eval_stk.back() == 't'))
                        {
                            on &= 1;
                        }
                        else
                        {
                            on &= 0; // early stopping if encounter AND 0
                            break;
                        }
                        eval_stk.pop_back();
                    }
                }
                else if(op == '!')
                {
                    on ^= 1; // toggle the boolean result
                }
                res.push_back((on == 1) ? 't' : 'f');
            }
        }
        
        return (res.back() == 't') ? 1 : 0;
    }
};








The idea is to push operators(!, &, |) in a stack and values (t, (, f) in a different stack. For each ')', we pop the operator and based on the operator popped keep popping values and perform the operation. Push back the final result into the value stack.

bool parseBoolExpr(string expr) {
    stack<char> val, op;
    for (char ch : expr) {
        if (ch == 't' || ch == 'f' || ch == '(') val.push(ch);
        else if (ch == '&' || ch == '|' || ch == '!') op.push(ch);
        else if (ch == ')') {
            char p = op.top(); op.pop();
            bool v = (val.top() == 't'); val.pop(); // Here we are directly using true or false values instead of characters 't' or 'f'
            if (p == '!')
                v = !v; // Negate the value for ! operator
            while (val.top() != '(') { // Keep popping the values till the top element is (
                if (p == '&') v = v && (val.top() == 't');
                else v = v || (val.top() == 't');
                val.pop();
            }
            val.pop(); // This pop is needed to pop the (
            val.push(v ? 't' : 'f'); // Store the result back in value stack - The result must be converted back to character 't' or 'f'
        }
    }
    return val.top() == 't'; // Return the final result by converting it to a bool value
}
