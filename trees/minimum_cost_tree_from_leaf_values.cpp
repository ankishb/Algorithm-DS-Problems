class Solution {
public:
    int mctFromLeafValues(vector<int>& A) {
        int ans = 0;
        int n = A.size();
        if(n == 0) return 0;
        if(n == 1) return A[0];
        // if(n == 2) return A[0]*A[1];
        int min_prod, min_id;
        vector<int> arr(A);
        int arr_size;
        
        for(int k=0; k<n-1; k++){
            arr_size = arr.size();
            min_prod = INT_MAX;
            min_id = 0;
            for(int i=0; i<arr_size-1; i++){
                if(min_prod > arr[i]*arr[i+1]){
                    min_prod = arr[i]*arr[i+1];
                    min_id = i;
                }
            }
            ans += min_prod;
            // make new array
            arr[min_id] = max(arr[min_id], arr[min_id + 1]);
            for(int j=min_id+1; j<arr_size-1; j++){
                arr[j] = arr[j+1];
            }
            arr.pop_back();
        }
        return ans;
    }
};



// recursive solution
class Solution {
public:
    int mctFromLeafValues(vector<int> arr) {
        int n=arr.size();
        if(n<=1) return 0;
        int mi=INT_MAX,mi_index=-1;
        for(int i=0;i<n-1;i++){
            if(arr[i]*arr[i+1]<mi){
                mi=arr[i]*arr[i+1];
                mi_index=i;
            }
        }
        int res=mi;
        if(arr[mi_index+1]<arr[mi_index]) mi_index++;
        arr.erase(arr.begin()+mi_index);
        return res+mctFromLeafValues(arr);
    }
};