
#include <bits/stdc++.h>
using namespace std;

void left_rotate(int n, int k){
    k = k%16;
    while(k > 0){
        int bit = (n & (1 << 15));
        n = n<<1;
        if(bit == 1) n += 1;
        k--;
    }
    cout<<n<<endl;
}
void right_rotate(int n, int k){
    k = k%16;
    while(k > 0){
        int bit = (n & 1);
        n = n>>1;
        if(bit == 1) n = n|(1<<15);
        k--;
    }
    cout<<n<<endl;
}

void solve(){
    int n, k;
    cin>>n>>k;

    left_rotate(n, k);
    right_rotate(n, k);
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