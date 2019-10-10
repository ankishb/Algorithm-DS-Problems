
/* O(N) appraoch
Idea is that, we find positive integer, put them at their repective index,
It means that we maintain array [0-n] such that A[0] = 0, A[1] = 1
We don't find that pattern after running first step, we find our answer
*/
int firstMissingPositive(vector<int> &A) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        if (A[i] > 0 && A[i] <= n) {
            int pos = A[i] - 1;
            if (A[pos] != A[i]) {
                swap(A[pos], A[i]);
                i--;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (A[i] != i + 1) return (i + 1);
    }
    return n + 1;
}


// O(N LogN) 
int Solution::firstMissingPositive(vector<int> &A) {
    sort(A.begin(), A.end());
    int i = 0, n = A.size(), c = 1;
    while(i < n && A[i] < 1) i++;
    if(i == n) return 1;
    for(int ii=i; ii<n; ii++){
        if(ii>0 && A[ii] == A[ii-1]) continue;
        if(A[ii] > c) return c;
        c++;
    }
    return c;
}


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 1;
        sort(nums.begin(), nums.end());
        if(nums[0] > 1) return 1;
        int i = 0;
        while(i < n && nums[i] < 1) i++;
        if((i >= n) || (i < n && nums[i] != 1)) return 1;
        int no = 1;
        while(i < n){
            if(no != nums[i]) return no;
            while(i < n && nums[i] == no) i++;
            no++;
        }
        return no;
    }
};