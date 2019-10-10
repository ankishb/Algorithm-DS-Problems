int Solution::pow(int x, int n, int d) {
    if(x == 0) return 0;
    if(n == 0) return 1%d;
    bool neg = (x < 0 && n%2 == 1) ? true : false;
    x = abs(x);
    
    long long int ans = 1, xs = x;
    while(n != 0){
        if(n%2 == 1){
            ans = (ans*x)%d; 
            n--; 
        }
        else{ 
            xs = (xs*xs)%d; 
            n = n/2; 
        }
    }
    if(neg) return (ans%d + d)%d;
    return ans;
}
        //     if (n == 0) return 1 % p;

        //     long long ans = 1, base = x;
        //     while (n > 0) {
        //         // We need (base ** n) % p. 
        //         // Now there are 2 cases. 
        //         // 1) n is even. Then we can make base = base^2 and n = n / 2.
        //         // 2) n is odd. So we need base * base^(n-1) 
        //         if (n % 2 == 1) {
        //             ans = (ans * base) % p;
        //             n--;
        //         } else {
        //             base = (base * base) % p;
        //             n /= 2;
        //         }
        //     }
        //     if (ans < 0) ans = (ans + p) % p;
        //     return ans;
        // }
// // Your Input: 71045970 41535484 64735492
// // Expected output is 20805472 
// int myPow(long x, long n, long d)

// {   if(n==0){
//     return 1;
//     }
//     if(n==1){
//     return x%d;
//     }
//     if(n%2==0){
//         return (myPow((x*x)%d,n/2,d))%d;
//     }
//     return (x%d)*(myPow((x*x)%d,n/2,d))%d;
// }

// int Solution::pow(int x, int n, int d) {
// if(myPow(x,n,d)<0){
// return (myPow(x,n,d)+d)%d;}
// return myPow(x,n,d)%d;

// }









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