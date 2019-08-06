
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        if(n == 3) return max(nums[0], max(nums[1], nums[2]));
        int max_el, start;
        vector<int> ans(nums);
        for(int i=2; i<n; i++){
            max_el = nums[0];
            if(i == n-1) start = 1;
            else start = 0;
        	for(int j=start; j<=i-2; j++){
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







wice pass:

    not rob nums[n-1]
    not rob nums[0]

and the other is same as House Robber.

int rob(vector<int>& nums)
{
    if(nums.size() == 0)
        return 0;
    if(nums.size() == 1)
        return nums[0];
    
    int pre1 = 0, cur1 = 0;
    for(int i = 0; i < nums.size() - 1; ++ i)
    {
        int temp = pre1;
        pre1 = cur1;
        cur1 = max(temp + nums[i], pre1);
    }
    
    int pre2 = 0, cur2 = 0;
    for(int i = 1; i < nums.size(); ++ i)
    {
        int temp = pre2;
        pre2 = cur2;
        cur2 = max(temp + nums[i], pre2);
    }
    
    return max(cur1, cur2);
}








This problem is a little tricky at first glance. However, if you have finished the House Robber problem, this problem can simply be decomposed into two House Robber problems.
Suppose there are n houses, since house 0 and n - 1 are now neighbors, we cannot rob them together and thus the solution is now the maximum of

    Rob houses 0 to n - 2;
    Rob houses 1 to n - 1.

The code is as follows. Some edge cases (n < 2) are handled explicitly.

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        if (n < 2) return n ? nums[0] : 0;
        return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
    }
private:
    int robber(vector<int>& nums, int l, int r) {
        int pre = 0, cur = 0;
        for (int i = l; i <= r; i++) {
            int temp = max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};









int  houseRob(vector<int>&a , int l ,  int h){
        int oneStepBack = 0; 
        int twoStepBack = 0;
        int MaxRob = 0;
        for(int i=l ; i<=h ; i++){
            MaxRob = max( twoStepBack+a[i] , oneStepBack);
            twoStepBack = oneStepBack;
            oneStepBack = MaxRob;
        }
        return MaxRob;
    }
    int rob(vector<int>& a) {
        if(a.size() == 0) return 0;
        if(a.size() == 1) return a[0]; 
        return max( houseRob(a , 0 , a.size()-2) , houseRob(a , 1 , a.size()-1));
    }