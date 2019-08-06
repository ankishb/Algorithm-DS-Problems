class Solution {
public:
    int m[1001][1001] = {};
    int minHeightShelves(vector<vector<int>>& b, int max_w, int i = 0, int w = 0, int h = 0) {
        if (i >= b.size()) return h;
        if (m[i][w] != 0) return m[i][w];
        return m[i][w] = min(h + minHeightShelves(b, max_w, i + 1, b[i][0], b[i][1]),
                w + b[i][0] > max_w ? INT_MAX : minHeightShelves(b, max_w, i + 1, w + b[i][0], max(h, b[i][1])));
    }
};

    

def minHeightShelves(self, books: List[List[int]], shelf_width: int) -> int:
        n = len(books)
        dp = [float('inf') for _ in range(n + 1)]
        dp[0] = 0
        for i in range(1, n + 1):
            max_width = shelf_width
            max_height = 0
            j = i - 1
            while j >= 0 and max_width - books[j][0] >= 0:
                max_width -= books[j][0]
                max_height = max(max_height, books[j][1])
                dp[i] = min(dp[i], dp[j] + max_height)
                j -= 1
        return dp[n]






    Step 1: Init DP. where dp[i] represents the min height of book up to i (1-index for padding to prevent SEGV)

    Step 2: Do DP, for each new book i (for book [0, n) and dp [1, n + 1)) we have 2 chioces

        Step 2-1: Put on the new layer of shelf, and the total height till book i will be dp[i - 1] + books[i][1]
        Step 2-2: Yet, we may try to squeeze the book as many as possible on the same layer on the condition that sum of their width < shift_width. So we go back from book i to book 0, checking all the possibilities that can be squeezed to the same layer. And if(sum > sw) the sum of width exceeds the shift width, unable to squeeze, then we quit finding the previous combinations.

    Analysis:

        Time complexity: O(N ^ 2)
        Space complexity: O(N) for storing the results


class Solution {
public:
    void print_dp(vector<int>& dp)
    {
        for(auto &x : dp)
        {
            printf("%d ", x);
        }
        printf("\n");
    }
    int minHeightShelves(vector<vector<int>>& books, int sw) 
    {
        int n = books.size();
		// init
        vector<int> dp(n + 1, 0);  // min height for book up to i (starting from 0)
        dp[0] = 0;
        
        // doing dp
        for(int i = 0; i < n; i++)
        {
            dp[i + 1] = dp[i] + books[i][1]; // Step 2- 1: on the new layer
            int sum = 0, h = 0;
            for(int j = i; j >= 0; j--)
            {
                sum += books[j][0]; // try to put on current layer, rather than the new one
                if(sum > sw) // the sum of width exceeds the shift width, unable to squeeze
                {
                    break;
                }
                else // Step 2- 2: keep squeezing
                {
                    h = max(h, books[j][1]); // get the tallest book for this layer
                    dp[i + 1] = min(dp[j] + h, dp[i + 1]); // for i + 1 th book it can either be the next layer, or this layer(try the combination to make 'one layer' as short as possible)
                    // printf("sum %d booksj_h %d h %d j %d dp[j] %d i %d dp[i + 1] %d\n", sum, books[j][1], h, j, dp[j], i, dp[i + 1]);
                }
            }
            // print_dp(dp);
        }
        // print_dp(dp);
        return dp[n];
    }
};
