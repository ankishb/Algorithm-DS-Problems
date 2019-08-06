
FAMOUS PRODUCT

Given an array of integers A of size N.

Value of a subset of array A is defined as product of all prime numbers in that subset.

If subset does not have any prime number in it, value of such a subset is 1.

If subset have only one prime number in it, value of such a subset is the prime number itself.

Calculate and return Sum of values of all possible subsets of array A% (10^9 + 7).



Input Format

The first and only argument given is the integer array A.

Output Format

Calculate and return Sum of values of all possible subsets of array % (10^9+ 7).

Constraints

1 <= N <= 10^5
1 <= A[i] < 2^31
max(A[1], A[2] ,..., A[n]) - min(A[1], A[2] ,..., A[n]) <=10^6

For Example

Input 1:
    A = [3, 7]
Output 1:
    32
Explaination 1:
    Value ( [] ) = 1
    Value ( [3] ) = 3
    value ( [7] ) = 7
    value ( [3, 7] ) = 21
    answer = (1  +  3 +  7  +  21) % 1000000007 = 32

Input 2:
    A = [4, 7]
Output 2:
    16
Explaination 2:
    value ( [] ) = 1
    value ( [4] ) = 1
    value ( [7] ) = 7
    value ( [4, 7] ) = 7
    answer = (1  +  1  +  7 +  7) % 1000000007 = 16







#define pb push_back
#define mxn 1000005
#define mxnn 100005
#define mod (ll)1000000007
#define ll long long
bool prime[mxn],mark[mxn];
vector <ll> pr,b;
void seive()
{
    for(int i=0;i<mxn;i++)
    {
        prime[i] = true;
    }
    prime[0] = false;
    prime[1] = false;
    for(int i = 2;i < mxn;i++)
    {
        if(prime[i])
        {
            ll j = 2;
            while(i * j < mxn)
            {
                prime[i * j] = false;
                j++;
            }
        }
    }
    for(int i=0;i<mxn;i++)
    {
        if(prime[i])
        {
            pr.pb(i);
        }
    }
}
ll powe(ll a, ll b)
{
    ll res = 1LL;
    while(b)
    {
        if(b%2)
        {
            res = ((res % mod)*(a % mod))%mod;
            b--;
        }
        else
        {
            a = ((a % mod)*(a % mod))%mod;
            b=b/2;
        }
    }
    return res%mod;
}
int Solution::solve(vector <int> &A)
{
    seive();
    ll n,low = 1e12,high = INT_MIN;
    n = A.size();
    for(int i=0;i<n;i++)
        {
            low = min(low, (ll)A[i]);
            high = max(high,  (ll)A[i]);
        }
         ll limit = floor(sqrt(high)) + 1;
    ll m = high - low + 1;
    for(int i=0;i<mxn;i++)
    {
        mark[i] = false;
    }

    b.clear();
    ll indx = 0;
    while(pr[indx]<=limit)
    {
        b.pb(pr[indx]);
        indx++;
    }
    for (int i = 0; i < b.size(); i++)
        {
        ll loLim = floor(low / b[i]) * b[i];
        if (loLim < low)
            loLim += b[i];
        if(loLim==b[i])
            loLim += b[i];
        for (int j = loLim; j <= high; j += b[i])
            mark[j - low] = true;
        }
    ll coun = 0;
    ll ans  = 1LL;
    for(int i=0;i<n;i++)
    {
        if(!mark[A[i]-low])
        {
            ans = ( (ans%mod) * (A[i]%mod + 1))%mod;
            ans%=mod;
            coun++;
        }
    }
    ans = ((ans%mod)* (powe(2LL, n - coun)%mod))%mod;
    return ans;
}













const int N =1000005;
int mark[N];
const long long mod =1000000007;


long long modexp(long long x,long long n){
    long long r=1LL;
    while(n){
        if(n&1)
            r=(1LL*r*x)%mod;
        x=(1LL*x*x)%mod;
        n>>=1;
    }
    return r;
}

void segmentedsieve(int a,int b){
    for(int i=a; i<b+1; ++i)
        mark[i-a]=2;
    if(a==1)
        mark[0]=1;
    for(int i=2LL; i*i<=b; ++i){
        for(int j=((a-1)/i+1)*i; j<=b; j+=i){
            if(j<i*i)
                continue;
            if(j==i*i)
                mark[j-a]+=1;
            else
                mark[j-a]+=2;
        }
    }
}


int Solution::solve(vector <int> &A){
    int mx=INT_MIN,mn=INT_MAX;
    for(auto &it:A){
        assert(it<=INT_MAX&&it>=1);
        mx=max(mx,it);
        mn=min(mn,it);
    }
    int n=A.size();
    assert(n>=1&&n<=100000);
    assert(mx-mn<=1000000);
    segmentedsieve(mn,mx);
    long long ans=1LL;
    long long coun=0;
    for(int i=0; i<n; ++i){
        if(mark[A[i]-mn]==2){
            A[i]%=mod;
            ans=(1LL*ans*(A[i]%mod+1))%mod;
            ++coun;
        }
    }
    ans=(1LL*ans*modexp(2LL,n-coun))%mod;
    return (int)(ans);
    
}







const int N =1000005;
int mark[N];
const long long mod =1000000007;


long long modexp(long long x,long long n){
    long long r=1LL;
    while(n){
        if(n&1)
            r=(1LL*r*x)%mod;
        x=(1LL*x*x)%mod;
        n>>=1;
    }
    return r;
}

void segmentedsieve(int a,int b){
    for(int i=a; i<b+1; ++i)
        mark[i-a]=2;
    if(a==1)
        mark[0]=1;
    for(int i=2LL; i*i<=b; ++i){
        for(int j=((a-1)/i+1)*i; j<=b; j+=i){
            if(j<i*i)
                continue;
            if(j==i*i)
                mark[j-a]+=1;
            else
                mark[j-a]+=2;
        }
    }
}


int Solution::solve(vector <int> &A){
    int mx=INT_MIN,mn=INT_MAX;
    for(auto &it:A){
        assert(it<=INT_MAX&&it>=1);
        mx=max(mx,it);
        mn=min(mn,it);
    }
    int n=A.size();
    assert(n>=1&&n<=100000);
    assert(mx-mn<=1000000);
    segmentedsieve(mn,mx);
    long long ans=1LL;
    long long coun=0;
    for(int i=0; i<n; ++i){
        if(mark[A[i]-mn]==2){
            A[i]%=mod;
            ans=(1LL*ans*(A[i]%mod+1))%mod;
            ++coun;
        }
    }
    ans=(1LL*ans*modexp(2LL,n-coun))%mod;
    return (int)(ans);
    
}

