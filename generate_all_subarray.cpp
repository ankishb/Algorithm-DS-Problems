
#include <bits/stdc++.h>
using namespace std;

void brute_force_solution(int arr[], int n){
	// starting element of array
	for(int i=0; i<n; i++){
		// run a loop with increasing index, For example: first run for 1 times and then for 2, then for 3 and so on.   [1, 2, 3, 4]
		for(int j=i; j<n; j++){
			for(int k=i; k<=j; k++){
				cout<<arr[k]<<" ";
			}
			cout<<endl;
		}
	}
}

void purchase_max_toys(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}

	brute_force_solution(arr, n);
	// optimal_solution(arr, n);
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		purchase_max_toys();
	}
	return 0;
}