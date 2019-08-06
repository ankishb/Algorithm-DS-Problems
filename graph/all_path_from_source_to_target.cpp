class Solution {
public:
    void helper(vector<vector<int>>& graph, vector<vector<int>>& store, vector<int>& cur_vect){
        int n = graph.size();
        int prev = cur_vect.back();
        if(prev == n-1){
            store.push_back(cur_vect);
            return ;
        }
        for(int i=0; i<graph[prev].size(); i++){
            cur_vect.push_back(graph[prev][i]);
            helper(graph, store, cur_vect);
            cur_vect.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> store;
        vector<int> cur_vect;
        if(graph.size() == 0) return store;
        cur_vect.push_back(0);
        helper(graph, store, cur_vect);
        return store;
    }
};