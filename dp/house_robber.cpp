
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        int max_el;
        vector<int> ans(nums);
        for(int i=2; i<n; i++){
            max_el = nums[0];
        	for(int j=0; j<=i-2; j++){
        		 max_el = max(max_el, max(nums[j], ans[j]));
        	}
            ans[i] = ans[i] + max_el;
        }

        
        for(int i=0; i<n; i++){
            cout<<ans[i]<<" ";
        	max_el = max(max_el, ans[i]);
        }
        return max_el;
    }
};