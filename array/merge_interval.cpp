/*
Approach:
1. sort by first element in each list
2. create heap, to store the second element and we start with index 1.
3. If starting time is less than or equal to end time (store at top of heap), we pop top and insert current end time
4. else we create a new list
*/

bool custom_sort(const vector<int> &v1, const vector<int> &v2){
    return (v1[0]<v2[0]) || ((v1[0]==v2[0])&&(v1[1]>v2[1]));
}

// sort by first, if equal then  sort by second [both in increasing order]
// order: (we can do it either way)
bool custom(const vector<int> &v1, const vector<int> &v2){
    return (v1[0]<v2[0]) || (v1[0]==v2[0] &&  v1[1]<v2[1]);
}
class Solution {
public:
    // A --> intervals
    vector<vector<int>> optimal1(vector<vector<int>>& A) {
        if(A.size() <= 1) return A;
        priority_queue<int> pq;
        sort(A.begin(), A.end(), custom_sort);

        vector<vector<int> > ans;
        ans.push_back(A[0]);
        pq.push(A[0][1]);
        int n = A.size();
        int ans_i = 0;

        for(int i=1; i<n; i++){
            // cout<<pq.top()<<" : "<<A[i][0]<<'\n';
            if(pq.top() >= A[i][0]){
                ans[ans_i][1] = max(A[i][1], pq.top());
                if(pq.top() < A[i][1]){
                    pq.pop();
                    pq.push(A[i][1]);
                }
            }
            else{
                ans.push_back(A[i]);
                ans_i++;
                // cout<<A[i][1]<<" ";
                pq.push(A[i][1]);
            }
        }
        return ans;
    }
    
    vector<vector<int>> merge(vector<vector<int>>& A) {
        // return optimal1(A);
        return optimal2(A);
    }
    
    vector<vector<int>> optimal2(vector<vector<int>>& A) {
        int n = A.size();
        sort(A.begin(), A.end());
        
        // create max_heap with priority on second int
        priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
        
        for(auto v : A){
            if(pq.empty()) pq.push({v[1],v[0]});
            else if(v[0] <= pq.top().first){
                int s = pq.top().second;
                int e = pq.top().first;
                
                pq.pop();
                pq.push({max(e, v[1]), min(s, v[0])});
            }
            else{
                pq.push({v[1],v[0]});
            }
        }
        
        vector<vector<int>> ans;
        while(!pq.empty()){
            int s = pq.top().second;
            int e = pq.top().first;
            vector<int> temp = {s,e};
            ans.push_back({s,e});
            // idx--; 
            pq.pop();
        }
        return ans;
    }
};