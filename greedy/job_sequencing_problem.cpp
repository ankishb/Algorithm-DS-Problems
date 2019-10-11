
// new try
class custom_pq{
public:
    int d, p;
    custom_pq(int dead, int pro): d(dead), p(pro){}
};

bool operator<(const custom_pq &p1, const custom_pq &p2){
    return (p1.p < p2.p);
}

int Solution::solve(vector<int> &d, vector<int> &p){
    int n = d.size(), max_d = 0; // d: deadline, p: profit
    priority_queue<custom_pq> pq;
    for(int i=0; i<n; i++){
        max_d = max(max_d, d[i]);
        pq.push(custom_pq(d[i], p[i]));
    }
    vector<int> allot(max_d+1, 0);
    while(!pq.empty()){
        custom_pq top = pq.top();
        // cout<<top.d<<" "<<top.p<<endl;
        pq.pop();
        int j = top.d;
        while(j >= 1){
            if(allot[j] == 0){
                allot[j] = top.p;
                break;
            }
            j--;
        }
    }
    int max_profit = 0;
    for(auto a : allot){
        // cout<<a<<" ";
        max_profit += a;
    }
    // cout<<endl;
    return max_profit;
}




// oldest one
// Given a set of N jobs where each job i has a deadline and profit associated to it. Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. The task is to find the maximum profit and the number of jobs done.

#include <bits/stdc++.h>
using namespace std;

struct job{
	int job_id;
	int deadline;
	int profit;
};

bool compare(job a, job b){
	return (a.profit > b.profit);
}


void job_sequencing(){
	int n;// no of jobs
	cin>>n;
	vector<job> jobs(n);
	for(int i=0; i<n; i++){
		cin>>jobs[i].job_id>>jobs[i].deadline>>jobs[i].profit;
	}

	sort(jobs.begin(), jobs.end(), compare);

	// cout<<endl<<"================"<<endl;
	// for(int i=0; i<n; i++){
	// 	cout<<jobs[i].job_id<<" "<<jobs[i].deadline<<" "<<jobs[i].profit<<endl;
	// }
	// cout<<endl<<"================"<<endl;

	int min = INT_MIN;
	for(int i=0; i<n; i++){
		min = (min > jobs[i].deadline)?min:jobs[i].deadline;
	}
	cout<<endl<<"======= Job IDs ========"<<endl;
	int result[min] = {0};
	int cur_profit, j;
	for(int i=0; i<n; i++){
		cur_profit = jobs[i].profit;
		bool run_loop = true;
		j = jobs[i].deadline - 1;

		while(run_loop && j>=0){
			// cout<<"--"<<result[j];
			if(result[j] == 0){
				result[j] = cur_profit;
				cout<<jobs[i].job_id<<", ";
				run_loop = false;
			}
			else{
				j--;
			}
		}
		// cout<<endl;
	}


	// int result[n] = {0};
	// int indexes[n] = {0};
	// for(int i=0; i<n; i++){
	// 	result[i] = jobs[i].profit;
	// 	indexes[i] = i;
	// }

	// for(int i=1; i<n; i++){
	// 	for(int j=0; j<i; j++){
	// 		if(jobs[i].deadline > jobs[j].deadline){
	// 			// result[i] = max(result[i], result[j]+jobs[i].profit);
	// 			if(result[i] < result[j] + jobs[i].profit){
	// 				result[i] = result[j] + jobs[i].profit;
	// 				indexes[i] = j;
	// 			}
	// 		}
	// 	}
	// }

	cout<<endl<<"======= Profit ========"<<endl;
	for(int i=0; i<min; i++){
		if(result[i] != 0){
			cout<<result[i]<<", ";
		}
	}
	// cout<<endl<<"======= indexes ========"<<endl;
	// for(int i=0; i<n; i++){
	// 	cout<<indexes[i]<<" ";
	// }

	// int max = -1, index=0;
	// for(int i=0; i<n; i++){
	// 	if(result[i] > max){
	// 		max = result[i];
	// 		index = i;
	// 	}
	// }
	// cout<<endl<<"Max Profit: "<<max<<endl;

	// while(index>=0){
	// 	cout<<jobs[index].job_id<<" ";
	// 	if( index == indexes[index]){
	// 		break;
	// 	}
	// 	index = indexes[index];
	// }
	cout<<endl<<"=========================="<<endl;
}

// 1 2 100
// 2 1 19
// 3 2 27
// 4 1 25
// 5 3 15

// 1 4 20
// 2 1 10
// 3 1 40
// 4 1 30

int main()
{
	int test;
	cin>>test;
	while(test--){
		job_sequencing();
	}
	return 0;
}
