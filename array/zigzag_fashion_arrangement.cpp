
vector<int> Solution::wave(vector<int> &A) {
    vector<int> B(A);
    sort(B.begin(), B.end());
    for(int i=1; i<B.size(); i++){
        if(i%2 == 1 && B[i-1] < B[i]){
            swap(B[i-1], B[i]);
        }
        else if(i%2 == 0 && B[i-1] > B[i]){
            swap(B[i-1], B[i]);
        }
    }
    return B;
}
// Once we have sorted the array, we don't need to 
// consider even and odd indices of array.
vector<int> Solution::wave(vector<int> &A) {
    vector<int> B(A);
    sort(B.begin(), B.end());
    for(int i=1; i<B.size(); i=i+2){
        swap(B[i-1], B[i]);
    }
    return B;
}




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