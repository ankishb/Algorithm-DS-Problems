
// permuatation-1
class Solution {
public:
    vector<vector<int>> store;
    vector<int> cur;
    vector<bool>vis;
    
    void helper(vector<int> A){
        int n = A.size();
        if(cur.size() == n){
            store.push_back(cur);
        }
        for(int i=0; i<n; i++){
            if(vis[i] == true) continue;
            cur.push_back(A[i]);
            vis[i] = true;
            helper(A);
            cur.pop_back();
            vis[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vis.resize(nums.size(), false);
        helper(nums);
        
        return store;
    }
};


// permuatation-2
/*
Only logic to remember, how to deal with duplicates:
	
    if(i > 0 && A[i] == A[i-1] && !vis[i - 1]) continue;

*/
class Solution {
public:
    set<vector<int>> store;
    vector<int> cur;
    vector<bool> vis;
    
    void helper(vector<int> A){
        if(cur.size() == A.size()){
            store.insert(cur);
            return;
        }
        for(int i=0; i<A.size(); i++){
            if(vis[i] || i > 0 && A[i] == A[i-1] && !vis[i - 1]) continue;
            // if(vis[i] == true) continue;
            vis[i] = true;
            cur.push_back(A[i]);
            helper(A);
            cur.pop_back();
            vis[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vis.resize(nums.size(), false);
        helper(nums);
        vector<vector<int>> ans;
        for(auto v : store){
            ans.push_back(v);
        }
        return ans;
    }
};