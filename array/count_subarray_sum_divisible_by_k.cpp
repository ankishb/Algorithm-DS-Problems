
int get_count(vector<int> A, int k){
    int n = A.size(), sum = 0;
    int mod[k+1] = {0};
    for(int i=0; i<n; i++){
        sum += A[i];
        sum = ((sum%k)+k)%k;
        mod[sum]++;
    }
    int count = 0;
    for(int i=0; i<=k; i++){
        count += (mod[i]*(mod[i]-1))/2;
    }
    return count+mod[0];
}