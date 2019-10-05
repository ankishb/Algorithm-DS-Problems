
// new try
/*
Approach 1. Use dp (recurrence relation T[i][j] += min(left, up)
Approach 2: use queue(infact priority quueue) [memory limit exceeded]
*/
int dp_sol1(vector<vector<int> > &A) {
    int n = A.size();
    if(n == 0) return 0;
    int m = A[0].size();

    // first row
    for(int i=1; i<m; i++){
        A[0][i] += A[0][i-1];
    }
    // second col
    for(int i=1; i<n; i++){
        A[i][0] += A[i-1][0];
    }
    // iterate over all other element
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            A[i][j] += min(A[i-1][j], A[i][j-1]);
        }
    }
    return A[n-1][m-1];
}

class custom_pq{
public:
    int d, x, y;
    custom_pq(int d_, int x_, int y_):
    d(d_), x(x_), y(y_){}
};

bool operator<(const custom_pq &p1, const custom_pq &p2){
    return (p1.d > p2.d);
}

int dp_sol2(vector<vector<int> > &A) {
    int n = A.size();
    if(n == 0) return 0;
    int m = A[0].size();

    priority_queue<custom_pq> pq;
    pq.push(custom_pq(A[0][0], 0, 0));
    int x, y, d;
    while(!pq.empty()){
        custom_pq top = pq.top();
        d = top.d;
        x = top.x;
        y = top.y;
        pq.pop();
        if(x == n-1 && y == m-1) return d;
        
        if(x+1 < n) pq.push(custom_pq(d+A[x+1][y], x+1, y));
        if(y+1 < m) pq.push(custom_pq(d+A[x][y+1], x, y+1));
    }
    return -1;
}
int Solution::minPathSum(vector<vector<int> > &A) {
    // return dp_sol1(A);
    return dp_sol2(A);
}







// old one
int Solution::minPathSum(vector<vector<int> > &A) {
    int i, j;
    for(i=0; i<A.size(); i++){
        for(j=0; j<A[i].size(); j++){
            if(i==0 && j==0) continue;
            else if(i==0) A[i][j] = A[i][j-1]+A[i][j];
            else if(j==0) A[i][j] = A[i-1][j]+A[i][j];
            else A[i][j] += min(A[i-1][j], A[i][j-1]);
        }
    }
    return A[i-1][j-1];
}

// Another Approach (look at logic)
int Solution::minPathSum(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int curr = INT_MAX;
            if (i-1 >= 0) {
                curr = min(curr, A[i-1][j]);
            }
            if (j-1 >= 0) {
                curr = min(curr, A[i][j-1]);
            }
            if (curr != INT_MAX) {
                A[i][j] += curr;
            }
        }
    }
    return A[n-1][m-1];
}
