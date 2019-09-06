// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(isBadVersion(1)) return 1;
        int l = 1, r = n, m;
        while(l < r){
            m = l + (r - l)/2;
            if(isBadVersion(m)) r = m;
            else l = m+1;
        }
        return l;
    }
};