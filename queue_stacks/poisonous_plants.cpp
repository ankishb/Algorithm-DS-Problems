
int poisonousPlants(vector<int> A){
    vector<int> p;
    int count = 0, n, m = A.size();
    for(int k=0; k<m; k++){
    // while(true){
        // cout<<"1 ";
        p.clear();
        n = A.size();
        for(int i=0; i<n; i++){
            if(i == 0 || A[i] <= A[i-1]){
                p.push_back(A[i]);
            }
        }
        if(n == 0 || p.size() == n) return count;
        count++;
        A = p;
    }
    return count;
}