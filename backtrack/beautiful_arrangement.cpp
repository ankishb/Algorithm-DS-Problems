
/*
As number are unique, we don't need to store number,
Just count the permutation, if it valid.
*/
class Solution {
public:
    vector<int> cur, A;
    // set<vector<int>> store;
    int count = 0;
    vector<bool> vis;
    
    void print(){
        for(auto a : cur) cout<<a<<" "; cout<<endl;
    }
    void helper(int n){
        if(cur.size() > n) return;
        if(cur.size() == n){
            // print();
            // store.insert(cur);
            count++;
            return;
        }
        
        for(int i=1; i<=n; i++){
            int m = cur.size()+1;
            if(vis[i] == true || ((A[i]%m != 0) && (m%A[i] != 0))) continue;
                vis[i] = true;
                cur.push_back(A[i]);
                helper(n);
                cur.pop_back();
                vis[i] = false;
            // }
        }
    }
    
    int countArrangement(int N) {
        vis.resize(N+1, false);
        A.resize(N+1,0);
        count = 0;
        for(int i=0; i<=N; i++){
            A[i] = i;
        }
        helper(N);
        // cout<<"\n---------------\n";
        // return store.size();
        return count;
    }
};