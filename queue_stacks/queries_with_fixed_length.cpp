
int slidingMaximum(vector<int> &A, int k){
    int n = A.size();
    if(n == 0 || k == 0) return {};
    deque<int> dq;
    int min_el = INT_MAX;
    
    for(int i=0; i<n; i++){
        while(!dq.empty() && (i-dq.front() >= k)){
            dq.pop_front();
        }
        while(!dq.empty() && A[dq.back()]<A[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i+1 >= k) min_el = min(min_el, A[dq.front()]);
    }
    return min_el;
}

vector<int> solve(vector<int> arr, vector<int> queries) {
    vector<int> ans;
    for(auto q : queries){
        ans.push_back(slidingMaximum(arr, q));
    }
    return ans;
}