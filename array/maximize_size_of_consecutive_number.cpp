
#include <bits/stdc++.h>
using namespace std;

int optimal_sol(vector<int> A, int k_){
    return 1;   
}
/*
int maximiseSubset(int arr[], int n, int k) 
{ 
    // Since we can always enforce the 
    // solution to contain all the K added  
    // points 
    int ans = k; 
  
    int l = 0, r = 0; 
    while (r < n) { 
  
        // increment l until the number of points  
        // that need to be placed between index l 
        // and index r is not greater than k 
        while ((arr[r] - arr[l]) - (r - l) > k)  
            l++; 
          
        // update the solution as below 
        ans = max(ans, r - l + k + 1); 
          
        r++; 
    } 
  
    return (ans); 
} 
*/
int naive_sol(vector<int> A, int k_){
    int n = A.size(), max_size = 1, cur_size, k;
    if(n == 0) return k_;
    if(n == 1) return k_+1;
    for(int i=0; i<n; i++){
        cur_size = 1;
        k = k_;
        for(int j=i+1; j<n; j++){
            if(A[j]-A[j-1]-1 > k) break;
            else{
                cur_size += (A[j]-A[j-1]-1);
                k -= (A[j] - A[j-1] - 1);
            }
            cur_size++;
        }
        if(k > 0) cur_size += k;
        // cout<<cur_size<<"\n";
        max_size = max(max_size, cur_size);
    }
    return max_size;
}

int get_max_size(vector<int> A, int k){
    return naive_sol(A, k);
    // return optimal_sol(A, k);
}

int main()
 {
	int test;
	cin>>test;
	while(test--){
	    int n, k;
	    cin>>n>>k;
	    vector<int> A(n);
	    for(int i=0; i<n; i++){
	        cin>>A[i];
	    }
	    cout<<get_max_size(A, k)<<endl;
	}
	return 0;
}