// new try
int merge_count(vector<int> &A, int low, int mid, int high){
    if(low >= high) return 0;
    int ll = low, rl = mid+1;
    int lh = mid, rh = high;
    int count = 0;
    vector<int> copy;
    while(ll <= lh && rl <= rh){
        if(A[ll] <= A[rl]){
            copy.push_back(A[ll]);
            ll++;
        }
        else{
            count += (lh - ll + 1);
            copy.push_back(A[rl]);
            rl++;
        }
    }
    while(ll <= lh){
        copy.push_back(A[ll]);
        ll++;
    }
    while(rl <= rh){
        copy.push_back(A[rl]);
        rl++;
    }
    // cout<<low<<" "<<high<<" :: ";
    for(auto a : copy){
        // cout<<a<<" ";
        A[low] = a;
        low++;
    }
    // cout<<endl;
    
    return count;
}

int count_inversion(vector<int> &A, int low, int high){
    if(low < high){
        int mid = low + (high - low)/2;
        int lc = count_inversion(A, low, mid);
        int rc = count_inversion(A, mid+1, high);
        int count = merge_count(A, low, mid, high);
        return lc + rc + count;
    }
    return 0;
}

int Solution::countInversions(vector<int> &A) {
    return count_inversion(A, 0, A.size()-1);
}



// old one
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
