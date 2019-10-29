/*
We encode two value (a, b) at same place, using following trick
    a = a + (b % n) *n
    a = a + b*n
    
    b = b + (a % n)*n 
    b = b + (a + b*n)%n *n
    b = b + a*n
    
final step: a/n and b/n will give, (b, a)
*/
void Solution::arrange(vector<int> &A) {
    int n = A.size();
    for(int i=0; i<n; ++i) {
        A[i] = A[i] + (A[A[i]] % n) * n;
    }

    for(int i = 0; i < n; ++i) {
        A[i] = A[i] / n;
    }
}

