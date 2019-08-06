// Given a positive integer N, print count of set bits in it. For example, if the given number is 6(binary: 110), output should be 2 as there are two set bits in it. 

#include <bits/stdc++.h>
using namespace std;

void get_counts(int n){
	int count = 0;
	while(n>0){
		n = n&(n-1);
		count++;
	}
	cout<<count<<endl;
}

int main()
{
	int test;
	cin>>test;

	while(test--){
		int n;
		cin>>n;

		get_counts(n);
	}
	return 0;
}