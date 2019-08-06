
void print(vector<int> cur){
    for(auto itr : cur) cout<<itr<<" ";
    cout<<endl;
}

void helper(int X, int x, int n, int idx, int &count, vector<int> &cur){
    if(x < 0) return ;
    if(x == 0){ count++; print(cur); return; }
    for(int i=idx; i<=sqrt(X); i++){
        if(pow(i,n) <= x){
            cur.push_back(i);
            helper(X, x-pow(i,n), n, i+1, count, cur);
            cur.pop_back();
        }
    }
}

// Complete the powerSum function below.
int powerSum(int X, int N) {
    // vector<vector<int>> store;
    int count = 0;
    vector<int> cur;
    helper(X, X, N, 1, count, cur);
    return count;
}