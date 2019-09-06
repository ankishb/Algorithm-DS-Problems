class Solution {
public:
    int searchInsert(vector<int>& A, int t) {
        if(A.back() < t) return A.size();
        if(A[0] > t) return 0;
        int n = A.size(), l = 0, r = n-1, mid;
        while(l < r){
            mid = l + (r - l)/2;
            if(A[mid] == t) return mid;
            else if(t < A[mid]) r = mid-1;
            else l = mid+1;
        }
        if(t == A[l]) return l;
        if(t == A[r]) return r;
        if(t < A[l]) return l;
        if(t > A[l] ) return l+1;
        if(t < A[r]) return r;
        if(t > A[r]) return r+1;
        return -1;
    }
};