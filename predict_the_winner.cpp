// Approach:
// As both play optimally, which means, their strategy to choose an element such that, it leaves an lower scored element behind for the opponent. So it pick an element as follows
// Our turn:
//     pick i = A[i] + opponent(i+1, j)
//     pick j = A[j] + opponent(i, j-1)
//     max(pick i, pick j)
// opponent turn:
//     choose i = you(i+1, j)
//     choose j = you(i, j-1)
//     min(choose i, choose j)
    

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if(nums.size() <= 1) return true;
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        
        int T[n][n], j, choose_i, choose_j;
        for(int k=0; k<n; k++){
            for(int i=0; i<n-k; i++){
                j = i+k;
                if(i==j) T[i][j] = nums[i];
                else if(i+1 == j) T[i][j] = max(nums[i], nums[j]);
                else{
                    // if chosen i, we will get min((i+2, j), (i+1, j-1))
                    choose_i = nums[i] + min(T[i+2][j], T[i+1][j-1]);
                    choose_j = nums[j] + min(T[i][j-2], T[i+1][j-1]);
                    T[i][j] = max(choose_i, choose_j);
                }
            }
        }
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                cout<<T[k][i]<<" ";
            }
            cout<<endl;
        }
        int my_score = T[0][n-1];
        return (my_score >= (sum - my_score)) ? true : false;
    }
};







 
// most elegant solution [https://youtu.be/Tw1k46ywN6E]
/*
I try to summarize what the video tell us.

The goal here is that we want to maximize the amount of money we can get assuming we move first.

Here your dp[i][j] means the max value we can get if it it's our turn and only coins between i and j remain.(Inclusively)

So dp[i][i] means there is only one coin left, we just pick it, dp[i][i+1] means there are only two left, we then pick the max one.

Now we want to derive the more general case. dp[i][j] = max( something + v[i], something + v[j]), since we either will pick the i or j coin. The problem now turns to what "something" here will be.

A quick idea may bedp[i][j] = max( dp[i + 1][j] + v[i], dp[i][j - 1] + v[j]), but here dp[i + 1][j] and dp[i][j - 1] are not the values directly available for us, it depends on the move that our opponent make.

Then we assume our opponent is as good as we are and always make optimize move. The worse case is that we will get the minimal value out of all possible situation after our opponent make its move.

so the correct dp formula would be dp[i][j] = max( min (dp[i + 1][j - 1], dp[i + 2][ j]) + v[i], min (dp[i][j - 2], dp[i + 1][ j - 1]) + v[j]}) .
If we pick i, then our opponent need to deal with subproblem dp[i + 1][j], it either pick from i + 2 or j - 1. Similarly, If we pick j, then our opponent need to deal with subproblem dp[i][j - 1] , it either pick from i + 1 or j - 2. We take the worse case into consideration so use min() here.

Hope this is helpful, and point out if I make any mistake :-)
*/
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if(nums.size()% 2 == 0) return true;
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        int myBest = utill(nums, dp, 0, n-1);
        return 2*myBest >= accumulate(nums.begin(), nums.end(), 0);
    }
    
    int utill(vector<int>& v, vector<vector<int>> &dp, int i, int j){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int a = v[i] + min(utill(v,dp, i+1, j-1), utill(v, dp, i+2, j));
        int b = v[j] + min(utill(v,dp,i, j-2), utill(v,dp, i+1, j-1));
        dp[i][j] = max(a, b);
                        
        return dp[i][j];
    }
};



// editorial
public class Solution {
    public boolean PredictTheWinner(int[] nums) {
        Integer[][] memo = new Integer[nums.length][nums.length];
        return winner(nums, 0, nums.length - 1, memo) >= 0;
    }
    public int winner(int[] nums, int s, int e, Integer[][] memo) {
        if (s == e)
            return nums[s];
        if (memo[s][e] != null)
            return memo[s][e];
        int a = nums[s] - winner(nums, s + 1, e, memo);
        int b = nums[e] - winner(nums, s, e - 1, memo);
        memo[s][e] = Math.max(a, b);
        return memo[s][e];
    }
}