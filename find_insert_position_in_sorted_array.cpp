

int binary_search(vector<int> arr, int left, int right, int k){
    if(k>arr[arr.size()-1]){
        return arr.size();
    }
    if (k<arr[0]){
        return 0;
    }
    
    int mid;
    while(left<=right){
        mid = (left+right)/2;
        if(arr[mid] == k){
            return mid;
        }
        else if(k > arr[mid]){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    // // cout<<mid<<"=="<<arr[mid]<<endl;
    // if(arr[mid] > k){
    //     return mid;
    // }
    // else{
    //     return mid+1;
    // }
    return left;
}

int Solution::searchInsert(vector<int> &A, int B) {
    int ans = binary_search(A, 0, A.size()-1, B);
    return ans;
}
