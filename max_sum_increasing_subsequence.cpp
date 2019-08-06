
#include <bits/stdc++.h>
using namespace std;

void get_max_sum_longest_subsequence(int arr[], int n){
	int result[n];
	for(int i=0; i<n; i++){
		result[i] = arr[i];
	}

	int max_length = -1;
	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++){
			if(arr[i] >= arr[j]){
				result[i] = max(result[j]+arr[i], result[i]);
				// max_length = (max_length > result[i]) ? max_length : result[i];
			}
		}
	}

	cout<<"================"<<endl;
	for(int i=0; i<n; i++){
		cout<<result[i]<<" ";
		max_length = (max_length > result[i]) ? max_length : result[i];
	}
	cout<<endl<<"================"<<endl;
	cout<<max_length<<endl;
}


int main()
{
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}

		get_max_sum_longest_subsequence(arr, n);
	}
	return 0;
}