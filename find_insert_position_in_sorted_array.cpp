
// old one
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

int Solution::searchInsert(vector<int> &A, int t) {
    int n = A.size();
    if(n == 0) return 0;
    if(n == 1) return (A[0] == t) ? 0 : ((A[0] > t)?0:1);
    if(t < A[0]) return 0;
    if(t > A.back()) return n;
    int l = 0, r = n-1, m;
    while(l < r){
        m = l + (r - l)/2;
        // cout<<l<<" "<<r<<" "<<m<<" "<<A[l]<<" "<<A[r]<<" "<<A[m]<<endl;
        if(A[m] == t) return m;
        else if(A[m] < t) l = m+1;
        else r = m-1;
    }
    // if(A[l] > t) return l;
    if(l+1 <n && A[l] < t && A[l+1] > t) return l+1;
    return l;
    // if(A[l] != t) return l+1;
    // return l;
    // return binary_search(A, 0, A.size()-1, B);
}



// super old
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
