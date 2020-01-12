
/*  Using binary search:
    if A[mid] == A[mid+1] or A[mid] == A[mid-1]
        then update low and high based on the count in left half and right half
    else
        we found that element
*/
class Solution {
public:
    int bitMan_sol(vector<int> &nums){
        int ans = 0;
        for(auto d : nums){
            ans = ans ^ d;
        }
        return ans;
    }
    int binarySearch_sol(vector<int> nums, int low, int high){
        if(high - low + 1 <= 3){
            int ans = 0;
            for(int i=low; i<=high; i++){
                ans = ans ^ nums[i];
            }
            return ans;
        }
        
        int mid = low + (high - low)/2;
        if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
            return nums[mid];
        }
        if(nums[mid] == nums[mid-1]){
            if((mid-low+1)%2 == 0){
                return binarySearch_sol(nums, mid+1, high);
            }
            else{
                return binarySearch_sol(nums, low, mid-2);
            }
        }
        if(nums[mid] == nums[mid+1]){
            if((high-mid+1)%2 == 0){
                return binarySearch_sol(nums, low, mid-1);
            }
            else{
                return binarySearch_sol(nums, mid+2, high);
            }
        }
        
        return 0;
    }
    
    int singleNonDuplicate(vector<int>& nums) {
        // return bitMan_sol(nums);
        return binarySearch_sol(nums, 0, nums.size()-1);
    }
};