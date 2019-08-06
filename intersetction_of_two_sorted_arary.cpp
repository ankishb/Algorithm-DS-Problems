
#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)

void solve(const vector<int> &A, const vector<int> &B){
	vector<int> ans;
	int Ai=0, Bi=0;
	int n=A.size(), m=B.size();
	while(Ai<n && Bi<m){
		if(A[Ai] < B[Bi]){
			Ai++;
		}
		else if(A[Ai] > B[Bi]){
			Bi++;
		}
		else{
			ans.push_back(A[Ai]);
			Ai++;
			Bi++;
		}
	}

	cout<<"\n ----- intersectional array ----- \n";
	loop(i, 0, ans.size()){
		cout<<ans[i]<<" ";
	}
	cout<<"\n ----- intersectional array ----- \n";
}

void intersect(const vector<int> &A, const vector<int> &B){
	int n=A.size(), m=B.size();
	if(n>=m){
		solve(A, B);
	}
	else{
		solve(B, A);
	}
}

int main()
 {
	int test;
	cin>>test;
	while(test--){
		int n, m;
		cin>>n>>m;
		vector<int> A;//(n,0);
		int el;
		loop(i, 0, n){
			cin>>el;
			A.push_back(el);
			// cin<<A[i];
		}
		vector<int> B;//(m,0);
		loop(i, 0, m){
			cin>>el;
			B.push_back(el);
			// cin<<B[i];
		}

	    intersect(A, B);
	}
	return 0;
}


