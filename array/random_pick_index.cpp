
// Memory: O(1) and Time: O(N)
// Note that : copy a vector is constant time operation, it just 
//     point to that array.
#include <bits/stdc++.h>
class Solution {
public:
    vector<int> copy;
    Solution(vector<int>& nums) {
        copy = nums;
    }
    // easy to understand
    int pick(int target) {
        int count = 0, res = -1;
        for(auto d : copy){
            if(target == d) count++;
        }
        int idx = rand()%count;
        for(int i=0; i<copy.size(); i++){
            if(target == copy[i]){
                if(idx == 0) res = i;
                idx--;
            }
        }
        return res;
    }
    // using reserviour sampling
    int pick1(int target){
        int count = 0, res = -1;
        for (int i=0; i<copy.size(); i++){
            if (copy[i] == target) {
                /*
                randomly select an int from 0 to the nums of target. 
                If x equals 0, set the res as the current index. 
                The probability is always 1/nums for the latest 
                appeared number. 
                For example, 1 for 1st num, 1/2 for 2nd num, 
                1/3 for 3nd num (1/2 * 2/3 for each of the first 2 nums).
                */
                count++;
                int idx = rand()%count;
                if(idx == 0) res = i;
            }
        }
        return res;
    }
};

// Memory: O(N) and Time: O(1)
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