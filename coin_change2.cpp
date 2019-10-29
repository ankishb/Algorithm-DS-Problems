void helper(vector<int> coins, int sum, int curSum, int idx, 
    set<vector<int>> &store, vector<int> &temp){
    if(curSum > sum) return;
    if(curSum == sum){
        store.insert(temp);
        return;
    }
    for(int i=idx; i<coins.size(); i++){
        if(curSum+coins[i] > sum) break;
        temp.push_back(coins[i]);
        helper(coins, sum, curSum+coins[i], i, store, temp);
        temp.pop_back();
    }
}

// The possible states to go from Rec are
// Case 1 : You include the coin -> Rec(S[], m, N-S[m])
// Case 2 : You avoid the coin -> Rec(S[], m-1, N)

// Base Cases are:

//     N = 0, m >= 0 Since the sum is already been made return 1.
//     N > 0, m = 0 Sum cannot be made as no coins left return 0.
//     N < 0, We have overshot the required sum return 0.

void helper2(vector<int> coins, int idx, int sum, int &count, 
    unordered_map<int, vector<int>> &myMap){
    cout<<idx<<" "<<coins[idx]<<" "<<sum<<endl;
    if(sum < 0) return;
    if(idx < 0) return;
    if(sum == 0  && idx >= 0) count = count+1;
    if(myMap.find(idx) == myMap.end()){
        bool found = false;
        for(auto itr : myMap[idx]){
            if(itr == sum-coins[idx]){ found=true; break; }
        }
        if(!found) {
            myMap[idx].push_back(sum-coins[idx]);
            helper2(coins, idx, sum-coins[idx], count, myMap);
        }
    }
    
    if(myMap.find(idx-1) == myMap.end()){
        bool found = false;
        for(auto itr : myMap[idx-1]){
            if(itr == sum){ found=true; break; }
        }
        if(!found) {
            myMap[idx-1].push_back(sum);
            helper2(coins, idx-1, sum, count, myMap);
        }
    }
}

int Solution::coinchange2(vector<int> &A, int B) {
    if(A.size() == 0) return 0;
    unordered_map<int, vector<int>> myMap;
    // sort(A.begin(), A.end());
    // set<vector<int>> store;
    // vector<int> temp;
    // helper(A, B, 0, 0, store, temp);
    // return store.size()%1000007;
    int count = 0;
    helper2(A, A.size()-1, B, count, myMap);
    return count%1000007;
}
