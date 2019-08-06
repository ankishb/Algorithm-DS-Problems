// Implement pow(x, n) % d.

#include <bits/stdc++.h>
using namespace std;


int power_function(int x, int n, int d){
    
    bool neg=true;
    if(n%2 == 0 && x<0){
        // its result will be +ve
        neg = false;
    }
    int last_digit = abs(x)%10;
    if(n==0){
        return 1%d;
    }
    if(last_digit == 0){
        return 0;
    }
    int div;
    if(last_digit == 1 || last_digit==5 || last_digit==6){
        div = 1;
    }
    else if(last_digit == 4 || last_digit==9){
        div = 2;
    }
    else{
        div = 4;
    }

    int power = n%div;
    if(power == 0){
        power = div;
    }
    // cout<<"power: "<<power<<endl;
    int ans = 1;
    for(int i=0; i<power; i++){
        ans = ans*last_digit;
    }
    if(neg){
        ans = d-ans;
    }
    // int ans = pow(last_digit, power);
    // cout<<"x^n: "<<ans<<endl;
    ans = ans%d;
    return ans;

}


int main()
{
	int test;
	cin>>test;
	while(test--){
		int x, n, d;
		cin>>x>>n>>d;
		cout<<power_function(x, n, d)<<endl;
	}
	return 0;
}