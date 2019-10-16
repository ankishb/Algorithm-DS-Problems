
int naive_sol(vector<int> &A){
    set<int> uni;
    for(auto a : A){
        uni.insert(a);
    }
    int i = 0;
    for(auto a : uni){
        A[i] = a;
        i++;
    }
    return i;
}
int optimal_sol(vector<int> &A){
    int i = 1, j = 1, n = A.size();
    while(j < n){
        if(A[j-1] != A[j]){
            A[i] = A[j];
            i++;
        }
        j++;
    }
    return i;
}
int Solution::removeDuplicates(vector<int> &A) {
    // return naive_sol(A);
    return optimal_sol(A);
}
