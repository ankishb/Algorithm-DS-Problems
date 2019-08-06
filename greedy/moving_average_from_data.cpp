// Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

#include <bits/stdc++.h>
using namespace std;

void print_queue(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

void get_moving_average(vector<int> nums, int k){
	queue<int> q;
	int n = nums.size();
	int avg = 0;
	for(int i=0; i<k; i++){
		q.push(i);
		avg += nums[i];
	}
	vector<double> ans;
	int front_idx;
	ans.push_back(avg);
	for(int i=k; i<n; i++){
	   // print_queue(q);
		front_idx = q.front();
		q.pop();
		avg -= nums[front_idx];
		q.push(i);
		avg += nums[i];
		cout<<avg<<" -- ";
		ans.push_back(avg);
	}

	for(int i=0; i<ans.size(); i++){
		ans[i] = ans[i]/(k*1.0);
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n; cin>>n;
		vector<int> vect(n, 0);
		for(int i=0; i<n; i++){
			cin>>vect[i];
		}
		int k;
		cin>>k;
		get_moving_average(vect, k);
	}
	return 0;
}