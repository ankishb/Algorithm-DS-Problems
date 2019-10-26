
/*
We don't need to define "A[l]+A[l+1] == A[r]".
This will be taken care by "A[l] < A[r]" automatically 
in next step. Same case is with other-way around.
*/
int get_min_op(vector<int> A){
    int n = A.size();
    int l = 0, r = n-1, count = 0;
    while(l < r){
        if(A[l] == A[r]){
            l++; r--;
        }
        else if(A[l] < A[r]){
            count++;
            A[l+1] += A[l];
            l++;
        }
        else if(A[l] > A[r]){
            count++;
            A[r-1] += A[r];
            r--;
        }
    }
    return count;
}