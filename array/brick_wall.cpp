/*
Idea is to get cumulative sum for each wall, 
then we will find the maximum common pivot point, 
where it can be break, with minimum effort

One edge case wih two possibilities: (when we have only one shelf)
    1. When we have just one brick: We can't break it (unbroken shelves: 1)
    2. When we have more than one bricks: we can break with at least one possible 
        scnerio (unbroken shelves: 0)
*/
class Solution {
public:
    // new solution
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size(), sum;
        // As if n = 1, then we can't break it, ans = 1
        if(n < 0) return 0;
        if(n == 1){
            return (wall[0].size() == 1) ? 1 : 0;
        }
        unordered_map<int, int> map;
        for(auto v : wall){
            sum = 0;
            for(auto el : v){
                sum += el;
                map[sum]++;
            }
        }
        map.erase(sum);
        int ans = 0;
        for(auto itr : map){
            ans = max(ans, itr.second);
        }
        return n - ans;
    }

    // old solution
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