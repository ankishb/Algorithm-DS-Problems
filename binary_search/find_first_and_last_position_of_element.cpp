
// using inbuilt lower bound function
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1, -1};
        auto low = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        auto high = lower_bound(nums.begin(), nums.end(), target+1) - nums.begin()-1;
        if(low < 0 || low >= nums.size()) return {-1, -1};
        if(low >= 0 && low < nums.size() && nums[low] != target) return {-1, -1};
        return {low, high};
    }
};


class Solution {
public:
    vector<int> naive_sol(vector<int>& A, int t) {
        int l=INT_MAX, r=INT_MIN, n=A.size();
        for(int i=0; i<n; i++){
            if(A[i] == t){ l = i; break; }
        }
        if(l == INT_MAX) return {-1, -1};
        for(int i=l+1; i<n; i++){
            if(A[i] != t){ r = i-1; break; }
        }
        if(A.back() == t) r = n-1;
        return {l, r};
        
    }
    
    int lowerBound(vector<int> A, int t){
        int n = A.size();
        int l = 0, r = n-1, m;
        while(l <= r){
            m = l + (r - l)/2;
            if(A[m] < t) l = m+1;
            else r = m-1;
        }
        return l;
    }
    vector<int> optimal_sol(vector<int>& A, int t) {
        int n = A.size();
        if(n == 0) return {-1,-1};
        int low  = lowerBound(A, t);
        int high = lowerBound(A, t+1);
        if(low >= n || A[low] != t) return {-1,-1};
        return {low, high-1};
    }
    vector<int> searchRange(vector<int>& A, int t) {
        return naive_sol(A, t);
        return optimal_sol(A, t);
    }
};


