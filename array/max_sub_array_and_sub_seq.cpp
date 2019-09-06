
vector<int> maxSubarray(vector<int> arr) {
    int n = arr.size();
    if(n == 0) return {0,0};
    int max_arr = arr[0], max_seq = arr[0];
    int cur_arr=arr[0], cur_seq=arr[0];
    if(cur_arr < 0) cur_arr = 0;
    for(int i=1; i<n; i++){
        cur_arr += arr[i];
        if(cur_arr > max_arr) max_arr = cur_arr;
        if(cur_arr < 0) cur_arr = 0;

        // max({keep-prev, only-cur, prev+cur})
        max_seq = max({max_seq, arr[i], max_seq+arr[i]});
    }
    return {max_arr, max_seq};
}