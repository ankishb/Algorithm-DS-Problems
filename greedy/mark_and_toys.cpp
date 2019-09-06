// Complete the maximumToys function below.
int maximumToys(vector<int> prices, int k) {
    int n = prices.size(); if(n == 0) return 0;
    sort(prices.begin(), prices.end());
    int count = 0;
    for(int i=0; i<n; i++){
        if(prices[i] <= k){
            count++; 
            k -= prices[i];
        }
        else break;       
    }
    return count;
}