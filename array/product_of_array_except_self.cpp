class Solution {
public:
    // constant space
    vector<int> solution2(vector<int>& nums) {
        int n = nums.size();
        vector<int> prod(n,1);
        int left_prod = 1, right_prod = 1;
        for(int i=1; i<n; i++){
            left_prod *= nums[i-1];
            prod[i] = left_prod * prod[i];
        }
        for(int i=n-2; i>=0; i--){
            right_prod *= nums[i+1];
            prod[i] = right_prod * prod[i];
        }
        // for(auto a : prod) cout<<a<<" "; cout<<endl;
        return prod;
    }
    // space : O(n)
    vector<int> solution1(vector<int>& nums) {
        int n = nums.size();
        vector<int> left_prod(n,1), right_prod(n,1), prod(n,1);
        left_prod[1] = nums[0];
        for(int i=2; i<n; i++){
            left_prod[i] = left_prod[i-1] * nums[i-1];
        }
        right_prod[n-2] = nums[n-1];
        for(int i=n-3; i>=0; i--){
            right_prod[i] = right_prod[i+1] * nums[i+1];
        }
        // for(auto a : left_prod) cout<<a<<" "; cout<<endl;
        // for(auto a :right_prod) cout<<a<<" "; cout<<endl;
        for(int i=0; i<n; i++){
            prod[i] = left_prod[i]*right_prod[i];
        }
        return prod;
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        // return solution1(nums);
        return solution2(nums);
    }
};