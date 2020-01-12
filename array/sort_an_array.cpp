class Solution {
public:
    // void swap(vector<int> &nums, int i1, int i2){
    //     int temp = nums[i1];
    //     nums[i1] = nums[i2];
    //     nums[i2] = temp;
    // }
    
    int pivotization(vector<int> &nums, int low, int high){
        int pivot = nums[high];
        int i = low-1;
        for(int j=low; j<high; j++){
            if(nums[j] < pivot){
                i++;
                // swap(nums, i, j);
                swap(nums[i], nums[j]);
            }
        }
        i++;
        // swap(nums, i, high);
        swap(nums[i], nums[high]);

        return i;
    }

    void print_vector(vector<int> nums){
        for(auto a : nums){
            cout<<a<<" ";
        }
        cout<<endl;
    }
    
    void quick_sort(vector<int> &nums, int low, int high){
        if(low < high){
            // cout<<low<<" :: "<<high<<"\t";
            int pi = pivotization(nums, low, high);
            // cout<<pi<<" :: ";
            // print_vector(nums);
            quick_sort(nums, low, pi-1);
            quick_sort(nums, pi+1, high);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        // merge_sort(nums);
        quick_sort(nums, 0, nums.size()-1);
        return nums;
    }
};