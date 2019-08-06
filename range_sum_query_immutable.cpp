class NumArray {
public:
    vector<int> cum_sum;
    int n, sum;
    NumArray(vector<int>& nums) {
        n = nums.size();
        cum_sum.clear();
        sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            cum_sum.push_back(sum);
        }
    }
    
    int sumRange(int i, int j) {
        sum = cum_sum[j] ;
        if(i<=0) return sum;
        return sum - cum_sum[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */