
// newest one
int Solution::canJump(vector<int> &A) {
    int n = A.size(), energy = A[0];
    for(int i=1; i<n; i++){
        if(energy == 0) return false;
        energy--;
        if(energy < A[i]){
            energy = A[i];
        }
    }
    return (energy >= 0);
}


// new try and best optimal
/*
1. We iterate over array, while holding current jump size
2. When we jump, we check if we can have more enegy than current(holding)
3. We fail, if we have 0 or neg enegy at any step and we don't make to the end
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return true;
        int energy = nums[0];
        for(int i=1; i<n; i++){
            energy--;
            if(energy < 0) return false;
            energy = max(energy, nums[i]);
        }
        return (energy >= 0) ? true : false;
    }
};


// old one optimal
int Solution::canJump(vector<int> &A) {
    if(A.size() == 0 || A.size() == 1) return 1;
    
    vector<int> temp(A.size(), 0);
    int closest = A.size()-1;
    
    for(int i = temp.size()-2; i >= 0; i--){
        if(A[i] - closest + i >= 0){
            closest = i;
            temp[i] = 1;
        }
    }
    
    return temp[0];
}




// not optimal
int Solution::canJump(vector<int> &A) {
    int n = A.size();
    bool T[n][n];
    memset(T, 0, sizeof(T));
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            // if(i>0 && T[i-1][j] == false){
            //     return false;
            // }
            if(i==j || A[i]+i-j >= 0){
                T[i][j] = true;
            }
        }
    }
    return T[i-1][j-1];
}


// recursive solution
void check(vector<int> A, int i, bool *flag){
    // cout<<i<<" "<<*flag<<endl;
    if(*flag) return ;
    if(i == A.size()-1){
        *flag = true;
        return ;
    }
    for(int j=i+1; j<=i+A[i]; j++){
        check(A, j, flag);
        if(*flag) break;
    }
}
int Solution::canJump(vector<int> &A) {
    bool flag = false;
    int index = 0;
    check(A, index, &flag);
    if(flag) return 1;
    return 0;
}


