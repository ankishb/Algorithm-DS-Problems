#define pii pair<int,int>
#define f first
#define s second

int naive_sol(vector<int> A){
    int n = A.size(), max_ = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            max_ = max(max_, (j-i)*min(A[i], A[j]));
        }
    }
    return max_;
}

// doesn't work(wrong approach)
int optimal_sol1(vector<int> A){
    int n = A.size(), max_water = 0;
    vector<pii> water;
    for(int i=0; i<n; i++){
        water.push_back({A[i], i});
    }
    sort(water.begin(), water.end());
    int min_i = water[0].s;
    int max_i = water[0].s;
    for(int i=1; i<n; i++){
        int cur = max(abs(water[i].s - min_i), abs(water[i].s - max_i));
        max_water = max(max_water, water[i-1].f * cur);
        min_i = min(min_i, water[i].s);
        max_i = max(max_i, water[i].s);
    }
    return max_water;
}

int optimal_sol2(vector<int> A){
    int n = A.size();
    int l = 0, r = n-1, ans = 0;
    while(l < r){
        ans = max(ans, min(A[l], A[r])*(r-l));
        // move right side, as there may be greater el
        if(A[l] < A[r]) l++;
        else r--;
    }
    return ans;
}

int optimal_sol3(vector<int> A){
    int64_t n = A.size();
    if(n == 1) return 0;
    int64_t ans = -1, max = -1;
    for(int64_t i=0; i<n; i++){
        if(max < A[i]) max = A[i];
    }
    
    for(int64_t i=0; i<n; i++){
        int64_t area;
        for(int64_t r=n-1; r>i; r--){
            if((r - i) * max < ans) break;
            area = (r - i) * min(A[i], A[r]);
            if(area > ans) ans = area;
        }
    }
    return ans;
}

int Solution::maxArea(vector<int> &A) {
    // return naive_sol(A);
    return optimal_sol1(A);
    // return optimal_sol2(A);
    // return optimal_sol3(A);
}
