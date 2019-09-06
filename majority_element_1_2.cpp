
/*
Moree-counting algorithm for majority element (> n/2)
*/


class Solution {
public:
    int usingMemory(vector<int> nums){
        unordered_map<int, int> myMap;
        int k = nums.size()/2;
        for(auto a : nums){
            myMap[a]++;
            if(myMap[a] > k) return a;
        }
        for(auto itr : myMap){
            if(itr.second > k) return itr.first;
        }
        return -1;
    }
    
    int bitMasking(vector<int>& nums) {
        int majority = 0;
        for (unsigned int i = 0, mask = 1; i < 32; i++, mask <<= 1) {
            int bits = 0;
            for (int num : nums) {
                if (num & mask) {
                    bits++;
                }
            }
            if (bits > nums.size() / 2) {
                majority |= mask;
            }
        }
        return majority;
    }
    
    int majorityElement(vector<int>& nums) {
        return usingMemory(nums);
        return bitMasking(nums);
    }
};