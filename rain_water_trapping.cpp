
#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)

void trap_water(vector<int> &A){
	int left[A.size()] = {0};
	int right[A.size()] = {0};

	left[0] = A[0];
	for(int i=1; i<A.size(); i++){
		left[i] = max(left[i-1], A[i]);
	}

	
	right[A.size()-1] = A[A.size()-1];
	for(int i=A.size()-2; i>=0; i--){
		right[i] = max(right[i+1], A[i]);
	}

	// cout<<"\n ---- left -----\n";
	// for(int i=0; i<A.size(); i++){
	// 	cout<<left[i]<<" ";	
	// }

	// cout<<"\n ---- right -----\n";
	// for(int i=0; i<A.size(); i++){
	// 	cout<<right[i]<<" ";
	// }
	// cout<<endl;


	int ans = 0;
	for(int i=0; i<A.size(); i++){
		ans += min(left[i], right[i]) - A[i];
	}

	cout<<ans<<endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		int el;
		vector<int> vect;
		loop(i, 0, n){
			cin>>el;
			vect.push_back(el);
		}
		trap_water(vect);
	}
	return 0;
}




// C++ program to find maximum amount of water that can 
// be trapped within given set of bars. 
// Space Complexity : O(1) 

#include<iostream> 
using namespace std; 

int findWater(int arr[], int n) 
{ 
	// initialize output 
	int result = 0; 
	
	// maximum element on left and right 
	int left_max = 0, right_max = 0; 
	
	// indices to traverse the array 
	int lo = 0, hi = n-1; 
	
	while(lo <= hi) 
	{ 
		if(arr[lo] < arr[hi]) 
		{ 
			if(arr[lo] > left_max) 
			// update max in left 
			left_max = arr[lo]; 
			else
			// water on curr element = max - curr 
			result += left_max - arr[lo]; 
			lo++; 
		} 
		else
		{ 
			if(arr[hi] > right_max) 
			// update right maximum 
			right_max = arr[hi]; 
			else
			result += right_max - arr[hi]; 
			hi--; 
		} 
	} 
	
	return result; 
} 

int main() 
{ 
	int arr[] = {0, 1, 2, 1, 3, 1}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout << "Maximum water that can be accumulated is "
		<< findWater(arr, n); 
} 
