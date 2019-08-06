
#include <bits/stdc++.h>
using namespace std;

void find_max_chocolate_child_ate(int k, vector<int> vect){
	priority_queue<int, vector<int>, greater<int> > pq;
	int n = vect.size();
	for(int i=0; i<n; i++){
		pq.push(vect[i]);
	}
	int sum = 0;
	int top;
	while(k-- && pq.top()>0){
		top = pq.top();
		sum += top;
		top = top/2;
		pq.pop();
		pq.push(top);
	}
	cout<<sum<<endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int k, n;
		cin>>n;
		vector<int> vect;
		while(n--){
			cin>>el;
			vect.push_back(el);
		}
		cin>>k;
		find_max_chocolate_child_ate(k, vect);
	}
	return 0;
}