/*
- We need to sort on the basis of comparison between these states
- To do that, we consider the profit and loss between each state, based on difference at each state
- To comparison between each state, we sort the array based on the difference of root
*/
bool custom_sort(const vector<int> &v1, const vector<int> &v2){
    return (v1[0] - v2[0] < v1[1] - v2[1]);
}

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), custom_sort);
        int ans = 0;
        // for(auto c : costs){
        //     cout<<c[0]<<" "<<c[1]<<endl;
        // }
        for(int i=0; i<costs.size(); i++){
            if(i < costs.size()/2) ans += costs[i][0];
            else ans += costs[i][1];
        }
        return ans;
    }
};