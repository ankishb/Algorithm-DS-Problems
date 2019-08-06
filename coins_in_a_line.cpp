// There are N coins (Assume N is even) in a line. Two players take turns to take a coin from one of the ends of the line until there are no more coins left. The player with the larger amount of money wins. Assume that you go first.

/*
Approach:
Rec(player = you, start, end) = 
        |
    max | v(end) + Rec(opposite_player, start, end - 1)  
        |
        | v(start) + Rec(opposite_player, start + 1, end)
        |
Rec(player = opposite, start, end) = 
        |
    min | Rec(you, start, end - 1)
        |
        | Rec(you, start + 1, end)
        |
*/

int Solution::maxcoin(vector<int> &A) {
    int n = A.size();
    int T[n][n];
    
    int j;
    for(int k=0; k<n; k++){
        for(int i=0; i<n-k; i++){
            // cout<<"("<<i<<", "<<i+k<<") ";
            j = i+k;
            if(i==j) T[i][j] = A[i];
            else if(i+1 == j) T[i][j] = max(A[i], A[j]);
            else{
                int chose_i = A[i] + min(T[i+2][j], T[i+1][j-1]);
                int chose_j = A[j] + min(T[i][j-2], T[i+1][j-1]);
                T[i][j] = max(chose_i, chose_j);
            }
        }
        // cout<<endl;
    }
    
    // for(int i=0; i<n; i++){
    //     // for(int j=0; j<i; j++) cout<<"00 ";
    //     for(int j=0; j<n; j++) cout<<T[i][j]<<" ";
    //     cout<<endl;
    // }
    return T[0][n-1];
}
