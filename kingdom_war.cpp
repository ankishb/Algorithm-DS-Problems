
// O(N^3)
int kadanes_algo(vector<int> vect){
    int global_max = INT_MIN;
    int cur_sum = 0;
    for(int i=0; i<vect.size(); i++){
        cur_sum    += vect[i];
        if(global_max < cur_sum){
            global_max = cur_sum;
        }
        if(cur_sum < 0){
            cur_sum = 0;
        }
    }
    return global_max;
}

int Solution::solve(vector<vector<int> > &vect) {
    int global_max = INT_MIN;
    int cur_sum = 0;
    int n1 = vect.size();
    int n2 = vect[0].size();
    
    for(int l=0; l<n2; l++){
        vector<int> temp(n1, 0);
        for(int r=l; r<n2; r++){
            for(int k=0; k<n1; k++){
                temp[k] += vect[k][r];
            }
            int cur_sum = kadanes_algo(temp);
            global_max = max(global_max, cur_sum);
        }
    }
    return global_max;
}



// O(n^2)
int Solution::solve(vector<vector<int> > &A) {
    int rows = (int)A.size()+1, cols = (int)A[0].size()+1;
    int max = INT_MIN;
    vector<vector<int> > matrix(rows);
    for(int i = 0; i < rows; i++){
        matrix[i].resize(cols);
    }
    for(int i=rows-2 ; i >= 0 ; --i){
        for(int j=cols-2 ; j >= 0 ; --j){
            matrix[i][j] = A[i][j];
            matrix[i][j] += matrix[i+1][j] + matrix[i][j+1] - matrix[i+1][j+1];
            max = matrix[i][j]>max ? matrix[i][j] : max;
        }
    }
    return max;
}