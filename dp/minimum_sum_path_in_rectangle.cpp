
// new try
// by modifying the given matrix
int solution1(vector<vector<int>> A){
    int n = A.size();
    if(n == 0) return 0;
    for(int i=n-2; i>=0;i--){
        for(int j=0; j<A[i].size(); j++){
            A[i][j] += min(A[i+1][j], A[i+1][j+1]);
        }
    }
    return A[0][0];
}

// O(n) space
int solution2(vector<vector<int>> A){
    int n = A.size();
    if(n == 0) return 0;
    
    vector<int> next(A[n-1]);
    for(int i=n-2; i>=0;i--){
        for(int j=0; j<A[i].size(); j++){
            next[j] = A[i][j] + min(next[j], next[j+1]);
        }
        next.pop_back();
    }
    return next[0];
}

int Solution::minimumTotal(vector<vector<int> > &A) {
    // return solution1(A);
    return solution2(A);
}






// old one
// Without modifying the given matrix and space complexity: O(N)
int minimumTotal(vector<vector<int> > &triangle) {
    int n = triangle.size();
    vector<int> minlen(triangle.back());
    for (int layer = n-2; layer >= 0; layer--){ // For each layer
        for (int i = 0; i <= layer; i++){ // Check its every 'node'
            // Find the lesser of its two children, and sum the current value in the triangle with it.
            minlen[i] = min(minlen[i], minlen[i+1]) + triangle[layer][i]; 
        }
    }
    return minlen[0];
}
