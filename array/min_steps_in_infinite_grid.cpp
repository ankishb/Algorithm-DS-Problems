
/*
As we can travel in all direction, which means that we can reach at any cell
by calculating manhattan distance. To cinvince yourself, look at following exp:
			4 4 4 4 4 4 4
			3 3 3 3 3 3 3
			3 2 2 2 2 2 3
			3 2 1 1 1 2 3
			3 2 1 0 1 2 3
			3 2 1 1 1 2 3
			3 2 2 2 2 2 3
			3 3 3 3 3 3 3
			4 4 4 4 4 4 4
	If we start at middle cell, we can reach at any cell as max(x, y), where x and y 
	are manhattan distances between x's and y's coordinates.
*/
int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int n = A.size(), x, y, steps = 0;
    for(int i=1; i<n; i++){
        x = abs(A[i-1] - A[i]);
        y = abs(B[i-1] - B[i]);
        steps += max(x, y);
    }
    return steps;
}
