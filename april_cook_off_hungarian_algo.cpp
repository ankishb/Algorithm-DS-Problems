// Given a positive integer N, print count of set bits in it. For example, if the given number is 6(binary: 110), output should be 2 as there are two set bits in it. 

#include <bits/stdc++.h>
using namespace std;
int T[500][500];

bool check_if_valid(int n){
	int arr[n] = {0};
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(T[i][j] == 0){
				if(arr[i] == 0){
					arr[i] = 1;
				}
				else{
					return false;
				}
			}
		}
	}
	for(int i=0; i<n; i++){
		if(arr[i] == 0){
			return false;
		}
	}
	return true;
}

int main()
{
	int test;
	cin>>test;

	while(test--){
		int n;
		cin>>n;

		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin>>T[i][j];
			}
		}
		if(check_if_valid(n)){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
	return 0;
}