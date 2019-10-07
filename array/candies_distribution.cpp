
#include <bits/stdc++.h>
using namespace std;

void candies_distribution(){
    int n, k;
    cin>>n>>k;
    int sum = (n*(n+1))/2;
    if(sum != 0) k = k%sum;
    int i = 1;
    while(k >= i){
        k -= i;
        i++;
    }
    cout<<k<<endl;
}


int main()
{
	int test;
	cin>>test;
	while(test--){
		candies_distribution();
	}
}