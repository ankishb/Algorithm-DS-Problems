class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        for(int i=0; i<n; i++){
            // cout<<i<<" ";
            if(i == 0 && n > 1 && nums[i] > nums[i+1]){
                return 0;
            }
            else if(i > 0 && nums[i] > nums[i-1]){
                if(i+1 < n && nums[i] > nums[i+1]){
                    return i;
                }
                else if(i+1 >= n){
                    return i;
                }
                // cout<<i<<" ";
            }
        }
        return 1;
    }
};