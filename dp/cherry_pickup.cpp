
// class Solution(object):
    def cherryPickup(self, grid):
        N = len(grid)
        dp = [[float('-inf')] * N for _ in xrange(N)]
        dp[0][0] = grid[0][0]
        for t in xrange(1, 2*N - 1):
            dp2 = [[float('-inf')] * N for _ in xrange(N)]
            for i in xrange(max(0, t-(N-1)), min(N-1, t) + 1):
                for j in xrange(max(0, t-(N-1)), min(N-1, t) + 1):
                    if grid[i][t-i] == -1 or grid[j][t-j] == -1:
                        continue
                    val = grid[i][t-i]
                    if i != j: val += grid[j][t-j]
                    dp2[i][j] = max(dp[pi][pj] + val
                                    for pi in (i-1, i) for pj in (j-1, j)
                                    if pi >= 0 and pj >= 0)
            dp = dp2
        return max(0, dp[N-1][N-1])


// class Solution(object):
    def cherryPickup(self, grid):
        N = len(grid)
        memo = [[[None] * N for _1 in xrange(N)] for _2 in xrange(N)]
        def dp(r1, c1, c2):
            r2 = r1 + c1 - c2
            if (N == r1 or N == r2 or N == c1 or N == c2 or
                    grid[r1][c1] == -1 or grid[r2][c2] == -1):
                return float('-inf')
            elif r1 == c1 == N-1:
                return grid[r1][c1]
            elif memo[r1][c1][c2] is not None:
                return memo[r1][c1][c2]
            else:
                ans = grid[r1][c1] + (c1 != c2) * grid[r2][c2]
                ans += max(dp(r1, c1+1, c2+1), dp(r1+1, c1, c2+1),
                           dp(r1, c1+1, c2), dp(r1+1, c1, c2))

            memo[r1][c1][c2] = ans
            return ans

        return max(0, dp(0, 0, 0))




class Solution {
public:

int memo[51][51][51];

int cond(int i,int j,int k,int n,vector<vector<int>>& grid){
    int i1=i;
    int j1=j;
    int i2=k;
    int j2=i1+j1-i2;
    // cout<<i1<<" "<<j1<<" "<<i2<<" "<<j2;
    if(j2<0||j2>=n)return INT_MIN;
    if(i1==i2&&j1==j2){
        if(grid[i][j]!=-1)
        return grid[i][j];
        return INT_MIN;
    }
    else{
        int o1 = grid[i1][j1];
        int o2 = grid[i2][j2];
        if(o1==-1||o2==-1)return INT_MIN;
        return o1+o2;
    }
}


int dp(int i,int j,int k,int n,vector<vector<int>>& grid){
    if(i>=n||j>=n||k>=n)
        return INT_MIN;
    
    if(i==n-1&&j==n-1&&k==n-1){
        return grid[n-1][n-1];
    }
    
    if(memo[i][j][k]!=-1)return memo[i][j][k];
    int ans;
    int cc = cond(i,j,k,n,grid);
    // int cc=0;
    if(cc==INT_MIN)
    ans=INT_MIN;
    else
    ans=max({dp(i+1,j,k,n,grid),dp(i,j+1,k,n,grid),dp(i+1,j,k+1,n,grid),dp(i,j+1,k+1,n,grid)});
    if(ans!=INT_MIN){
        ans+=cc;
    }
    memo[i][j][k]=ans;
    return ans;
}



int cherryPickup(vector<vector<int>>& grid) {
    int n=grid.size();        
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                memo[i][j][k]=-1;
            }
        }
    }
    // return 0;
    int a = dp(0,0,0,n,grid);
    if(a!=INT_MIN)return a;
    return 0;
}

};