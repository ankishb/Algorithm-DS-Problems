
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; 
	cin>>n;
	vector<int> A(n);
	for(int i=0; i<n; i++){
		cin>>A[i];
	}
	for(auto itr : A) cout<<itr<<" ";
	cout<<endl;
	int cur_sum = 0;
	int ans = 0;
	for(int i=0; i<n; i++){
	    cur_sum += A[i];
		if(cur_sum < 0){
		    cout<<cur_sum<<" ";
			ans -= cur_sum ;
			cur_sum = 0;
		}
	}
	cout<<ans+1<<endl;
	cout<<"-----------\n";
}

int main()
 {
	int test;
	cin>>test;
	while(test--){
	    solve();
	}
	return 0;
}