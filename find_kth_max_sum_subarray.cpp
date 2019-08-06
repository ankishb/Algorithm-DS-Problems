/*Submitted By:- Waqas Hamid*/
/*Codechef Nick : beginner007*/
/*Leetcode Nick : beginner007*/
/*Topcoder Nick : beginner007*/
/*Codeforces Nick : beginner7*/
 
#include<bits/stdc++.h>
#define LL long long int
#define s(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define w(t) while(t--)
#define f(i,n) for(i=0;i<n;i++)
#define fd(i,n) for(i=n-1;i>=0;i--)
#define p(a) printf("%d",a)
#define pl(a) printf("%lld",a)
#define ps(a) printf("%s",a)
#define pc(a) printf("%c",a)
#define ent printf("\n")
#define mod 1000000007
#define PI 3.14159265
#define gs getline(cin,s)
#define pb push_back
#define mp make_pair
#define INF 1e18
 
using namespace std;
 
int arr[10005];
int X[2015];
 
priority_queue< int,vector<int>,greater<int> > Q;
 
int main()
{
	int t,i,j,n,k1,k2,k3,k,x;
	sl(t);
	w(t)
	{
		sl(n);sl(k1);sl(k2);sl(k3);
		for(i=1;i<=n;i++){
    		sl(arr[i]);
    		arr[i]+=arr[i-1];
		}
		for(i=1;i<=n;i++){
			for(j=i;j<=n;j++){
				x=arr[j]-arr[i-1];
				if(Q.size()<k3){
                    Q.push(x);
                }
				else{
					if(x>Q.top()){
						Q.pop();Q.push(x);
					}
				}
			}
		}
		 k=k3;
 
		while(!Q.empty()){
			X[k--]=Q.top();
			Q.pop();
		}
		printf("%d %d %d\n",X[k1],X[k2],X[k3]);
	}
	return 0;
}
















#include<bits/stdc++.h>
 
using namespace std;
 
multiset<int> st;
vector<int> vec;
vector<int> cum;
vector<int> ans;
 
int main()
{
	int t,i,j,n,k1,k2,k3,p,q,num,tot,x;
	
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d %d %d %d",&n,&k1,&k2,&k3);
		vec.clear();
		ans.clear();
		cum.clear();
		st.clear();
		cum.resize(n+1);
		vec.resize(n+1);
		
		for(i=1;i<=n;i++){
			scanf("%d",&vec[i]);
		}
		cum[1]=vec[1];
	
		
		for(i=2;i<=n;i++){
			cum[i]=vec[i]+cum[i-1];
		}
		
		cum[0]=0;
		for(i=1;i<=n;i++){
			for(j=i;j<=n;j++){
				if(j==i){
					if(st.size()<k3){
						st.insert(cum[j]-cum[i-1]);
					}
					else{
						p=(*(st.begin()));
						if((cum[j]-cum[i-1])>p)
						{
							tot=st.count(p);
							st.erase(p);
							st.insert(cum[j]-cum[i-1]);
							if(tot>1){
								tot--;
								for(x=0;x<tot;x++){
									st.insert(p);
								}
							}
						}
					}
				}
				else{
					p=cum[j]-cum[i-1];
					if(st.size()<k3){
						st.insert(p);
					}
					else{
						q=(*(st.begin()));
						if(p>q){
							tot=st.count(q);
							st.erase(q);
							st.insert(p);
							if(tot>1){
								tot--;
								for(x=0;x<tot;x++){
									st.insert(q);
								}
							}
						}
					}
				}
			}
		}
	
		
		multiset<int>::iterator it;
		
		for(it=st.begin();it!=st.end();++it){
			ans.push_back(*it);
		}
		
		reverse(ans.begin(),ans.end());
		
		printf("%d %d %d\n",ans[k1-1],ans[k2-1],ans[k3-1]);
	}
	
	return 0;
} 