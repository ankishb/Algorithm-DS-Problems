
// new try
class Solution {
public:
    int jump(vector<int>& A) {
        int n = A.size();
        if(n <= 1) return 0;
        int min_jumps = 0, i = 0;
        while(i < n){
            int j = i+1;
            int next = i+1;
            min_jumps++;
            if(i+A[i] >= n-1) return min_jumps;
            while(j < n && j <= i+A[i]){
                if(j+A[j] >= next+A[next]){
                    next = j;
                }
                j++;
            }
            i = next;
        }
        
        return min_jumps;
    }
};


/*
1. find the final-state(fs) from cur-state(ss) while having energy A[ss]
2. Now iterate back from fs toward ss, and
    collect if any higher energy, which will take us much far from fs + A[fs]
        If approved update ss and fs
*/
class Solution {
public:
    int jump(vector<int>& A) {
        int n = A.size();
        if(n == 1) return 0;
        int min_steps = 1, energy = A[0];
        int ss = 0, fs = min(ss+A[0], n-1);
        while(fs < n-1){
            int pick = fs;
            for(int i=fs-1; i>ss; i--){
                if(i+A[i] > fs+A[fs] && i+A[i] > pick+A[pick]){
                    pick = i;
                }
            }
            // cout<<pick<<" ";
            if(pick != fs){
                ss = pick;
                fs = min(ss+A[ss], n-1);
            }
            else{
                ss = fs;
                fs = ss+A[ss];
            }
            min_steps++;
        }
        return min_steps;
    }
};