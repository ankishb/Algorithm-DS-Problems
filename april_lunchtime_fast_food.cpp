
#include <bits/stdc++.h>
using namespace std;

void maximize_profit(vector<int> current, vector<int> big, int n){
	for(int i=n-2; i>=0; i--){
		cout<<current[i]<<", "<<big[i]<<", "<<current[i+1]<<", "<<big[i+1]<<endl;
		current[i] = current[i] + max(current[i+1], big[i+1]);
		big[i] += big[i+1];
	}
	for(auto itr:current) cout<<itr<<", ";
	cout<<endl;
	for(auto itr:big) cout<<itr<<", ";
	cout<<endl;
	cout<<max(big[0], current[0])<<endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<int> current(n,0);
		vector<int> big(n,0);
		for(int i=0; i<n; i++){
			cin>>current[i]>>big[i];
		}
		maximize_profit(current, big, n);
	}
	return 0;
}