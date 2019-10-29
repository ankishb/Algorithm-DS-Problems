
// new one
long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> store(n+2, 0);
    for(auto q : queries){
        store[q[0]] += q[2];
        store[q[1]+1] += (-q[2]);
    }
    long ans = 0, sum = 0;
    for(int i=0; i<n+2; i++){
        sum += store[i];
        ans = max(ans, sum);
    }
    return ans;
}

// old one
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