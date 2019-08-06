// Given a number N. Find a number K such that product of digits of K must be equal to N.
// Note : K must be as small as possible.

#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)

void solve(){
	int i = 12;
	double d = 4.0;
	string s = "hackerrank";
	int i1;
	double d1;
	cin>>i1;
	cin>>d1;
	string s1;
	cin.ignore(1);
	getline(cin, s1);
	cout<<i+i1<<endl;
	printf("%.1f\n", d+d1);
	cout<<s+s1<<endl;
}

// void facto(int n){
// 	for(int i=2; i<sqrt(n); i++){
// 		if(n%i == 0){
// 			return false;
// 		}
// 		else{
// 			return 
// 		}
// 	}
// }

int main()
 {
	int test;
	cin>>test;
	while(test--){
		// int n;
		// cin>>n;
		// int ans=0;
	    solve();
	}
	return 0;
}