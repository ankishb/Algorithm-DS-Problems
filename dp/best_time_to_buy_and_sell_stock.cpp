/*
Approach:
Ist look at the Naive:
1. there are two case at ith day, either do nothing or sell the stock.
	1. For do nothing, max profit at ith day will be profit at (i-1)th day
	2. For selling stock at ith day, if look at all previous day (j<i) such that we buy stock at jth day and sell at ith day. Note that maximum profit, we get then is maxProfit(j) + price[j] - profit[i] - transaction fee
*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> profit(n+1, 0);
        for(int i=2; i<=n; i++){
        	for(int j=1; j<i; j++){
                // cout<<j-1<<" "<<i-1<<" "<<profit[i-1]<<" "<<profit[j-1] + prices[i-1] - prices[j-1] - fee<<endl;
        		profit[i] = max(profit[i-1], profit[i]);
                profit[i] = max(profit[i], profit[j-1] + prices[i-1] - prices[j-1] - fee);
        	}
        }

        // cout<<endl;
        for(auto itr : profit){
        	cout<<itr<<" ";
        }
        return profit[n];
    }
};








/*
The solution maintains two states:

s0 = profit having no stock
s1 = profit having 1 stock

The code iterates through the stock prices, and updates s0, s1 respectively. The run time is O(n).

update s0 by selling the stock from s1, so s0 = max(s0, s1+p);
update s1 by buying the stock from s0, so s1 = max(s1, s0-p-fee);
*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int s0 = 0, s1 = INT_MIN; 
        for(int p:prices) {
            int tmp = s0;
            s0 = max(s0, s1+p);
            s1 = max(s1, tmp-p-fee);
        }
        return s0;
    }
};







/*
You might either have sold your stock or not, we can get the best profit (by day i) on each case according to the relationship:

a. If you're holding your stock, the best profit you can get on day i is either the same with the previous day (if you didn't sell it) or you buy the stock on the price of day i.

hold = max(preSold - prices[i], preHold);

b. If you have no stock, the best you can get is either the same with yesterday (you've already sold it) or you sell it on today's price.

sold = max(preHold + prices[i] - fee, preSold);

Since we have 0 profit at the very beginning and can't sell, the initial value is -prices[0], and 0. Finally, we have to end on "sold" to get the maximum profit.
*/
    public int maxProfit(int[] prices, int fee) {       
        int preHold= -prices[0];
        int preSold = 0;
        
        for(int i = 1; i < prices.length; i++) {
            int hold = Math.max(preSold- prices[i], preHold);
            int sold = Math.max(preHold+ prices[i] - fee, preSold);
            preHold = hold ;
            preSold = sold ;
        }
        return preSold;
    }














Given any day I, its max profit status boils down to one of the two status below:

(1) buy status:
buy[i] represents the max profit at day i in buy status, given that the last action you took is a buy action at day K, where K<=i. And you have the right to sell at day i+1, or do nothing.
(2) sell status:
sell[i] represents the max profit at day i in sell status, given that the last action you took is a sell action at day K, where K<=i. And you have the right to buy at day i+1, or do nothing.

Let's walk through from base case.

Base case:
We can start from buy status, which means we buy stock at day 0.
buy[0]=-prices[0];
Or we can start from sell status, which means we sell stock at day 0.
Given that we don't have any stock at hand in day 0, we set sell status to be 0.
sell[0]=0;

Status transformation:
At day i, we may buy stock (from previous sell status) or do nothing (from previous buy status):
buy[i] = Math.max(buy[i - 1], sell[i - 1] - prices[i]);
Or
At day i, we may sell stock (from previous buy status) or keep holding (from previous sell status):
sell[i] = Math.max(sell[i - 1], buy[i - 1] + prices[i]);

Finally:
We will return sell[last_day] as our result, which represents the max profit at the last day, given that you took sell action at any day before the last day.

We can apply transaction fee at either buy status or sell status.

So here come our two solutions:

Solution I -- pay the fee when buying the stock:

public int maxProfit(int[] prices, int fee) {
        if (prices.length <= 1) return 0;
        int days = prices.length, buy[] = new int[days], sell[] = new int[days];
        buy[0]=-prices[0]-fee;
        for (int i = 1; i<days; i++) {
            buy[i] = Math.max(buy[i - 1], sell[i - 1] - prices[i] - fee); // keep the same as day i-1, or buy from sell status at day i-1
            sell[i] = Math.max(sell[i - 1], buy[i - 1] + prices[i]); // keep the same as day i-1, or sell from buy status at day i-1
        }
        return sell[days - 1];
    }

Solution II -- pay the fee when selling the stock:

    public int maxProfit(int[] prices, int fee) {
        if (prices.length <= 1) return 0;
        int days = prices.length, buy[] = new int[days], sell[] = new int[days];
        buy[0]=-prices[0];
        for (int i = 1; i<days; i++) {
            buy[i] = Math.max(buy[i - 1], sell[i - 1] - prices[i]); // keep the same as day i-1, or buy from sell status at day i-1
            sell[i] = Math.max(sell[i - 1], buy[i - 1] + prices[i] - fee); // keep the same as day i-1, or sell from buy status at day i-1
        }
        return sell[days - 1];
    }











class Solution {
    // https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108867
    // Normally we DP index dp[i] = dp[i - 1] + ....
    // But there is another way to DP the state, e.g. this question
    public int maxProfit(int[] prices, int fee) {
        // two states:
        // "hold" state: represent the max profit when we hold a stock at time i - 1.
        // "empty" state: represent the max profit when we do not hold a stock at time i - 1.
        // initialization:
        // for "hold" state, we hold one stock, so the profit is -prices[0]
        // for "empty" state, we do not hold stock, so the profit is 0
        int hold = -prices[0], empty = 0;
        for (int i = 1; i < prices.length; i++) {
            // on current time i
            // the max profit of hold state is either we still hold the stock we hold at the i-1 time(hold)
            // or we buy new stock(empty - prices[i])
            hold = Math.max(hold, empty - prices[i]);
            // the max profit of enpty state is eighter we still keep our hand empty(empty)
            // or we sell the stock we already hold(hold + prices[i] - fee)
            empty = Math.max(empty, hold + prices[i] - fee);
        }
        // return must be empty, because selling is better than holding one stock that has not been sold
        return empty;
    }
}