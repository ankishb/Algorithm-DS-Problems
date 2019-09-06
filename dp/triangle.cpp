class Solution {
public:
    // triangle: A
    int minimumTotal(vector<vector<int>>& A) {
        int n = A.size();
        if(n == 0) return 0;
        if(n == 1) return A[0][0];
        vector<int> arr(n,0);
        
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<=i; j++){
                arr[j] = min(arr[j]+A[i+1][j], arr[j+1]+A[i+1][j+1]);
            }
            for(auto itr : arr) cout<<itr<<" "; cout<<endl;
        }
        return arr[0]+A[0][0];
    }
};