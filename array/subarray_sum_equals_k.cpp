
/*
Solution 2. From solution 1, we know the key to solve this problem is SUM[i, j]. So if we know SUM[0, i - 1] and SUM[0, j], then we can easily get SUM[i, j]. To achieve this, we just need to go through the array, calculate the current sum and save number of all seen PreSum to a HashMap. Time complexity O(n), Space complexity O(n).
*/
class Solution {
public:
    int brute_force(vector<int> nums, int k){
        int sum = 0, count = 0;
        for(int i=0; i<nums.size(); i++){
            sum = 0;
            for(int j=i; j<nums.size(); j++){
                sum += nums[j];
                if(sum == k) count++;
            }
        }
        return count;
    }
    
    int subarraySum(vector<int>& nums, int k) {
        // return brute_force(nums, k);
        return optimized(nums, k);
    }
    
    int optimized(vector<int> nums, int k){
        unordered_map<int, int> my_map;
        my_map[0] = 1;
        int sum = 0, count = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(my_map.find(sum-k) != my_map.end()){
                count += my_map[sum-k];
            }
            if(my_map.find(sum) != my_map.end()){
                my_map[sum] = my_map[sum] + 1;
            }
            else{
                my_map[sum] = 1;
            }
        }
        return count;
    }
    
    // when all elements are positive
    int solution1(vector<int>& nums, int k) {
        int start = 0, count = 0, sum = 0, i;
        for(i=0; i<nums.size(); i++){
            sum += nums[i];
            while(sum > k && start < i){
                sum -= nums[start];
                start++;
                if(sum == k) count++;
            }
            
        }
        return count;
    }
};