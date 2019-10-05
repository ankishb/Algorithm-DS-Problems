bool custom_sort(const vector<int> &v1, const vector<int> &v2){
    return (v1[0] < v2[0]) || (v1[0] == v2[0] && v1[1] < v2[1]);
}
bool sort_by_sec(const vector<int> &v1, const vector<int> &v2){
    return (v1[1] < v2[1]) || (v1[1] == v2[1] && v1[0] < v2[0]);
}

class Solution {
public:
    int naive(vector<vector<int>>& A) {
        int n = A.size();
        vector<int> len(n, 1);
        sort(A.begin(), A.end(), custom_sort);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(A[i][0] > A[j][1]){
                    len[i] = max(len[i], len[j]+1);
                }
            }
        }
        
        int max_len = 0;
        for(auto l : len){
            max_len = max(max_len, l);
        }
        return max_len;
    }
    /*
    Similar to activity selection
    */
    int optimal(vector<vector<int>>& A) {
        int n = A.size();
        if(n <= 1) return n;
        sort(A.begin(), A.end(), sort_by_sec);
        // for(auto v : A){
        //     cout<<v[0]<<" "<<v[1]<<endl;
        // }
        // cout<<"--------\n";
        
        int len = 1, last = A[0][1];
        for(int i=1; i<n; i++){
            if(last < A[i][0]){
                len++;
                last = A[i][1];
            }
        }
        return len;
    }
    int findMinArrowShots(vector<vector<int>>& A) {
        // return naive_ways(A);
        return optimal(A);
    }
};