// Given an array of n integers and a positive number k. We are allowed to take any k integers from the given array. The task is to find the minimum possible value of the difference between maximum and minimum of K numbers.
/*
Approach:
1. sort the array
2. track min of (A[k+i-1] - A[i]) of each window.

Proof: The idea is to sort the array and choose k continuous integers. Why continuous? let the chosen k integers be arr[0], arr[1],,..arr[r], arr[r+x]…, arr[k-1], all in increasing order but not continuous in the sorted array. This means there exists an integer p which lies between arr[r] and arr[r+x],. So if p is included and arr[0] is removed, then the new difference will be arr[r] – arr[1] whereas old difference was arr[r] – arr[0]. And we know arr[0] <= arr[1] <= ..<= arr[k-1] so minimum difference reduces or remain same. If we perform same procedure for other p like number, we get the minimum difference.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int test; cin>>test;
	while(test--){
		int n, k; cin>>n>>k;
		vector<int> vect(n, 0);
		for(int i=0; i<n; i++){
			cin>>vect[i];
		}
		
		int min_diff = INT_MAX;
		sort(vect.begin(), vect.end());
		for(int i=k-1; i<n; i++){
		  //  cout<<(vect[i-k+1] - vect[i])<<endl;
			min_diff = min(min_diff, (vect[i] - vect[i-k+1]));
		}
		cout<<min_diff<<endl;
	}	
	return 0;
}