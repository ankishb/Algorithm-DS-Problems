
// again new try
void helper(vector<int> A, vector<bool> &mask, 
    vector<int> &temp, vector<vector<int>> &store){
    if(temp.size() == A.size()){
        store.push_back(temp);
        return;
    }
    for(int i=0; i<A.size(); i++){
        if(mask[i] == false){
            mask[i] = true;
            temp.push_back(A[i]);
            helper(A, mask, temp, store);
            mask[i] = false;
            temp.pop_back();
        }
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    int n = A.size();
    if(n == 0) return {{}};
    vector<bool> mask(n, false);
    vector<int> temp;
    vector<vector<int>> store;
    helper(A, mask, temp, store);
    return store;
}



// new algorithm
void helper(vector<int> A, int idx, vector<int> &cur, 
    vector<vector<int>> &store){
    int n = A.size();
    if(idx == n-1){
        store.push_back(cur);
        return;
    }
    for(int i=idx; i<n; i++){
        swap(cur[idx], cur[i]);
        helper(A, idx+1, cur, store);
        swap(cur[idx], cur[i]);
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    int n = A.size();
    if(n <= 0) return {{}};
    if(n == 1) return {{A[0]}};
    vector<vector<int>> store;
    vector<int> cur(A);
    helper(A, 0, cur, store);
    
    return store;
}


// old algorithm
void helper(vector<int> A, vector<bool> &mask, 
    vector<int> &temp, vector<vector<int>> &store){
    if(temp.size() == A.size()){
        store.push_back(temp);
        return;
    }
    for(int i=0; i<A.size(); i++){
        if(mask[i] == false){
            mask[i] = true;
            temp.push_back(A[i]);
            helper(A, mask, temp, store);
            mask[i] = false;
            temp.pop_back();
        }
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    int n = A.size();
    if(n == 0) return {{}};
    vector<bool> mask(n, false);
    vector<int> temp;
    vector<vector<int>> store;
    helper(A, mask, temp, store);
    return store;
}



void permute_util(vector<int> char_, vector<int> count, 
             vector<int> result,  int level,
             vector<vector<int> > &ans){
    if(result.size() == level){ // why level
        // print(result);
        ans.push_back(result);
        return;
    }

    for(int i=0; i<count.size(); i++){
        if(count[i] != 0){
            result[level] = char_[i];
            count[i]--;
            permute_util(char_, count, result, level+1, ans);
            count[i]++;
        }
    }
}


vector<vector<int> > Solution::permute(vector<int> &A) {
    map<int, int> my_map;
    vector<int> char_;
    vector<int> count;
    vector<int> result(A.size());

    for(int i=0; i<A.size(); i++){
        my_map[A[i]]++;
    }

    map<int, int>::iterator itr;
    for(itr=my_map.begin(); itr!=my_map.end(); ++itr){
        char_.push_back(itr->first);
        count.push_back(itr->second);
    }

    vector<vector<int> > ans;
    permute_util(char_, count, result, 0, ans);
    return ans;
}

