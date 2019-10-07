/* time: O(n^2)
1. Sort the array (also convert el to el^2)
2. Fix target, and use two pointer approach to find two element whose sum = target

Note that if you fix smaller element, this will be wrong, as we know that in a triplet
	of pythagoreous theorm, third element is greater than first two and also sum of 
	square of third is equal to square of third. [a^2 + b^2 = c^2; c > a && c > b]
*/
#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)

void solve(){
    int n; cin>>n;
    bool found = false;
    vector<int> A(n);
    for(int i=0; i<n; i++) cin>>A[i];
    sort(A.begin(), A.end());
    for(int i=0; i<n; i++) A[i] *= A[i];
    
    for(int i=n-1; i>=2 && (!found); i--){
        int l = 0, r = i-1, sum;
        while(l < r){
            sum = A[l] + A[r];
            // cout<<A[i]<<" "<<A[l]<<" "<<A[r]<<endl;
            if(sum < A[i]) l++;
            else if(sum > A[i]) r--;
            else{
                found = true;
                break;
            }
        }
    }
    if(found) cout<<"Yes\n";
    else cout<<"No\n";
}

int main()
{
	int test;
	cin>>test;
	while(test--){
	    solve();
	}
	return 0;
}