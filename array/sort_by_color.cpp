
// new try
void Solution::sortColors(vector<int> &A) {
    int n = A.size();
    // first collect all 0s in the left side
    int l = 0;
    while(l < n && A[l] == 0) l++;
    for(int i=l; i<n; i++){
        if(A[i] == 0){
            swap(A[i], A[l]);
            l++;
        }
    }
    // collect all 1s after index l
    for(int i=l; i<n; i++){
        if(A[i] == 1){
            swap(A[i], A[l]);
            l++;
        }
    }
}


// old one
void Solution::sortColors(vector<int> &A) {
    int start_index = 0;
    int index = 0;
    int n = 3;
    // Outer loop is run for n-1 times e.g. 2 in our exp
    for(int ii=0; ii<n-1; ii++){
        start_index = index;
        // inner loop run for [n, n-count(0)], which is
        // n times for all 0's and n-count(0's) times for all 1's
        for(int i=start_index; i<A.size(); i++){
            if(A[i] == ii){
                swap(A[index], A[i]);
                index++;
            }
        }
    }
}