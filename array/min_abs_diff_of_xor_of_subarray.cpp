#include<bits/stdc++.h>
using namespace std;

/*
Input:
2
6
12 6 20 14 38 6
7
10 16 9 34 7 46 23
Output:
16
1
*/
/*
As we need to divide the array into two subarray, 
which can be done by finding the xor of entire array 
and then in another pass, we split the array into two
piece using xor property.
*/
int get_min_abs_diff(vector<int> A){
    int n = A.size();
    int ans = INT_MAX, xor_sum = 0, cur_xor = 0;
    for(auto d : A) xor_sum ^= d;
    for(auto d : A){
        cur_xor ^= d; // add element
        xor_sum ^= d; // remove element
        ans = min(ans, abs(xor_sum - cur_xor));
    }
    return ans;
}

int main()
{
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        vector<int> A(n);
        for(int i=0; i<n; i++){
            cin>>A[i];
        }
        cout<<get_min_abs_diff(A)<<endl;
    }
    return 0;
}