
int max_abs_diff(vector<int> A){
    int n = A.size();
    int l_max[n], l_min[n], r_min[n], r_max[n];
    int left_min = INT_MAX, left_max = INT_MIN;
    int cur_min = 0, cur_max = 0;
    for(int i=0; i<n; i++){
        cur_min += A[i];
        cur_max += A[i];
        left_min = min(left_min, cur_min);
        left_max = max(left_max, cur_max);
        if(cur_max < 0) cur_max = 0;
        if(cur_min > 0) cur_min = 0;
        l_min[i] = left_min;
        l_max[i] = left_max;
    }
    int right_min = INT_MAX, right_max = INT_MIN;
    cur_min = 0, cur_max = 0;
    for(int i=n-1; i>=0; i--){
        cur_min += A[i];
        cur_max += A[i];
        right_min = min(right_min, cur_min);
        right_max = max(right_max, cur_max);
        if(cur_max < 0) cur_max = 0;
        if(cur_min > 0) cur_min = 0;
        r_min[i] = right_min;
        r_max[i] = right_max;
    }
    int ans = INT_MIN;
    for(int i=0; i<n-1; i++){
        ans = max(ans, abs(r_max[i+1]-l_min[i]));
        ans = max(ans, abs(r_min[i+1]-l_max[i]));
    }
    return ans;
}