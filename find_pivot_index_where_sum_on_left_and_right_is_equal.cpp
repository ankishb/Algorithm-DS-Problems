// Given an array of integers nums, write a method that returns the "pivot" index of this array.

// We define the pivot index as the index where the sum of the numbers to the left of the index is equal to the sum of the numbers to the right of the index.

// Approach:
// 1. scan array from both side, such that it pick the element from left, if right_sum > left_sum and vice verca.


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
    	int left_sum=0, right_sum=0;

    	for(int i=0; i<n; i++){
    		right_sum += nums[i];
    	}

    	for(int i=0; i<n; i++){
    		if(i > 0){
    			left_sum += nums[i-1];
    		}
    		right_sum -= nums[i];
    		if(left_sum == right_sum){
    			return i;
    		}
    	}
    	return -1;
    }
};


// not working
// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//     	int n = nums.size();
//         if(n == 1) return nums[0];

//         int left_sum=0, right_sum=0, left_idx=0, right_idx=n-1;
//         left_sum += nums[0];
//     	while(left_idx <= right_idx){
//     		if((left_sum>right_sum && left_sum>=0) || (left_sum<right_sum && left_sum<0)){
//     			right_sum += nums[right_idx];
//     			right_idx--;
//     		}
//     		else if((left_sum<right_sum && left_sum>=0) || (left_sum>right_sum && left_sum<0)){
//     			left_sum += nums[left_idx];
//     			left_idx++;
//     		}
//     		else{ return left_idx+1; }
//     	}
//     	if(left_sum == right_sum) return left_idx+1;
//     	return -1;
//     }
// };