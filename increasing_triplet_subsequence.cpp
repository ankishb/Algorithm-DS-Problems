class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return false;
        int left_max[n] = {0};
        int right_max[n] = {0};
        int max_;
        max_ = INT_MAX;
        for(int i=0; i<n; i++){
            if(i == 0) left_max[i] = -1;
            else{
                if(max_ > nums[i-1]){
                    max_ = nums[i-1];
                    left_max[i] = max_;
                }
                else{
                    left_max[i] = max_;
                }
            }
        }
        max_ = INT_MIN;
        for(int i=n-1; i>=0; i--){
            if(i == n-1) right_max[i] = -1;
            else{
                if(max_ < nums[i+1]){
                    max_ = nums[i+1];
                    right_max[i] = max_;
                }
                else{
                    right_max[i] = max_;
                }
            } 
        }
        
        // for(auto itr : left_max) cout<<itr<<" ";
        // cout<<endl;
        // for(auto itr : right_max) cout<<itr<<" ";
        // cout<<endl;
        // for(auto itr : nums) cout<<itr<<" ";
        // cout<<endl;
        
        
        for(int i=1; i<n-1; i++){
            // cout<<left_max[i]<<" "<<nums[i]<<" "<<right_max[i]<<endl;
            if(left_max[i]<nums[i] && right_max[i]>nums[i]) return true;
        }
        return false;
    }
};