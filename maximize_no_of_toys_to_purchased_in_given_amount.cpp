
#include <bits/stdc++.h>
using namespace std;

void purchase_max_toys(){
	int n, k;
	cin>>n>>k;
	int cost[n];
	for(int i=0; i<n; i++){
		cin>>cost[i];
	}

	sort(cost, cost+n);
	int count = 0, i=0;
	while(k>=0 && i<n){
		if(k-cost[i] > 0){
			cout<<cost[i]<<" ";
			k -= cost[i];
			count++;
			i++;
		}
		else{
			break;
		}
	}
	cout<<endl<<count<<endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		purchase_max_toys();
	}
	return 0;
}