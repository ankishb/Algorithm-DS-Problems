
long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> arr(n+2, 0);
    for(auto q : queries){
        arr[q[0]] += q[2];
        arr[q[1]+1] -= q[2];
    }
    // for(auto itr : arr) cout<<itr<<" ";
    long maxEl = arr[0];
    for(int i=1; i<n+2; i++){
        arr[i] += arr[i-1];
        maxEl = max(maxEl, arr[i]);
    }
    // cout<<endl;
    // for(auto itr : arr) cout<<itr<<" ";
    // cout<<endl;
    return maxEl;
}