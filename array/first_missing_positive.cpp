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