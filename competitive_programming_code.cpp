#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<n;i++)
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define init(x, a) memset(x, a, sizeof(x))
 
const int mod = 1000000007;
 
int mpow(int base, int exp); 
const int N = 1e5+4;
vi g[N];
 
int k;
int dfs(int u){
	int i,j;
	
	int ans = 0;
	fo(i, g[u].size()){
		int v = g[u][i];
		ans = max(ans, 1+dfs(v));
	}
	return ans;
}
string f(string a){
	int i, n = a.length();
	fo(i, n)
		if (a[i]>='a')
			a[i] -= 'a'-'A';
	return a;
}
int main()
{
	int i, n, m;
	cin>>n;
	map<string, int>A;
	fo(i, n){
		string a, b, c;
		cin>>a>>c>>b;
		a = f(a);
		b = f(b);
		if (A.find(a)==A.end()){
			A[a] = A.size()+1;
		}
		if (A.find(b)==A.end()){
			A[b] = A.size()+1;
		}
		
		g[A[b]].pb(A[a]);
	}
	cout<<1+dfs(A["POLYCARP"])<<endl;
	return 0;
} 
 
int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}