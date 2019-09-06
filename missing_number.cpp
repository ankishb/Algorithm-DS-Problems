class Solution {
public:
    // using sum of arary
    int constMemory1(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(int i=0; i<n; i++) sum += nums[i];
        return (n)*(n+1)/2 - sum;
    }
    // using bit manipulation
    int constMemory2(vector<int>& nums) {
        int n = nums.size(), bit = 0;
        for(int i=0; i<n; i++){
            bit = bit ^ i ^ nums[i] ;
        }
        return bit^n;
    }
    int withSorting(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i=0;
        while(i < n){
            if(i != nums[i]) break;
            i++;
        }
        return i;
    }
    int missingNumber(vector<int>& nums) {
        // return withSorting(nums);
        // return constMemory1(nums);
        return constMemory2(nums);
    }
};