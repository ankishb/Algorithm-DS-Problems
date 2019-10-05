
// new try
bool custom_sort(const vector<int> &v1, const vector<int> &v2){
    return (v1[1] < v2[1]) || (v1[1] == v2[1] && v1[0] < v2[0]);
}

void compute_max_profit(vector<vector<int> > A){
    int n = A.size();
    vector<int> profit;
    for(auto v : A){
        profit.push_back(v[2]);
    }
    sort(A.begin(), A.end(), custom_sort);
    
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(A[i][0] >= A[j][1]){
                profit[i] = max(profit[i], profit[i]+A[j][2]);
            }
        }
    }
    int max_profit = 0;
    for(auto p : profit){
        max_profit = max(max_profit, p);
    }
    cout<<max_profit<<endl;
}

// old one
#include <bits/stdc++.h>
using namespace std;

bool compare_by_second(const vector<int> &v1, const vector<int> &v2){
	return (v1[1] < v2[1]);
}

void compute_max_profit(vector<vector<int> > time_line, int n){
	cout<<endl<<"========= BEFORE ======="<<endl;
	for(int i=0; i<time_line.size(); i++){
		for(int j=0; j<time_line[0].size(); j++){
			cout<<time_line[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"================"<<endl;

	sort(time_line.begin(), time_line.end(), compare_by_second);
	cout<<"========= AFTER ======="<<endl;
	for(int i=0; i<time_line.size(); i++){
		for(int j=0; j<time_line[0].size(); j++){
			cout<<time_line[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"================"<<endl;

	int final_result[n] = {0};
	// fill profit in final_result
	for(int i=0; i<n; i++){
		final_result[i] = time_line[i][2];
	}

	for(int i=0; i<n; i++){
		cout<<final_result[i]<<" ";
	}
	cout<<endl;
	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++){
			// compare if finsih time of j is smaller and equal to start time of i.
			if(time_line[j][1] <= time_line[i][0]){
				final_result[i] = max(final_result[i], final_result[j]+time_line[i][2]);
				cout<<j<<" "<<i<<" == ";
				for(int i=0; i<n; i++){
					cout<<final_result[i]<<" ";
				}
				cout<<endl;
			}
		}
	}

	cout<<"======== Resulting Array ========"<<endl;
	int max = -1;
	for(int i=0; i<n; i++){
		cout<<final_result[i]<<" ";
		max = (max > final_result[i]) ? max : final_result[i];
	}
	cout<<endl<<max<<endl;
	cout<<"================"<<endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int no_of_jobs;
		cin>>no_of_jobs;

		vector<vector<int> > time_line(no_of_jobs);
		int start_time, end_time, profit;

		for(int i=0; i<no_of_jobs; i++){
			cin>>start_time>>end_time>>profit;
			time_line[i].push_back(start_time);
			time_line[i].push_back(end_time);
			time_line[i].push_back(profit);
		}

		compute_max_profit(time_line, no_of_jobs);
	}
}