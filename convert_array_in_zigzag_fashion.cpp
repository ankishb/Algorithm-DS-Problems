// Given an array A (distinct elements) of size N. Rearrange the elements of array in zig-zag fashion. The converted array should be in form a < b > c < d > e < f. The relative order of elements is same in the output i.e you have to iterate on the original array only.

#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void zigzag_fashioned_array(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}

	for(int i=0; i<n-1; i++){
		if(i%2 == 0 && arr[i] > arr[i+1]){
			// ith element < (i+1)th element
			swap(&arr[i], &arr[i+1]);
		}
		else if(i%2 != 0 && arr[i] < arr[i+1]){
			swap(&arr[i], &arr[i+1]);
		}
	}

	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		zigzag_fashioned_array();
	}
	return 0;
}