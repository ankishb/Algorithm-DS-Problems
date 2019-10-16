
// combination-sum-1
class Solution {
public:
    vector<int> cur;
    vector<vector<int>> store;
    
    void helper(vector<int> A, int idx, int target){
        int n = A.size();
        if(idx >= n || target < 0) return;
        if(target == 0){
            store.push_back(cur);
            return ;
        }
        for(int i=idx; i<n; i++){
            // if(target-A[i] < 0) continue;
            cur.push_back(A[i]);
            helper(A, i, target-A[i]);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& A, int target) {
        if(A.size() == 0) return {{}};
        sort(A.begin(), A.end());
        helper(A, 0, target);
        return store;
    }
};



// combination-sum-2(with improvement)
class Solution {
public:
    vector<int> cur;
    vector<vector<int>> store;
    
    void helper(vector<int> A, int idx, int target){
        int n = A.size();
        if(target == 0){
            store.push_back(cur);
            return ;
        }
        if(idx >= n || target < 0) return;
        
        for(int i=idx; i<n; i++){
            if(i > 0 && A[i] == A[i-1] && i > idx) continue;
            cur.push_back(A[i]);
            helper(A, i+1, target-A[i]);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& A, int target) {
        if(A.size() == 0) return {{}};
        sort(A.begin(), A.end());
        helper(A, 0, target);
        return store;
    }
};



// combination-sum-2
class Solution {
public:
    vector<int> cur;
    set<vector<int>> store;
    
    void helper(vector<int> A, int idx, int target){
        int n = A.size();
        if(target == 0){
            store.insert(cur);
            return ;
        }
        if(idx >= n || target < 0) return;
        
        for(int i=idx; i<n; i++){
            // if(i > 0 && A[i] == A[i-1]) continue;
            cur.push_back(A[i]);
            helper(A, i+1, target-A[i]);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& A, int target) {
        if(A.size() == 0) return {{}};
        sort(A.begin(), A.end());
        helper(A, 0, target);
        vector<vector<int>> ans;
        for(auto v : store){
            ans.push_back(v);
        }
        return ans;
    }
};