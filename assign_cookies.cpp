
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size(), m=s.size();
        if(n==0 || m==0) return 0;
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int gi=n-1, sj=m-1;
        int count = 0;
        while(gi>=0 && sj>=0){
            if(s[sj] >= g[gi]){
                count++;
                sj--;
                gi--;
            }
            else{
                gi--;
            }
        }
        return count;
    }
};