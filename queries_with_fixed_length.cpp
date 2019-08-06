
#include <bits/stdc++.h>
using namespace std;

// This logic is wrong, try this one A : [ 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 ], B : 2
int find_min_max1(vector<int> vect, int qi){
	queue<int> q;
	q.push(0);
	for(int i=1; i<qi; i++){
		if(vect[i] > vect[q.back()]){
			q.push(i);
		}
	}
	int min_ans = INT_MAX;
	for(int i=qi; i<vect.size(); i++){
		min_ans = min(min_ans, vect[q.back()]);
		
		// check if the front element still exist in current query.
		if(i-q.front() >= qi){
			q.pop();
		}
		// check if current element should be inserted in queue
		if(q.empty()){
			q.push(i);
		}
		else if(vect[i] > vect[q.back()]){
			q.push(i);
		}
	}
	min_ans = min(min_ans, vect[q.back()]);
	return min_ans;
}

int find_min_max(vector<int> vect, int qi){
	int min_ans = INT_MAX;
	deque<int> dq;
	for(int i=0; i<vect.size(); i++){
		// pop-out all element from deque, which are smaller then current element
		while(!dq.empty() && vect[i]>vect[dq.back()]){
			dq.pop_back();
		}
		// now insert it
		dq.push_back(i);
		// check if the front exist in the current sliding window.
		if(i-dq.front() >= qi){
			dq.pop_front();
		}

		// fill the front as our answer
		if(i+1-qi >= 0){
			min_ans = min(min_ans, vect[dq.front()]);
		}
	}
	return min_ans;
}

int main()
{
	int n, q;
	cin>>n>>q;
	vector<int> vect(n);
	for(int i=0; i<n; i++){ cin>>vect[i]; }

	int qi;
	while(q--){
		cin>>qi;
		int ans = find_min_max(vect, qi);
		cout<<ans<<endl;
	}
	return 0;
}