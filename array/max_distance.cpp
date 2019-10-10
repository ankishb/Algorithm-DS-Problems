/*
Note that the following approach take O(2*n) memory, 
but it can be do in O(n), if we start tranversing backward 
instead of building right_max array, this way, we can keep track 
of max_state from back and also find the ans
*/
int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    int left_min[n], right_max[n];
    for(int i=0; i<n; i++){
        if(i == 0) left_min[i] = A[i];
        else{
            left_min[i] = min(left_min[i-1], A[i]);
        }
    }
    for(int i=n-1; i>=0; i--){
        if(i == n-1) right_max[i] = A[i];
        else{
            right_max[i] = max(right_max[i+1], A[i]);
        }
    }
    int st = 0, end = 0, max_diff = 0;
    while(st < n && end < n){
        if(left_min[st] <= right_max[end]){
            max_diff = max(max_diff, end - st);
            end++;
        }
        else st++;
    }
    return max_diff;
}
