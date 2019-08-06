// You are given two numbers A and B. Write a program to count number of bits needed to be flipped to convert A to B.

#include <bits/stdc++.h>
using namespace std;

void swap_nibble(){
	int n;
	cin>>n;
	cout<<"left nibble: "<<(n&240)<<endl;
	cout<<"right nibble: "<<(n&15)<<endl;
	cout<<"New Byte: "<<(((n&15)<<4) | ((n&240)>>4))<<endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		swap_nibble();
	}
	return 0;
}