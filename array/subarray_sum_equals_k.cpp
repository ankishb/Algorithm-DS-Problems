
/* Optimal strategy:
    sum[i-j] = sum[0-j] - sum[0-i]
    sum[0-i] = sum[0-j] - sum

1. We process sum[0-j] along the process
2. Store the sum[0-j] in the map as well, which becomes sum[0-i] for next iterations
3. we check, if (k-sum[0-j]) is present,
    if yes, include the count for that value in ans

*/

class Solution {
public:
    int new_try(vector<int> nums, int k){
        int sum = 0, count = 0, n = nums.size();
        unordered_map<int,int> map;
        map[0] = 1;
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(map.find(sum-k) != map.end()){
                count += map[sum-k];
            }
            map[sum]++;
        }
        return count;
    }
    
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
        // return optimized(nums, k);
        return new_try(nums, k);
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