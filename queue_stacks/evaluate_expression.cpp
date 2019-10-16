#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

bool is_op(char ch){
    return (ch=='+' || ch=='/' || ch=='-' || ch=='*');
}
bool is_digit(char ch){
    return (ch >= '0' && ch <= '9');
}

/*
1. Take care spaces
2. Take care multiple digit number
3. take care -ve number (edge case)
*/
int main() {
    string s;
    getline(cin, s);
    stack<char> op;
    stack<double> nos;
    double a, b, c;
    int i=0, n = s.length();
    while(i < n){
        if(s[i] == ' ' || s[i] == '('){
            i++;
            continue;
        }
        if(is_op(s[i])){
            // an exception case for '-' as there can be "(-2)"
            if(s[i] == '-' && i > 0 && s[i-1] == '('){
                nos.push(0);
            }
            op.push(s[i]);
        }
        else if(is_digit(s[i])){
            string number = "";
            while(i<n && is_digit(s[i])){
                number += s[i];
                i++;
            }
            i--; // as i is also increased at the end of loop
            nos.push((double)(stoi(number)));
            // cout<<number<<" ";
        }
        else if(s[i] == ')'){
            if(nos.size() < 2){
                cout<<"ERROR\n";
                return 0;
            }
            else{
                a = nos.top(); nos.pop();
                b = nos.top(); nos.pop();
                if(op.top() == '+') c = b+a;
                if(op.top() == '-') c = b-a;
                if(op.top() == '*') c = b*a;
                if(op.top() == '/'){
                    if(a == 0){
                        cout<<"ERROR\n";
                        return 0;
                    }
                    else c = b/a;
                }
                op.pop();
                nos.push(c);
            }
        }
        i++;
    }
    if(!op.empty() || nos.size() > 1) cout<<"ERROR";
    else cout<<nos.top();
    return 0;
}





// interviewBit easy one
bool is_operator(string s){
    if(s == "+" || s == "*" || s == "/" || s == "-"){
        return true;
    }
    return false;
}

int Solution::evalRPN(vector<string> &A) {
    int n = A.size();
    stack<int> s;
    int top, top1, top2;
    for(int i=0; i<n; i++){
        if(is_operator(A[i])){
            top2 = s.top(); s.pop();
            top1 = s.top(); s.pop();
            // if(A[i] == "+") top = top1+top2;
            // else if(A[i] == "-") top = top1-top2;
            // else if(A[i] == "*") top = top1*top2;
            // else if(A[i] == "/") top = top1/top2;
            switch (A[i][0]){  
                case '+' : top = top1+top2 ; break;  
                case '-' : top = top1-top2 ; break;  
                case '*' : top = top1*top2 ; break;  
                case '/' : top = top1/top2 ; break;  
            }  
            s.push(top);
        }
        else{
            int temp = stoi(A[i]);
            s.push(temp);
        }
    }
    return s.top();
}
