


#include <bits/stdc++.h>
using namespace std;

int trailingZeroes(int no){
	int result = 0;
	while(no>5){
		result += no/5;
		no = no/5;
	}
	return result;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		cout<<trailingZeroes(n)<<endl;
	}
	return 0;
}
