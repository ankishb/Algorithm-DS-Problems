// https://www.codechef.com/COOK106B/problems/REACTION

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int test;
	cin>>test;

	while(test--){
		unsigned long l, r, g;
		cin>>l>>r>>g;

		// double lg=l*1.0/g*1.0, rg=r*1.0/g*1.0;
		cout<<floor(r*1.0/g)-ceil(l*1.0/g)+1<<"\n";
		// cout<<(rg)<<" "<<(lg)<<"\n";
	}
	return 0;
}