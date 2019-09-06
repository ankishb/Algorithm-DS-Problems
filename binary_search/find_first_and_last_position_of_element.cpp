
class Solution {
public:
    vector<int> searchRange1(vector<int>& A, int t) {
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
    vector<int> searchRange(vector<int>& A, int t) {
        int n = A.size();
        if(n == 0) return {-1,-1};
        int low  = lowerBound(A, t);
        int high = lowerBound(A, t+1);
        if(low >= n || A[low] != t) return {-1,-1};
        return {low, high-1};
    }
};


