
#include <bits/stdc++.h>
using namespace std;

void count_min_cost(){
	int n;
	cin>>n;
	int lenght[n];
	for(int i=0; i<n; i++){
		cin>>lenght[i];
	}

	priority_queue<int, vector<int>, greater<int> > pq(lenght, lenght + n); 
	// now for 4 elements, we will have 3 new nodes, so run for n-1 times.
	int first, second, ans=0;
	while(pq.size()-1 > 0){
		first = pq.top();
		pq.pop();
		second = pq.top();
		pq.pop();

		ans += first + second;
		pq.push(first+second);
	}
	cout<<ans<<endl;
}

int main()
{
	int test;
	cin>> test;
	while(test--){
		count_min_cost();
	}
	return 0;
}