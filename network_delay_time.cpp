class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int, int>> > sets(N+1);
        vector<int> p;
        for(int i=0; i<times.size(); i++){
            p = times[i];
            sets[p[0]].push_back(make_pair(p[1], p[2]));
        }
        
        pair<int, int> pp;
        int max_delay = INT_MIN;
        int cur_delay;
        for(int i=0; i<sets[K].size(); i++){
            pp = sets[K][i];
            cur_delay = 0;
            while(sets[pp.first].size() != 0){
                cur_delay += pp.second;
                pp = sets[pp.first]
            }
            max_delay = max(max_delay, cur_delay)
        }
        
        return 1;
    }
};