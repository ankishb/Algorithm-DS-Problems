
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int start = 0, end, len = 0, prod = 1;
        for(int i=0; i<nums.size(); i++){
            prod = nums[i]*prod;
            while(prod >= k && start < i){
                prod = prod/nums[start];
                start++;
            }
            if(prod < k){
                len += (i - start + 1);
            }
        }
        return len;
    }
};