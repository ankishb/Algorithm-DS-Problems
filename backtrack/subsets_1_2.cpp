
// subsets-1
// new try
class Solution {
public:
    vector<vector<int>> store;
    vector<int> cur;
    
    void helper(vector<int> A, int idx){
        store.push_back(cur);
        int n = A.size();
        for(int i=idx; i<n; i++){
            cur.push_back(A[i]);
            helper(A, i+1);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        helper(nums, 0);
        return store;
    }
};



// subset-2 (with improvement)
/*
This statement is the heart of this solution. It will avoid
duplicate to enter in the same array. Note here duplicate is
refering to same subset again(not the element in a subset)

For exp: [1,1,2] : [1(0),2(2)] && [1(1),2(2)] are generating 
same subset with different index of 1, which should be avoided

i > idx will fix first 1, and avoid next repeated element(1)

if(i>0 && A[i] == A[i-1] && i > idx) continue;
*/
class Solution {
public:
    vector<vector<int>> store;
    vector<int> cur;
    
    void helper(vector<int> A, int idx){
        store.push_back(cur);
        int n = A.size();
        for(int i=idx; i<n; i++){
            if(i>0 && A[i] == A[i-1] && i > idx) continue;
            cur.push_back(A[i]);
            helper(A, i+1);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        helper(nums, 0);
        return store;
    }
};
/* extra material
i > order prevents [1,1,2] from generating duplicate [1,2]. When order is 0, i loops from 0 to 2. When i is 0, you choose 1 at 0th index, go into backtracking, generates cases like [1,1][1,1,2][1,2] then return, redos the choice. Then i increments to 1, you choose 1 at 1st index, since i greater than order 0, continue prevents backtracking, so no duplicate [1,2].

PS: [1,1] can be generated because i and order are the same at the time which is 1, so its backtracking is not stopped.
*/

// subset-2
class Solution {
public:
    set<vector<int>> store;
    vector<int> cur;
    
    void helper(vector<int> A, int idx){
        store.insert(cur);
        int n = A.size();
        for(int i=idx; i<n; i++){
            cur.push_back(A[i]);
            helper(A, i+1);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        helper(nums, 0);
        vector<vector<int>> ans;
        for(auto v : store){
            ans.push_back(v);
        }
        return ans;
    }
};