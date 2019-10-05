
class Solution {
public:
    int wo_memory(vector<int> A){
        int n = A.size();
        if(n <= 2) return -1;
        int ls = 0, rs = 0;
        for(int i=0; i<n; i++){
            rs += A[i];
        }
        for(int j=0; j<n; j++){
            if(j > 0) ls += A[j-1];
            rs -= A[j];
            if(ls == rs) return j;
        }
        return -1;
    }
    
    int using_one_array(vector<int> A){
        int n = A.size();
        if(n <= 2) return -1;
        vector<int> store(n, 0);
        for(int i=1; i<n; i++){
            store[i] = store[i-1] + A[i-1];
        }
        int right_sum = 0, ans, found = 0;
        for(int i=n-1; i>=0; i--){
            if(i == n-1) right_sum = 0;
            else right_sum += A[i+1];
            if(store[i] == right_sum){
                ans = i;
                found = 1;
            }
        }
        return (found == 1) ? ans : -1;
    }
    
    int pivotIndex(vector<int>& nums) {
        return using_one_array(nums);
        // return wo_memory(nums);
    }
};


// Approach:
// 1. scan array from both side, such that it pick the element from left, if right_sum > left_sum and vice verca.

// not working, because logic is ambiguous. For exp: A = [-1,-1,-1,1], we start with left and right index i.e. 0 and 3, we see A[3] > A[0], we need to move index 0, which is not optimal, we need to check from both sides

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