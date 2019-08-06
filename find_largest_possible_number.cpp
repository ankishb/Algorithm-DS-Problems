// https://practice.geeksforgeeks.org/problems/largest-number-possible/0/?ref=self

#include <bits/stdc++.h>
using namespace std;

void get_largest_number(int n, int s){
	for(int i=0; i<n; i++){
		if(s/9 > 0){
			cout<<"9";
			s -= 9;
		}
		else if(s == 0){
		    cout<<"0";
		}
		else{
			cout<<s;
			s = 0;
		}
	}
	cout<<endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n, s;
		cin>>n>>s;
		get_largest_number(n, s);
	}
	return 0;
}



#include<bits/stdc++.h>
using namespace std;
void print(int n,int sum)
{
    if(n==1)
     {
         cout<<sum;
         return;
     }
     int m=min(sum,9);
     cout<<m;
     sum-=m;
     print(n-1,sum);
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	  int n,sum;
	  cin>>n>>sum;
	   if(9*n<sum || n>1 && sum==0)
	   {
	       cout<<-1<<endl;
	       
	   }
	   else
	   {
	    print(n,sum);
	    cout<<endl;
	   }
	}
	return 0;
}