#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    n++;
    int arr[n];
    arr[0]=0;
    for (int i = 1; i < n; ++i)
    {
        cin>>arr[i];
    }
    int cost=0,ans;
    for (int i = 1; i < n; ++i)
    {
        cost+=abs(arr[i]-arr[i-1]);
    }
    ans=cost;
    for (int i = 1; i < n; ++i)
    {
        for (int j = i+1; j < n; ++j)
        {
            int temp = cost;
            if(i+1<n)
                cost-=abs(arr[i+1]-arr[i]);
            if(i-1>=0)
                cost-=abs(arr[i]-arr[i-1]);
            if(j+1<n)
            cost-=abs(arr[j+1]-arr[j]);
            if(j-1>=0)
            cost-=abs(arr[j]-arr[j-1]);
            swap(arr[i],arr[j]);
            if(i+1<n)
            cost+=abs(arr[i+1]-arr[i]);
            if(i-1>=0)
            cost+=abs(arr[i]-arr[i-1]);
            if(j+1<n)
            cost+=abs(arr[j+1]-arr[j]);
            if(j-1>=0)
            cost+=abs(arr[j]-arr[j-1]);
            ans = min(cost,ans);
            swap(arr[i],arr[j]);
            cost=temp;
        }
    }
    cout<<ans<<endl;
}