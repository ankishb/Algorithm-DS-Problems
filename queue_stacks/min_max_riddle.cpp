
// naive approach(Time comp: O(n^2))
int get_maximum(vector<long> arr, int w){
    int n = arr.size(), max_idx;
    deque<int> dq;
    for(int i=0; i<w; i++){
        while(!dq.empty() && arr[dq.back()] >= arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    max_idx = dq.front();
    for(int i=w; i<n; i++){
        // check for front element, if that is inside the window, or not
        while(i-dq.front() >= w) dq.pop_front();
        while(!dq.empty() && arr[dq.back()] >= arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        max_idx = (arr[dq.front()] > arr[max_idx]) ? dq.front() : max_idx;
    }
    return max_idx;
}

vector<long> riddle(vector<long> arr) {
    int n = arr.size();
    if(n < 1) return {};
    vector<long> ans(n,0);
    int min_ = arr[0], max_ = arr[0];
    for(auto a : arr){
        min_ = (a < min_) ? a : min_;
        max_ = (a > max_) ? a : max_;
    }
    for(int i=1; i<=n; i++){
        if(i == 1) ans[i-1] = max_;
        else if(i == n) ans[i-1] = min_;
        else{
            int idx = get_maximum(arr, i);
            ans[i-1] = arr[idx];
        }
    }
    return ans;
}

