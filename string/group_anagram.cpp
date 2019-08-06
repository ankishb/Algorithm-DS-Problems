class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> my_map;
        int n = strs.size();
        string temp;
        int idx;
        for(int i=0; i<n; i++){
            temp = strs[i];
            sort(temp.begin(), temp.end());
            if(my_map.find(temp) != my_map.end()){
                idx = my_map[temp];
                ans[idx].push_back(strs[i]);
                // cout<<strs[i]<<" "<<idx<<endl;
            }
            else{
                my_map[temp] = ans.size();
                ans.push_back({strs[i]});
                // cout<<strs[i]<<" "<<ans.size()-1<<endl;
            }
        }
        return ans;
    }
};