#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    int odd = 0; //first bit from left(2nd last from right)
    int even= 0; //second bit from left(last from right)
    int mul = 1;
    for(int i=0; i<16; i++){
        if(i%2 == 0) even += mul;
        if(i%2 == 1) odd  += mul;
        mul *= 2;
    }
    int o = n&odd;
    int e = n&even;
    o = o>>1;
    e = e<<1;
    cout<<(o|e)<<endl;
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