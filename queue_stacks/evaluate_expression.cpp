
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
