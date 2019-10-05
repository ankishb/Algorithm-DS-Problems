/*
1. For each step, Calculate the cur_max, cur_min, and update global_max
2. check subarray condition, whethere we start new or stick to current one
*/
class Solution {
public:
    int maxProduct(vector<int>& A) {
        int n = A.size(); 
        int cur_max = 1, cur_min = 1, global_max = A[0];
        for(int i=0; i<n; i++){
            if(A[i] < 0) swap(cur_min, cur_max);
            cur_max *= A[i];
            cur_min *= A[i];
            global_max = max({global_max, cur_max});
            if(cur_max < 1) cur_max = 1;
        }
        return global_max;
    }
    /* Elegant solution
        1. At each step, we see, whether to stick to current one or start a new subarray
        2. update all parameters
    */
    int maxProduct1(vector<int>& A) {
        int n = A.size();
        int cur_min = A[0], cur_max = A[0], max_prod = A[0];
        for(int i=1; i<n; i++){
            if(A[i] < 0) swap(cur_min, cur_max);
            // either current or current with prev
            cur_min = min(cur_min*A[i], A[i]); 
            cur_max = max(cur_max*A[i], A[i]);
            max_prod = max(max_prod, cur_max);
        }
        return max_prod;
    }
};


/*
numspproach:
This is same as kadane algo to find maximum sum subarray, except there can be negative element in array, which can also make maximum subarray.
1. We keep track of maximum as well as minimum product at current step.
2. If we see -ve element, it become little tricky, the maximum becomes minimum, and minimum can become maximum, if it has already visit one -ve element before.
*/
class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int maxProduct = nums[0];
        int minProduct = nums[0];
        int maxRes = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (nums[i] >= 0)
            {
                maxProduct = max(maxProduct * nums[i], nums[i]);
                minProduct = min(minProduct * nums[i], nums[i]);
            }
            else
            {
                int temp = maxProduct;
                maxProduct = max(minProduct * nums[i], nums[i]);
                minProduct = min(temp * nums[i], nums[i]);
            }
            maxRes = max(maxRes, maxProduct);
        }
        return maxRes;
    }
};


// another elegant solution
int maxProduct(int A[], int n) {
    if(n==1) return A[0];
    int pMax=0, nMax=0, m = 0;
    for(int i=0; i<n; i++){
        if(A[i]<0) swap(pMax, nMax);
        pMax = max(pMax*A[i], A[i]);
        nMax = min(nMax*A[i], A[i]);
        m = max(m, pMax);
    }
    return m;
}


int maxProduct(int A[], int n) {
    // store the result that is the max we have found so far
    int r = A[0];

    // imax/imin stores the max/min product of
    // subarray that ends with the current number A[i]
    for (int i = 1, imax = r, imin = r; i < n; i++) {
        // multiplied by a negative makes big number smaller, small number bigger
        // so we redefine the extremums by swapping them
        if (A[i] < 0)
            swap(imax, imin);

        // max/min product for the current number is either the current number itself
        // or the max/min by the previous number times the current one
        imax = max(A[i], imax * A[i]);
        imin = min(A[i], imin * A[i]);

        // the newly computed max value is a candidate for our global result
        r = max(r, imax);
    }
    return r;
}



// this doesn't work

// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
// 		int n = nums.size();
//         if(n==1) return nums[0];
//         bool zero_flag = 0;
// 		int cur_max=1, cur_min=1, max_so_far=1, temp;
// 		for(int i=0; i<n; i++){
// 			if(nums[i] > 0){
// 				cur_max = max(cur_max*nums[i], 1);
// 				cur_min = min(cur_min*nums[i], 1);
//                 zero_flag = true;
// 			}
// 			else if(nums[i] == 0){
//                 // zero_flag = (1 - zero_flag);
// 				cur_max = 1;
// 				cur_min = 1;
// 			}
// 			// when number is negative
// 			else{
// 				temp = cur_max;
// 				cur_max = max(cur_min*nums[i], 1);
// 				cur_min = min(temp*nums[i], 1);
// 			}
// 			max_so_far = max(max_so_far, cur_max);
// 		}
//         if(max_so_far==1 && zero_flag==false){
//             return 0;
//         }
// 		return max_so_far;
//     }
// };
