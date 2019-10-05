
/*
1. First iterate in forward direction, 
	if value > last, increase candies, 
	otherwise init with 1
2. Iterate from backward and maintain candies
*/
long candies1(int n, vector<int> arr) {
    vector<long> cand(n, 0);
    cand[0] = 1;
    for(int i=1; i<n; i++){
        if(arr[i] > arr[i-1]){
            cand[i] = cand[i-1]+1;
        }
        else cand[i] = 1;
    }
    long total = cand[n-1];
    for(int i=n-2; i>=0; i--){
        if(arr[i] > arr[i+1] && cand[i] <= cand[i+1]){
            cand[i] = cand[i+1]+1;
        }
        total += cand[i];
    }
    // for(auto a : cand) cout<<a<<" ";
    return total;
}

// failing at one case out of 16. Don't know why!
long candies(int n, vector<int> arr) {
    vector<long long int> cand(n,0);
    if(n <= 1) return n;
    cand[0] = 1;
    for(int i=1; i<n; i++){
        if(arr[i] > arr[i-1]){
            cand[i] = cand[i-1]+1;
        }
        else{
            int j = i-1;
            cand[i] = 1;
            while(j >= 0 && cand[j] <= cand[j+1] && arr[j] > arr[j+1]){
                cand[j] = cand[j+1] + 1;
                j--;
            }
        }
    }
    long long int total = 0;
    for(auto a : cand){
        // cout<<a<<" ";
        total += a;
    }
    return total;
}
