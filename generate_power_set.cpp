
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
	string str;
	cin>>str;
	int len = str.length();
	int total_cases = pow(2, len);

	sort(str.begin(), str.end());
	cout<<"Printing All Possible soution in lexical order: "<<endl;
	for(int i=0; i<total_cases; i++){
		int cur_case = i;
		for(int j=0; j<len; j++){
			if(cur_case&1){// if last bit is set, then print
				cout<<str[j];
			}
			cur_case = cur_case>>1;
		}
		cout<<endl;
	}
	cout<<endl<<"======================="<<endl;
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