
// fresh try
int Solution::maxArr(vector<int> &A) {
    int n = A.size(), ans = INT_MIN;
    int min1 = INT_MAX, max1 = INT_MIN;
    int min2 = INT_MAX, max2 = INT_MIN;

    for(int i=0; i<n; i++){
        min1 = min(min1, A[i]+i);
        max1 = max(max1, A[i]+i);
        min2 = min(min2, A[i]-i);
        max2 = max(max2, A[i]-i);
        ans = max({ans, max1-min1, max2-min2});
    }
    return ans;
}


// old one
int naive(vector<int> &A) {
    int n = A.size(), dist = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            dist = max(dist, abs(A[i]-A[j])+abs(i-j));
        }
    }
    return dist;
}
/*
If we expand this `|A[i] - A[j]| + |i - j|` expression, we see 
that there are four cases, which result into following cases:
    a. For max((A[i] + i) – (A[j] + j)) 
    b. For max((A[i] – i) – (A[j] – j))
*/
int optimal(vector<int> &A) {
    int min1=A[0], max1=A[0];
    int min2=A[0], max2=A[0];
    for(int i=0; i<A.size(); i++){
        min1 = min(min1, A[i]+i);
        max1 = max(max1, A[i]+i);
        min2 = min(min2, A[i]-i);
        max2 = max(max2, A[i]-i);
    }
    return max(max2-min2, max1-min1);
}
int Solution::maxArr(vector<int> &A) {
    // return naive(A);
    return optimal(A);
}
