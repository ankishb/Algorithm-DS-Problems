// 8 9 3 8 0 2 4 8 3 9 0 5 2 2 7 3 7 9 0 2 3 9 9 7 0 3 9 8 6 5 7 6 2 7 0 3 9
// Ans: 19

// Space complexity: O(1), but modified given matrix, so it is O(N^2)
int Solution::minimumTotal(vector<vector<int> > &A) {
    if(A.size() == 0) return 0;
    if(A.size() == 1) return A[0][0];
    int n = A.size();
    for(int i=n-2; i>=0; i++){
        for(int j=0; j<A[i].size(); j++){
            A[i][j] += min(A[i+1][j], A[i+1][j+1]);
        }
    }
    return A[0][0];
}


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
