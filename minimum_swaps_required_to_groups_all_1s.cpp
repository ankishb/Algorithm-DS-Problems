
#include <bits/stdc++.h>
using namespace std;

void get_min_swaps(vector<int> A)

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n; cin>>n;
		vector<int> A;
		for(int i=0; i<n; i++){
			cin>>A[i];
		}
		get_min_swaps(A);
	}
}