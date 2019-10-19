
vector<int> Solution::maxone(vector<int> &A, int k) {
    int n = A.size();
    int i = 0, j = 0;
    int max_l = 0, max_i = 0;
    while(j < n){
        while(i <= j && A[j] == 0 && k == 0){
            if(A[i] == 0) k++;
            i++;
        }
        if(A[j] == 0) k--;
        
        
        if(j-i+1 > max_l){
            max_l = j-i+1;
            max_i = i;
        }
        j++;
    }
    vector<int> ans;
    for(int ii=max_i; ii<max_i+max_l; ii++){
        ans.push_back(ii);
    }
    return ans;
}
