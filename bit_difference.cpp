// You are given two numbers A and B. Write a program to count number of bits needed to be flipped to convert A to B.

#include <bits/stdc++.h>
using namespace std;

void check_bit_diff(){
	int a, b;
	cin>>a>>b;

	int count = 0;
	while(a != 0 || b != 0){
		if((a&1) != (b&1)){
			count++;
		}
		a = a>>1;
		b = b>>1;
	}
	cout<<count<<endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		check_bit_diff();
	}
}