#include <bits stdc++.h="">
using namespace std;
int main()
{
	int a[] ={-2, 2, -3, 4, 5};
	int n = sizeof(a) / sizeof(a[0]);
	int odd_sum =-1000001;
	int even_sum =-1000000;
	for(int i=0; i<n; i++) {
		if(a[i]%2 == 0){
			even_sum = max(even_sum, max(even_sum+a[i], a[i]));
			odd_sum = max(odd_sum, odd_sum+a[i]); 
		}
		else{
			even_sum = max(even_sum, odd_sum+a[i])
			odd_sum = max(odd_sum,max(even_sum+a[i], a[i]))
		}
	}
	cout<<even_sum<<endl;
	return 0;
}