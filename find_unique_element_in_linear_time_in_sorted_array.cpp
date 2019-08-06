// Given a sorted array A, size N, of integers; every element appears twice except for one. Find that element in linear time complexity and without using extra memory.

#include<iostream>
using namespace std;

int find_unique_element(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    if(arr[0] != arr[1]){
        return arr[0];
    }
    if(arr[n-1] != arr[n-2]){
        return arr[n-1];
    }
    for(int i=1; i<n-1; i++){
        if((arr[i-1] != arr[i]) && (arr[i] != arr[i+1])){
            return arr[i];
        }
    }

    // better and effecient
    // 1.
    // for(j=0;j<n;j=j+2){
    //     if(arr[j]!=arr[j+1]){
    //         break;
    //     }
    // }
    // printf("%lld\n",arr[j]);

    // 2.
    // int ans=0;
    // for(int i=0;i<n;i++)
    //     ans^=a[i];
    // cout<<ans<<endl;
}


int main()
 {
	int test;
	cin>>test;
	while(test--){
	    cout<<find_unique_element()<<endl;
	}
	return 0;
}



///// alternative solution
#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
#define f(in,n) for(int i=in;i<n;i++)
int main()
 {
    int q,n,num=0,m,p;
    cin>>q;
    while(q--)
    {
        num=INT_MIN;
        cin>>n;
        f(0,n)
        {
            cin>>m;
            if(i&1 && num==INT_MIN)
            {
                if(m!=p)
                num=p;
            }
            else
            p=m;
        }
        if(num==INT_MIN)
        cout<<m<<endl;
        else
        cout<<num<<endl;
    }
    return 0;
}