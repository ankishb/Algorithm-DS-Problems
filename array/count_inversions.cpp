
int naive_sol(vector<int> A){
    int n = A.size(), count = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(A[i] > A[j]) count++;
        }
    }
    return count;
}

int merge_c(vector<int> &A, int low, int mid, int high){
    int count = 0;
    int ll = low, lh = mid;
    int hl = mid+1, hh = high;
    vector<int> copy;
    while(ll <= lh && hl <= hh){
        if(A[ll] > A[hl]){
            count += lh-ll+1;
            copy.push_back(A[hl]);
            hl++;
        }
        else{
            copy.push_back(A[ll]);
            ll++;
        }
    }
    while(ll <= lh){
        copy.push_back(A[ll]);
        ll++;
    }
    while(hl <= hh){
        copy.push_back(A[hl]);
        hl++;
    }
    for(auto a : copy){
        A[low] = a;
        low++;
    }
    return count;
}

int optimal_sol(vector<int> &A, int low, int high){
    if(low >= high) return 0;
    
    int mid = low + (high - low)/2;
    int lc = optimal_sol(A, low, mid);
    int rc = optimal_sol(A, mid+1, high);
    
    int count = lc + rc + merge_c(A, low, mid, high);
    return count;
}

int Solution::countInversions(vector<int> &A) {
    // return naive_sol(A);
    set<pair<int,int>> vis;
    return optimal_sol(A, 0, A.size()-1);
}
