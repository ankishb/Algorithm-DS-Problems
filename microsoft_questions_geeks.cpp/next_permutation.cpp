// Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers. If such arrangement is not possible, it must be rearranged as the lowest possible order ie, sorted in an ascending order.


#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin>>n;
	vector<int> vect(n, 0);
	for(int i=0; i<n; i++){
		cin>>vect[i];
	}

	bool exist = false;
	int i;
	int min_el = vect[n-1];
	int min_idx = n-1;
	for(i=n-2; i>=0; i--){
		if(vect[i+1] < vect[i]){
			exist = true;
			break;
		}
		if(vect[i] < min_el){
			min_el = vect[i];
			min_idx = i;
		}
	}
	if(exist){
		// find the smallest item from right side and swap with element at current(ith) index. Also sort all the element after index i.
		swap(vect[i], vect[min_idx]);
		sort(vect.begin()+i+1, vect.end());
	}
	else{
		sort(vect.begin(), vect.end());
	}
	for(int i=0; i<n; i++){
		cout<<vect[i]<<" ";
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