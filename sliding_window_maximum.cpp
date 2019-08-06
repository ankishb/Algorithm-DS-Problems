
#include <bits/stdc++.h>
using namespace std;

void sliding_window_max(vector<int> &A, int B){
	deque<int> dq;
	vector<int> ans;
	for(int i=0; i<B; i++){
		while(!dq.empty() && A[dq.back()] <= A[i]){
			dq.pop_back();
		}
		dq.push_back(i);
	}

	for(int i=B; i<A.size(); i++){
		ans.push_back(A[dq.front()]);
		while(!dq.empty() && dq.front()<=i-B){
			dq.pop_front();
		}
		while(!dq.empty() && A[dq.back()]<=A[i]){
			dq.pop_back();
		}
		dq.push_back(i);
	}
	ans.push_back(A[dq.front()]);

	
	cout<<"\n ---- sliding window max ----- \n";
	for(int i=0; i<ans.size(); i++){
		cout<<ans[i]<<" ";
	}
	cout<<"\n ---- sliding window max ----- \n";
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		int el;
		vector<int> vect;
		for(int i=0; i<n; i++){
			cin>>el;
			vect.push_back(el);
		}
		int k;
		cin>>k;
		sliding_window_max(vect, k);
	}
	return 0;
}