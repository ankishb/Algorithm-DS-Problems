class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), profit = 0;
        if(n < 2) return 0;
        if(n == 2) return max(0, prices[1]-prices[0]);
        vector<int> minArr(n, INT_MAX);
        minArr[0] = 0;
        minArr[1] = prices[0];
        for(int i=2; i<n; i++){
            minArr[i] = min(minArr[i-1], prices[i-1]);
        }
        for(auto itr : minArr) cout<<itr<<" ";
        for(int i=1; i<n; i++){
            profit = max(profit, prices[i]-minArr[i]);
        }
        return max(0, profit);
    }
};