
#include <bits/stdc++.h>
using namespace std;

/* Approach:
1. iterate from left to right and collect fuel at each checkpoint
2. if fuel < 0, put in out ans and re-init fuel to 0
*/
// new try
void solve(){
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int fuel = 1, cur_fuel = 0;
    for(int i=0; i<n; i++){
        cur_fuel += arr[i];
        if(cur_fuel < 0){
            fuel += abs(cur_fuel);
            cur_fuel = 0;
        }
    }
    cout<<fuel<<endl;
}

// old approach
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