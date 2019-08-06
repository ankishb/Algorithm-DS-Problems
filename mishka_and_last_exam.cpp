/*
1093C - Mishka and the Last Exam

Let's present the following greedy approach. The numbers will be restored in pairs (a1,an)
, (a2,an−1) and so on. Thus, we can have some limits on the values of the current pair (satisfying the criteria about sort). Initially, l=0,r=1018 and they are updated with l=ai,r=an−i+1. Let l be minimal possible in the answer. Take ai=max(l,bi−r) and r=bi−l. That way l was chosen in such a way that both l and r are within the restrictions and l is also minimal possible. If l was any greater than we would move both l limit up and r

limit down leaving less freedom for later choices.

Overall complexity: O(n)

.

Funnily enough, I coded some naive solution just to test main correct and with restriction of 109
on numbers it passed all tests in 300 ms at max. After I saw that I guessed why it worked in O(MAXVAL)
*/



#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;

const long long INF64 = 1'000'000'000'000'000'000ll;
const int N = 200 * 1000 + 13;

int n;
long long a[N], b[N];

void brute(int x, long long l, long long r){
	if (x == n / 2){
		for (int i = 0; i < int(n); i++)
			printf("%lld ", a[i]);
		puts("");
		exit(0);
	}
	
	for (long long i = l; i <= b[x] / 2; ++i){ 
		if (b[x] - i <= r){
			a[x] = i;
			a[n - x - 1] = b[x] - i;
			brute(x + 1, i, b[x] - i);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < int(n/2); i++)
		scanf("%lld", &b[i]);
	brute(0, 0, INF64);
	return 0;
}







n = int(input())
l, r = 0, 10**18
b = list(map(int, input().split()))
a = [0 for i in range(n)]
for i in range(n // 2):
	a[i] = max(l, b[i] - r)
	a[-i - 1] = b[i] - a[i]
	l, r = a[i], a[-i - 1]
print(*a)











#include <bits/stdc++.h>
using namespace std; 
typedef long long LL; 
const LL maxn = 1e5+5; 
LL a[maxn]; 
vector<LL> v; 

int main() { 
	int n; 
	cin >> n; 
	for (int i = 0; i < n / 2; i++) 
		cin >> a[i]; 
	v.push_back(0); 
	v.push_back(a[0]); 
	LL ps = 0, pe = a[0]; 
	for (int i = 1; i < n / 2; i++) { 
		if (a[i] > pe) { 
			LL pps = a[i] - pe; 
			LL ppe = pe; 
			if (pps < ps) { 
				ppe -= (ps - pps); 
				v.push_back(ps); 
				v.push_back(ppe); 
				pe = ppe; 
			}
			else { 
				v.push_back(pe); v.push_back(a[i] - pe); ps = a[i] - pe; } } else { if (0 < ps) { v.push_back(ps); v.push_back(a[i] - ps); pe = a[i] - ps; } else { v.push_back(0); v.push_back(a[i]); pe = a[i]; } } } sort(v.begin(), v.end()); for (int i = 0; i < v.size(); i++) { if (i) cout << " "; cout << v[i]; } cout << endl; return 0; } 