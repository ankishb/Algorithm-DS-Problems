// An array is called Bitonic if it is comprises of an increasing sequence of integers followed immediately by a decreasing sequence of integers.
// Given a bitonic array A of N distinct integers. Find a element X in it.

// Note that: Here array is not like [3,4,5,1,2], but sth like [3,4,5,2,1]

/*
Approach: (Follow binary search O(logn) )
1. if the mid is greater than left & right, we found ans
2. if mid is greater than left & smaller than right, update left
3. if mid is lesser than left & lesser than right, update right
*/

#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)

void solve(){
	int n;
	cin>>n;
	vector<int> vect(n, 0);
	for(int i=0; i<n; i++){
		cin>>vect[i];
	}

    bool found_ans = false;
	int left_idx=0, right_idx=n-1, mid;
	while(left_idx <= right_idx){
		mid = floor((left_idx	+ right_idx)/2);
		if(left == right == mid) break;
		if(vect[mid]>vect[left_idx] && vect[mid]>vect[right_idx]){
			cout<<mid<<" "<<vect[mid]<<endl;
			found_ans = true;
			break;
		}
		// increasing seq, update left
		else if(vect[left_idx]<vect[mid] && vect[mid]<vect[right_idx]){
			left_idx = mid;
		}
		else{
			right_idx = mid;
		}
	}
	if(!found_ans) cout<<-1<<endl;
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