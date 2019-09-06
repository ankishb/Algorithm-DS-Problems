
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost){
        return dp_sol(cost);
        // return min(recursive(cost,0), recursive(cost, 1));
        // return optimized(cost);
    }
    int recursive(vector<int> cost, int i){
        if(i >= cost.size()) return 0;
        return cost[i] + min(recursive(cost, i+1), recursive(cost, i+2));
    }    
    int dp_sol(vector<int> cost){
        int first = cost[0], sec = cost[1];
        int n = cost.size();
        for(int i=2; i<n; i++){
            int cur_cost = cost[i] + min(first, sec);
            first = sec;
            sec = cur_cost;
        }
        return min(first, sec);
    }

    // doesn't  work for few test case passes 243/276
    int optimized(vector<int> cost){
        int n = cost.size();
        int last = n-1, sec_last = n-2;
        int winner, min_cost = 0;
        while(last >= 0 && sec_last >= 0){
            min_cost += min(cost[last], cost[sec_last]);
            if(cost[last] < cost[sec_last]) winner = last;
            else winner = sec_last;
            last = winner; sec_last = winner;
            last -= 1;
            sec_last -= 2;
            // if(winner == )
        }
        return min_cost;
    }
};

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        return go(cost, cost.size());
    }
private:
    unordered_map<int,int> memo;
    int go(vector<int>& c, int n){
        if (memo.count(n)) return memo[n];
        if (n<=1) return memo[n]=c[n];
        return memo[n]=(n==c.size() ? 0 : c[n])+min(go(c,n-2),go(c,n-1));
    }
};