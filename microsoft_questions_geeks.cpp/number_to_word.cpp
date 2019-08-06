
#include <bits/stdc++.h>
using namespace std;

bool custom_sort(const pair<int,int> &p1, const pair<int,int> &p2){
	return (p1.second < p2.second);
}

void solve(){
    int n;
    int el;
    vector<pair<int,int> > vp;
    for(int i=0; i<n; i++){
    	cin>>el;
    	vp.push_back(make_pair(el,i));
    }
    sort(vp.begin(), vp.end());
    for(int i=0; i<n; i++){
    	vp[i].first = i;
    }
    sort(vp.begin(), vp.end(), custom_sort);
    for(auto itr : vp){
    	cout<<itr->first<<" ";
    }
    cout<<endl;
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