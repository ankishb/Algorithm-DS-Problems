
class Solution {
public:
    int numSquares(int n) {
        if(n < 4) return n;
        int rows = floor(sqrt(n));
        vector<int> prev(n+1, 0), cur(n+1, 0);
        for(int i=1; i<=rows; i++){
            for(int j=1; j<=n; j++){
                if(i == 1) cur[j] = j;
                else if(j < i*i) cur[j] = prev[j];
                else cur[j] = min(prev[j], 1+cur[j-i*i]);
            }
            prev = cur;
            cur.resize(n+1, 0);
        }
        return prev[n];
    }
};