
#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)

void solve(){
    int n; cin>>n;
    vector<int> A(n);
    for(int i=0; i<n; i++){
        cin>>A[i];
    }
    bool smaller = true;
    for(int i=0; i<n-1; i++){
        if(smaller){
            if(A[i] > A[i+1]) swap(A[i], A[i+1]);
        }
        else{
            if(A[i] < A[i+1]) swap(A[i], A[i+1]);
        }
        smaller = 1 - smaller;
    }

    for(auto a : A){
        cout<<a<<" ";
    }
    cout<<endl;
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