
#include <bits/stdc++.h>
class Solution {
public:
    unordered_map<int, vector<int>> myMap;
    Solution(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            myMap[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int size = myMap[target].size();
        int random = rand()%(size);
        return myMap[target][random];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */