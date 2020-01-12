
/*  Using bit manipulation:
	1. As we know that there are only two element with single occurance
		So in the first xor operation, we have both element in the final.
	2. Now we also know that whereever there is 1 as bit in the answer,
		that tells us that one of the element in our answer has set bit
		at that location. 
	3. So we use And operation to separate that number from another.
*/

class Solution {
public:
    vector<int> naive_sol(vector<int> nums){
        int i = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans;
        
        while(i < n){
            int j = i+1;
            while(j < n && nums[j] == nums[i]) j++;
            if(j == i+1) ans.push_back(nums[i]);
            i = j;
        }
        return ans;
    }
    
    vector<int> optimal_sol(vector<int> nums){
        int i = 0, n = nums.size();
        int xor_o = 0;
        for(auto d : nums){
        	xor_o = xor_o ^ d;
        }

        // find rightmost bit to create two buckets
        int d_bit = xor_o & ~(xor_o - 1);
        int first = 0, second = 0;
        for(auto d : nums){
        	if(d_bit & d){
        		first = first ^ d;
        	}
        	else{
        		second = second ^ d;
        	}
        }

        return {first, second};
    }
    
    vector<int> singleNumber(vector<int>& nums) {
        return naive_sol(nums);
        return optimal_sol(nums);
    }
};