
#include <bits/stdc++.h>
using namespace std;

void chocolate_distribution(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int m;
	cin>>m;

	sort(arr, arr+n);
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	int min = INT_MAX;
	int index = 0;
	for(int i=0; i<=n-m; i++){
		cout<<arr[i+m-1] - arr[i] <<" ";
		if((arr[i+m-1] - arr[i]) < min){
			index = i;
			min = arr[i+m-1] - arr[i];
		}
	}

	cout<<endl<<index<<"--"<<min<<endl;
}


int main()
{
	int test;
	cin>>test;
	while(test--){
		chocolate_distribution();
	}
}