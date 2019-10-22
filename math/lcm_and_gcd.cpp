
#include <bits/stdc++.h>
#define pii pair<int,int>
#define vii vector<vector<int>>
#define f first
#define s second
#define ll long long int
using namespace std;

ll get_gcd(ll a, ll b){
    // if(b > a) swap(a, b);
    if(b == 0) return a;
    return get_gcd(b, a%b);
}

// creat a signature function here
void get_lcm_gcd(ll a, ll b){
    ll gcd = get_gcd(a, b);
    ll lcm = (a*b)/gcd;
    cout<<lcm<<" "<<gcd<<endl;
}


int main()
 {
	int test;
	cin>>test;
	while(test--){
	    // input and call signature function
	    ll a, b;
	    cin>>a>>b;
	    get_lcm_gcd(a, b);
	}
	return 0;
}