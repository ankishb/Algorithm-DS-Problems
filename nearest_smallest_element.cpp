
#include <bits/stdc++.h>
using namespace std;

void prevSmaller(vector<int> &A){
	int lower_b, min;
	vector<int> ans;
	ans.push_back(-1);
	for(int i=1; i<A.size(); i++){
		int j = i-1;
		min = A[i];
		while(j>=0){
			if(A[j]<A[i]){
				min = A[j];
				break;
			}
			else{
				j--;
			}
		}
		min = (min<A[i])?min:-1;
		ans.push_back(min);
	}

	cout<<"\n ---- vector ---- \n";
	for(int i=0; i<ans.size(); i++){
		cout<<ans[i]<<" ";
	}
	cout<<"\n ---- vector ---- \n";
}

void optimal(vector<int> &A){
	vector<int> ans;
	stack<int> stacking;
	ans.push_back(-1);
	stacking.push(A[0]);
	for(int i=1; i<A.size(); i++){
		while(!stacking.empty() && A[i]<stacking.top()){
			stacking.pop();
		}
		if(stacking.empty()){
			ans.push_back(-1);
		}
		else{
			ans.push_back(stacking.top());
		}
		stacking.push(A[i]);
	}

	cout<<"\n ---- vector ---- \n";
	for(int i=0; i<ans.size(); i++){
		cout<<ans[i]<<" ";
	}
	cout<<"\n ---- vector ---- \n";
}


int main()
{
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<int> vect;
		int el;
		for(int i=0; i<n; i++){
			cin>>el;
			vect.push_back(el);
		}
		
		// prevSmaller(vect);
		optimal(vect);
	}
	return 0;
}