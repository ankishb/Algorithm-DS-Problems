
#include <bits/stdc++.h>
using namespace std;

// int get_gcd(int n1, int n2){
// 	if(n1==0 || n2==0){
// 		return (n1==0)?n2:n1;
// 	}
// 	else if(n1>n2){
// 		return get_gcd(n1%n2, n2);
// 	}
// 	else{
// 		return get_gcd(n1, n2%n1);
// 	}
// }

// better, as it change the order of n1&n2
int get_gcd(int n1, int n2){
	if(n1==0 || n2==0){
		return (n1==0)?n2:n1;
	}
	return get_gcd(n2, n1%n2);
}

void get_fraction(int num1, int den1, int num2, int den2){
	// To get LCM of den1&den2, we first get GCD of them
	int den_gcd = get_gcd(den1, den2);
	int den_lcm = (den1*den2)/den_gcd;
	int num = (num1*den_lcm)/den1 + (num2*den_lcm)/den2;
	// ans is num/den_lcm, but we need compact form
	int gcd = get_gcd(den_lcm, num);
	cout<<num/gcd<<"/"<<den_lcm/gcd<<endl;
}

// 2
// 384 887 778 916
// 794 336 387 493
// Your Output is:
// 520915/406246
// 260737/82824

int main()
{
	int test;
	cin>>test;
	while(test--){
		int num1, num2, den1, den2;
		cin>>num1>>den1>>num2>>den2;
		get_fraction(num1, den1, num2, den2);
	}
	return 0;
}