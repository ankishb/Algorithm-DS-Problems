// Given a sorted array of distinct elements and an integer k. The array elements denote positions of points on 1-D number line, find the maximum size of subset of points that can have consecutive values of points which can be formed by placing another k points on the number line.

#include <bits/stdc++.h>
using namespace std;

// brute force solution
	// ((arr[right_idx] - arr[left_idx]) - (right_idx - left_idx)) <= k
	// This will check how many number are there in between right_idx-left_idx and diff between actual indices, will tells about the missing number, which will be compared with the k, if we can change these many numbers.

void brute_force_solution(int arr[], int n, int k){
	int count = 0;
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			if(((arr[j] - arr[i]) - (j-i)) <= k){
				count = max(count, j-i+k+1);
			}
		}
	}
	cout<<count<<endl;
}

void optimal_solution(int arr[], int n, int k){
	int count = 0;
	int i=0, j=0;
	while(j<n){
		if(((arr[j] - arr[i]) - (j-i)) > k){
			i++;
		}
		count = max(count, j-i+k+1);
		j++;
	}
	cout<<count<<endl;
}

void maximize_size(){
	int n, k;
	cin>>n>>k;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}

	// brute_force_solution(arr, n, k);
	optimal_solution(arr, n, k);
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		maximize_size();
	}
	return 0;
}