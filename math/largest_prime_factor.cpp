
// new try
#define ll long long int
ll largest_prime_factor(ll n){
    ll ans = 1;
    bool divide;
    for(ll i=2; i<=sqrt(n); i++){
        
        divide = false;
        while(n%i == 0){
            n = n/i;
            // cout<<n<<" ";
            divide = true;
        }
        if(divide) ans = i;
    }
    if(n > 2) ans = n;
    return ans;
}


// old one
#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)
typedef long long int ll;

// print all prime factor of given number
void solve(){
    ll n, ans; 
    cin>>n;
    while(n > 0 && n%2 == 0){
        n = n/2;
        ans = 2;
    }
    for(int i=3; i<=sqrt(n); i++){
        while(n > 0 && n%i == 0){
            n = n/i; 
            ans = i;
        }
    }
    ans = (ans > n) ? ans : n;
    cout<<ans<<endl;
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