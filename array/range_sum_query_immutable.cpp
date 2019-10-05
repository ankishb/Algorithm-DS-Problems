
// new try
class NumArray {
public:
    vector<int> cumsum;
    NumArray(vector<int>& nums) {
        int sum = 0;
        cumsum.push_back(sum);
        for(auto a : nums){
            sum += a;
            cumsum.push_back(sum);
        }
    }
    // [i-j] : cumsum[j] - cumsum[i-1]
    // Note: consider index carefully
    int sumRange(int i, int j) {
        return cumsum[j+1]-cumsum[i];  
    }
};

// old one
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