
string twoArrays(int k, vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), custom_reverse);
    int n = A.size();
    for(int i=0; i<n; i++){
        if(A[i]+B[i] < k) return "NO";
        // cout<<A[i]+B[i]<<" ";
    }
    return "YES";
}