// Find total number of Squares/Rectangles in a N*N cheesboard.

// https://practice.geeksforgeeks.org/problems/rectangles-in-nn-board/0/?ref=self

#include <bits/stdc++.h>
using namespace std;

void find_squares(){
	int n;
	cin>>n;
	cout<<n*(n+1)*(2*n+1)/6<<endl;
}

void incorrect_find_rectangles(){
	int n;
	cin>>n;
	long long int s_0=0, s_1=0;
	for(int i=0; i<n; i++){
		s_1 = s_0 + n*n*(n-1);
		s_0 = s_1;
	}
	cout<<s_0<<endl;
}

void find_rectangles(){
	int n;
	cin>>n;
	unsigned long long int rect=0, sqr=0;
	rect = n*(n-1)/2;
	rect = rect*rect;
	sqr = n*(n+1)*(2*n+1)/6;
	rect = rect - sqr;
	// ans = ((n*(n-1)/2)^2)-(n*(n+1)*(2*n+1)/6);
	cout<<rect<<endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		// find_squares();
		find_rectangles();
	}
	return 0;
}