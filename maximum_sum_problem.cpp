// Given a number n, we can divide it in only three parts n/2, n/3 and n/4 (we will consider only integer part). The task is to find the maximum sum we can make by dividing number in three parts recursively and summing up them together.
// Note: Sometimes, the maximum sum can be obtained by not dividing n.

// Input : n = 24
// Output : 27
// We break n = 24 in three parts {24/2, 24/3, 24/4} = {12, 8, 6},  now current sum is = (12 + 8 + 6) = 16
// As seen in example, recursively breaking 12 would produce value 13. So our maximum sum is 13 + 8 + 6 = 27.
// Note that recursively breaking 8 and 6 doesn't produce more values, that is why they are not broken further.

#include <bits/stdc++.h>
using namespace std;

int get_maximum_sum(int n){
	if(n < 12){
		return n;
	}
	return max(n, get_maximum_sum(n/2) + get_maximum_sum(n/3) + get_maximum_sum(n/4));
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;

		cout<<get_maximum_sum(n)<<endl;
	}
	return 0;
}