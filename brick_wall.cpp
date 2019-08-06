class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int sum, ans;
        
        unordered_map<int, int> my_map;
        for(int i=0; i<wall.size(); i++){
            sum = 0;
            for(int j=0; j<wall[i].size(); j++){
                sum += wall[i][j];
                my_map[sum]++;
            }
        }
        if(my_map.size() > 1){
            my_map.erase(sum);
        }
        else{
            return wall.size();
        }
        ans = 0;
        int max_ = INT_MIN;
        for(auto itr : my_map){
            max_ = max(max_, itr.second);
            // cout<<itr.first<<" : "<<itr.second<<endl;
        }
        return wall.size()-max_;
    }
};