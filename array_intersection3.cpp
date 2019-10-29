class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        unordered_map<int,int> map;
        for(auto a : arr1) map[a]++;
        for(auto a : arr2) map[a]++;
        vector<int> ans;
        for(auto a : arr3){
            if(map[a] == 2){
                ans.push_back(a);
            }
        }
        return ans;
    }
};