
long stockmax(vector<int> prices) {
    int n = prices.size();
    long profit = 0, sell = prices[n-1];
    for(int i=n-2; i>=0; i--){
        if(prices[i] > sell){
            sell = prices[i];
        }
        else{
            profit += (sell - prices[i]);
        }
    }
    return profit;
}




// not working
bool custom(const pair<int,int> &p1, const pair<int, int> &p2){
    return (p1.first > p2.first);
}
long stockmax(vector<int> prices, vector<pair<int, int>> store) {
    int n = prices.size();
    long int ans = 0;
    int i = store[0].second, j = 0;
    long buy, sell, profit = 0, count;
    while(i < n){
        // cout<<i<<" "<<prices[i]<<" "<<profit<<endl;
        buy = 0; count = 0; sell = prices[i];
        for(int k=j; k<i; k++){
            buy += prices[k];
            count++;
        }
        if(buy > 0) profit += (sell*count - buy);
        while(store[j].second <= i) j++;
        cout<<buy<<" "<<sell<<" "<<profit<<" "<<i<<" "<<j<<endl;
        if(j == n) break;
        i = store[j].second;
    }
    // cout<<profit<<endl;
    return profit;
}