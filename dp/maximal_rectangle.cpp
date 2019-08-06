
class Solution {
public:
    int getLargestRect(vector<int> A){
        int curArea, maxArea = 0, top, n = A.size(), i;
        stack<int> s;
        for(i=0; i<n; i++){
            if(s.empty()) s.push(i);
            else if(A[s.top()] <= A[i]) s.push(i);
            else{
                while(!s.empty() && A[s.top()] > A[i]){
                    top = s.top(); s.pop();
                    if(s.empty()) curArea = A[top]*i;
                    else curArea = (i - s.top() - 1)*A[top];
                    maxArea = max(maxArea, curArea);
                }
                s.push(i);
            }
        }
        while(!s.empty()){
            top = s.top(); s.pop();
            if(s.empty()) curArea = A[top]*i;
            else curArea = (i - s.top() - 1)*A[top];
            maxArea = max(maxArea, curArea);
        }
        // for(auto itr : A) cout<<itr<<" ";
        // cout<<": "<<maxArea<<endl;
        return maxArea;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();
        if(m == 0) return 0;
        vector<int> curRow(m);
        int maxArea = 0, curArea = 0, prev, cur;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i == 0) curRow[j] = (matrix[i][j] == '1') ? 1 : 0 ;
                else{
                    prev = (matrix[i-1][j] == '1') ? curRow[j] : 0 ;
                    curRow[j] = (matrix[i][j] == '1') ? (1 + prev) : 0;
                }
            }
            curArea = getLargestRect(curRow);
            maxArea = max(maxArea, curArea);
        }
        return maxArea;
    }
};