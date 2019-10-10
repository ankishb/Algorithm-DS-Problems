
// new try
/*
tranverse over string, if we encounter ')', then we need to check,
if between '(' and ')', we have any operator sign or not.
    if yes, we have valid string
    else, we have redundant braces. 

For exp: "(a) + b" has redundant braces
*/
int Solution::braces(string s){
    int n = s.length();
    stack<char> st;
    for(int i=0; i<n; i++){
        if(s[i] == ')'){
            bool op = false;
            while(!st.empty() && st.top() != '('){
                char ch = st.top();
                if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
                    op = true;
                }
                st.pop();
            }
            if(!st.empty() && st.top() == '(') st.pop();
            if(!op) return 1; //redundant bracket
        }
        else st.push(s[i]);
    }
    return 0;
}


// old one 
int Solution::braces(string A) {
    stack<char> s;
    vector<char> v;
    int n = A.length();
    if(n == 0) return 0;
    for(int i=0; i<n; i++){
        if(A[i]=='(' || A[i]=='+' || A[i]=='-' || A[i]=='*' || A[i]=='/'){
            s.push(A[i]);
        }
        if(A[i] == ')'){

            bool op = false; //check if encounter any operator
            while(!s.empty()){
                char ch = s.top(); 
                s.pop();
                if(ch=='+' || ch=='-' || ch=='*' || ch=='/') op = true;
                if(ch == '(') break;
            }
            if(op == false) return 1;
        }
        
    }
    return 0;
}
