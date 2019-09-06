bool custom_sort(const pair<int,int> &p1, const pair<int,int> &p2){
    return (p1.first == p2.first) ? (p1.second < p2.second) : (p1.first < p2.first);
}

// Complete the jimOrders function below.
vector<int> jimOrders(vector<vector<int>> orders) {
    int n = orders.size();
    vector<pair<int,int>> serve;
    for(int i=0; i<n; i++){
        serve.push_back(make_pair(orders[i][0]+orders[i][1], i+1));
    }
    sort(serve.begin(), serve.end(), custom_sort);
    vector<int> ans;
    for(int i=0; i<n; i++){
        ans.push_back(serve[i].second);
    }
    return ans;
}