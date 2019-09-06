
/*
If s[i] is '(', set longest[i] to 0,because any string end with '(' cannot be a valid one.
Else if s[i] is ')'

    If s[i-1] is '(', longest[i] = longest[i-2] + 2
	Else if s[i-1] is ')' and s[i-longest[i-1]-1] == '(', longest[i] = longest[i-1] + 2 + longest[i-longest[i-1]-2]

For example, input "()(())", at i = 5, longest array is [0,2,0,0,2,0], longest[5] = longest[4] + 2 + longest[1] = 6.
*/
   int longestValidParentheses(string s) {
            if(s.length() <= 1) return 0;
            int curMax = 0;
            vector<int> longest(s.size(),0);
            for(int i=1; i < s.length(); i++){
                if(s[i] == ')'){
                    if(s[i-1] == '('){
                        longest[i] = (i-2) >= 0 ? (longest[i-2] + 2) : 2;
                        curMax = max(longest[i],curMax);
                    }
                    else{ // if s[i-1] == ')', combine the previous length.
                        if(i-longest[i-1]-1 >= 0 && s[i-longest[i-1]-1] == '('){
                            longest[i] = longest[i-1] + 2 + ((i-longest[i-1]-2 >= 0)?longest[i-longest[i-1]-2]:0);
                            curMax = max(longest[i],curMax);
                        }
                    }
                }
                //else if s[i] == '(', skip it, because longest[i] must be 0
            }
            return curMax;
        }




int Solution::longestValidParentheses(string A) {
    int n = A.length();
    if(n <= 1) return 0;
    stack<int> s;
    s.push(-1);
    int maxLen = 0, len;
    for(int i=0; i<n; i++){
        if(A[i] == ')'){
            if(s.top() != -1 && A[s.top()] == '('){
                s.pop();
                len = (i - s.top());
                maxLen = max(maxLen, len);
            }
            else s.push(i);
        }
        else s.push(i);
    }
    return maxLen;
}



// wrong logic
// int Solution::longestValidParentheses(string A) {
//     stack<pair<char, int>> s;
//     int n = A.length();
//     if(n <= 1) return 0;
//     vector<int> arr(n, 0);
//     int len, maxLen = 0, i=0, j;
    
//     for(i=0; i<n; i++){
//         if(A[i] == ')'){
//             if(!s.empty() && s.top().first=='('){
//                 arr[s.top().second] = 2;
//                 s.pop();
//             }
//         }
//         else{
//             s.push(make_pair(A[i], i));
//         }
//     }
//     for(auto itr : arr) cout<<itr<<" "; cout<<endl;
//     while(i < n){
//         while(A[i] == 0) i++;
//         j = i;
//         len = A[j];
//         while(j+1<n && (A[j]==2 || A[j+1]==2)){
//             len += A[j+1];
//             j++;
//         }
//         maxLen = max(maxLen, len);
//         if(i == j) i++;
//         else i = j;
//     }
//     return maxLen;
// }

