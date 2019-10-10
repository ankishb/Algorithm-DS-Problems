
/*
Find count of subarray c1 & c2, for sum <= ql-1 & sum <= qr
and Answer would be [c2 - c1]

To do that, we can use two pointer approach, both from same point
1. Either include next term (if sum will still be less than k)
2. start a new subarray, if sum exceed
3. At each index, no of subarray with desired sum is [j - i + 1]
*/
int count_subarray(vector<int> A, int k){
    int n = A.size(), count = 0;
    int i = 0, j = 0, sum = 0;
    while(j < n){
        sum += A[j];
        while(i <= j && sum > k){
            sum -= A[i];
            i++;
        }
        count += (j - i + 1);
        cout<<i<<" "<<j<<" "<<sum<<" "<<count<<endl;
        j++;
    }
    return count;
}
int optimal(vector<int> A, int ql, int qr){
    int rc = count_subarray(A, qr);
    int lc = count_subarray(A, ql-1);
    cout<<" -- "<<rc<<" "<<lc<<endl;
    return (rc - lc);
}
int naive(vector<int> A, int ql, int qr){
    int n = A.size(), sum, count = 0;
    for(int i=0; i<n; i++){
        sum = 0;
        for(int j=i; j<n; j++){
            sum += A[j];
            if(sum >= ql && sum <= qr){
                count++;
            }
        }
    }
    return count;
}

int Solution::solve(vector<int> &A, int B, int C) {
    // return naive(A, B, C);
    return optimal(A, B, C);
}
