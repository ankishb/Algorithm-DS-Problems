
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
