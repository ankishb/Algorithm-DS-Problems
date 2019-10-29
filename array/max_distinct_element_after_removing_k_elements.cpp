#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vii vector<vector<int>>
#define f first
#define s second
#define ll long long int 

// creat a signature function here

int main()
 {
	int test;
	cin>>test;
	while(test--){
	    // input and call signature function
	    int n, k, el, dup = 0;
	    cin>>n>>k;
	    unordered_set<int> uni;
	    for(int i=0; i<n; i++){
	        cin>>el;
	        if(uni.count(el) != 0){
	            dup++;
	            continue;
	        }
	        uni.insert(el);
	    }
	    int size = uni.size();
	    if(k > dup) cout<<size-(k-dup)<<endl;
	    else cout<<size<<endl;
	}
	return 0;
}