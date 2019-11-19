
void countDistinct(int A[], int k, int n){
    unordered_map<int,int> freq;
    for(int i=0; i<k; i++) freq[A[i]]++;
    int st = 0;
    cout<<freq.size();
    for(int i=k; i<n; i++){
        freq[A[st]]--;
        if(freq[A[st]] == 0){
            freq.erase(A[st]);
        }
        st++;
        freq[A[i]]++;
        cout<<" "<<freq.size();
    }
}