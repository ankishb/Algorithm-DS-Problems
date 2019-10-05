
// new try (O(N*log(N)))
int Solution::maxp3(vector<int> &A) {
    sort(A.begin(), A.end());
    int n = A.size();
    int all_pos = A[n-3]*A[n-2]*A[n-1]; //can be all negative
    int pos_neg = A[0]*A[1]*A[n-1];     // if 2nd last el is negative
    return max({all_pos, pos_neg});
}




// fastest one (O(N))
int Solution::maxp3(vector<int> &A) {
    if(A.size() == 0) return 0;
    if(A.size() == 1) return 1;
    if(A.size() == 2) return max(A[0] * A[1], max(A[0], A[1]));
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX;
    for(int i=0; i<A.size(); i++) {
        if(A[i] > max1){
            max3 = max2;
            max2 = max1;
            max1 = A[i];
        }
        else if(A[i] > max2) {
            max3 = max2;
            max2 = A[i];
        }
        else if(A[i] > max3) {
            max3 = A[i];
        }
        if(A[i] < min1) {
            min2 = min1;
            min1 = A[i];
        }
        else if(A[i] < min2) {
            min2 = A[i];
        }
    }
    //cout << max1 << " " << max2 << " " << max3 << " " << min1 << " " << min2 << endl;
    //cout << max1 * max2 * max3 << " " << min1 * min2 * max1 << endl;
    return max(max1 * max2 * max3, max1 * min1 * min2);
}



// worse solution
int Solution::maxp3(vector<int> &A) {
    if(A.size() < 3){
        return 0;
    }
    
    long long int neg1 = INT_MAX, neg2 = INT_MAX;
    int neg1_count = 0;
    
    for(int i = 0; i < A.size(); i++){
        if(A[i] < neg1 && A[i] < 0){
            neg1_count = 1;
            neg1 = A[i];
        }
        else if(A[i] == neg1 && A[i] < 0){
            neg1_count++;
        }
    }
    
    if(neg1_count > 1){
        neg2 = neg1;
    }
    else if(neg1_count == 1){
        for(int i = 0; i < A.size(); i++){
            if(A[i] < 0 && A[i] < neg2 && neg1 < A[i]){
                neg2 = A[i];
            }
        }
    }
    
    long long int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    int max1_count = 0, max2_count = 0;
    
    for(int i = 0; i < A.size(); i++){
        if(A[i] > max1){
            max1 = A[i];
            max1_count = 1;
        }
        else if(A[i] == max1){
            max1_count++;
        }
    }
    
    if(max1_count > 1){
        max1_count--;
        max2 = max1;
    }
    else{
        for(int i = 0; i < A.size(); i++){
            if(A[i] > max2 && max1 > A[i]){
                max2 = A[i];
                max2_count = 1;
            }
            else if(A[i] == max2 && max1 > A[i]){
                max2_count++;
            }
        }
    }
    
    if(max1_count > 1){
        max3 = max1;
    }
    else if(max2_count > 1){
        max3 = max2;
    }
    else{
        for(int i = 0; i < A.size(); i++){
            if(A[i] > max3 && max2 > A[i] && max1 > A[i]){
                max3 = A[i];
            }
        }
    }
    
    if(neg1 == INT_MIN || neg2 == INT_MIN){
        return (int)max1*max2*max3;
    }
    
    return (int)max(max1*max2*max3, max1*neg1*neg2);
}