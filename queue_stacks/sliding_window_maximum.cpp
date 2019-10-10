
// new and elegant
vector<int> Solution::slidingMaximum(const vector<int> &A, int k){
    int n = A.size();
    if(n == 0 || k == 0) return {};
    deque<int> dq;
    vector<int> ans;

    for(int i=0; i<n; i++){
        while(!dq.empty() && (i-dq.front() >= k)){
            dq.pop_front();
        }
        while(!dq.empty() && A[dq.back()]<A[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i+1 >= k) ans.push_back(A[dq.front()]);
    }
    return ans;
}


// old one
vector<int> Solution::slidingMaximum(const vector<int> &A, int k) {
    int n = A.size();
    vector<int> ans;
    if(n == 0) return ans;

    deque<int> dq;
    for(int i=0; i<k; i++){
        while(!dq.empty() && A[dq.back()] <= A[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(A[dq.front()]);
    
    for(int i=k; i<n; i++){
        if(!dq.empty() && i - dq.front() >= k) dq.pop_front();
        while(!dq.empty() && A[dq.back()] <= A[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        
        ans.push_back(A[dq.front()]);
    }
    return ans;
}
