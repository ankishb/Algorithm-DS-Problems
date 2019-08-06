3 0 9 1 3 2 5

Here you should begin processing the first order right away. You will complete all orders with total wait time of 35 with an average wait time of 35/3 = 11. If you just don't process the first order and wait for the 2nd order then you can finish all orders with a total wait time of 28 with an average of 28/3 = 8. The correct answer is 11 and not 8 for this problem.

Now here's the HINT (Read only after you have struggled with the problem for more than an hour):

a. Maintain two queues. One for all the orders prioritized by arrival time. The second one for all orders prioritized by completion time with the shortest order at the head of the queue.

b. Read all the orders in sequence and fill the arrival time queue (first queue).

c. Have a loop that ticks time.

d. For every time tick in the loop see if there are any orders that have arrived by this time from the first queue. If there are then transfer them to the second queue (ordered by completion time) for processing (cooking).

e. Pick the top order from the second queue to process (cook the pizza). If you process the order then tick the time by the time it takes to cook that pizza. If you didn't have any order to process then tick the time by 1 unit. Keep track of total time to process the orders as you process them.

e. Repeat Steps b to e till all orders are processed.

f. Compute the average wait time and print it.

Hope this much explanation is ok to post on the forum. If this is too much let me know and I can condense it further. If there is an easier way to solve the problem then let me know that too.


#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct Type
{
	int t, l;
};

struct cmp
{
	bool operator() (Type& a, Type& b)
	{
		return a.l > b.l;
	}
};

bool operator < (Type a, Type b)
{
	return a.t < b.t;
}

vector<Type> v;
priority_queue<Type, vector<Type>, cmp> pq;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t, l;
		cin >> t >> l;
		Type tmp; tmp.t = t; tmp.l = l;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	for(auto itr : v){
		Type best = itr;
		cout<<best.t<<" : "<<best.l<<endl;
	}
}

// #include <bits/stdc++.h>
// using namespace std;

// class time_stamp{
// public:
// 	int start_time;
// 	int total_time;

// 	time_stamp(int start, int total){
// 		start_time = start;
// 		total_time = total;
// 	}
// };

// bool operator<(const time_stamp &p1, const time_stamp &p2){
// 	return p1.total_time > p2.total_time;
// }

// int optimize_awaiting_time(vector<vector<int> >customers){
// 	priority_queue<time_stamp> pq;
// 	for(int i=0; i<customers.size(); i++){
// 		pq.push(time_stamp({customers[i][0], customers[i][1]}));
// 	}

// 	// cout<<"\nTesting priority_queue\n";
// 	// while(!pq.empty()){
// 	// 	time_stamp temp = pq.top();
// 	// 	cout<<temp.start_time<<" : "<<temp.total_time<<endl;
// 	// 	pq.pop();
// 	// }
// 	// cout<<"\n-----------\n";

// 	int ans = 0;
// 	int ans1 = 0;
// 	time_stamp prev = pq.top();
// 	ans1 = (prev.total_time - prev.start_time);
// 	ans = ans1;
// 	pq.pop();
// 	while(!pq.empty()){
// 		time_stamp cur = pq.top();
// 		pq.pop();
// 		ans1 += (cur.total_time - (cur.start_time - prev.start_time));
// 		prev = cur;
// 		ans += ans1;
// 	}
// 	return ans/customers.size();
// }


// int main()
// {
// 	int test=1;
// 	// cin>>test;
// 	while(test--){
// 		int n;
// 		cin>>n;
// 		int el1, el2;
// 		vector<vector<int> > vect;
// 		vector<int> temp;
// 		while(n--){
// 			cin>>el1>>el2;
// 			temp.clear();
// 			temp.push_back(el1);
// 			temp.push_back(el2);
// 			vect.push_back(temp);
// 		}

// 		int ans = optimize_awaiting_time(vect);
// 		cout<<ans<<endl;
// 	}
// 	return 0;
// }








//minimum-average-waiting-time.cpp
//Minimum Average Waiting Time
//Weekly Challenges - Week 6
//Author: derekhh

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct Type
{
	int t, l;
};

struct cmp
{
	bool operator() (Type& a, Type& b)
	{
		return a.l > b.l;
	}
};

bool operator < (Type a, Type b)
{
	return a.t < b.t;
}

vector<Type> v;
priority_queue<Type, vector<Type>, cmp> pq;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t, l;
		cin >> t >> l;
		Type tmp; tmp.t = t; tmp.l = l;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	long long cur_t = 0;
	long long tot = 0;
	int idx = 0;

	while (true)
	{
		int i;
		for (i = idx; i < n; i++)
		{
			if (v[i].t <= cur_t)
				pq.push(v[i]);
			else
			{
				idx = i;
				break;
			}
		}

		if (i == n) idx = n;

		if (!pq.empty())
		{
			Type tmp = pq.top();
			tot += cur_t + tmp.l - tmp.t;
			cur_t += tmp.l;
			pq.pop();
		}

		else
		{
			if (idx != n)
				cur_t = v[idx].t;
		}

		if (idx == n && pq.empty()) break;
	}

	cout << tot / n << endl;
	return 0;
}