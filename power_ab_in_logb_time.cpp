// For two given positive numbers a and b. Find a^b. Output your number modulus 10^9+7.

#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)

// naive approach
void naive(){
    long long int x, y;
    cin>>x>>y;
    long long int ans=1;
    for(long long int i=0; i<y; i++){
        ans *= x;
        ans = ans%(1000000007);
    }
    cout<<ans<<endl;
}

void optimal_iterative(){
	long long int x, y;
	cin>>x>>y;
	int ans = 1;
	while(y>0){
		// if y is odd, we make it even
		if(y&1){
			ans *= x;
		}
		y = y>>1;
		x = x*x; // we take x^2
		x = x%1000000007;
	}
	cout<<ans<<endl;
}

int exponentMod(int A, int B, int C) 
{ 
    // Base cases 
    if (A == 0) 
        return 0; 
    if (B == 0) 
        return 1; 
  
    // If B is even 
    long y; 
    if (B % 2 == 0) { 
        y = exponentMod(A, B / 2, C); 
        y = (y * y) % C; 
    } 
  
    // If B is odd 
    else { 
        y = A % C; 
        y = (y * exponentMod(A, B - 1, C) % C) % C; 
    } 
  
    return (int)((y + C) % C); 
} 
void optimal_recursive(){
	int x, y;
	cin>>x>>y;
	cout<<exponentMod(x, y, 1000000007)<<endl;
}

int main()
 {
	int test;
	cin>>test;
	while(test--){
	    // naive();
	    optimal_iterative();
	    // optimal_recursive();
	}
	return 0;
}