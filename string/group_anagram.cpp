class Solution {
public:
    vector<vector<string>> optimal2(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<int>> map;
        for(int i=0; i<n; i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            if(map.find(s) == map.end()){
                map[s] = {i};
            }
            else{
                map[s].push_back(i);
            }
        }
        vector<vector<string>> ans;
        vector<string> temp;
        for(auto itr : map){
            temp.clear();
            for(auto idx : itr.second){
                temp.push_back(strs[idx]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
    vector<vector<string>> optimal1(vector<string>& strs) {
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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        return optimal1(strs);
        // return optimal2(strs);
    }
};