// https://www.codechef.com/JULY17/problems/IPCTRAIN

#include <bits/stdc++.h>
using namespace std;

struct node{
	int Di;
	int Li;
	int Si;
};

bool compare(node A, node B){
	return (A.Si > B.Si);
}

void optimal_sadness(vector<node> trainee, int n, int d){
	sort(trainee.begin(), trainee.end(), compare);

	cout<<"\n -- sorting testing -- \n";
	for(int i=0; i<n; i++){
		cout<<trainee[i].Di<<" "<<trainee[i].Li<<" "<<trainee[i].Si<<" \n";
	}
	cout<<" -- sorting testing -- \n";

	int result[d+1] = {0};
	int filling_idx = 0;
	for(int i=0; i<n; i++){
		filling_idx = trainee[i].Di;
		for(int j=0; j<trainee[i].Li; j++){
			if(filling_idx < 1){
				// 0 is also not possible
				break;
			}
			else if(result[filling_idx] == 0 && filling_idx <=d){
				result[filling_idx] = trainee[i].Si;
				filling_idx++;
			}
		}
	}

	cout<<"\n -- Resulting Array -- \n";
	for(int i=1; i<=d; i++){
		cout<<result[i]<<" ";
	}
	cout<<"\n -- Resulting Array -- \n";
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n_trainer, n_days;
		cin>>n_trainer>>n_days;
		vector<node> trainee(n_trainer);
		int reaching_day, lecture_to_attend, sadness_rate;
		for(int i=0; i<n_trainer; i++){
			cin>>reaching_day >> lecture_to_attend >> sadness_rate;
			trainee[i].Di = reaching_day;
			trainee[i].Li = lecture_to_attend;
			trainee[i].Si = sadness_rate;
		}
		optimal_sadness(trainee, n_trainer, n_days);
	}
	return 0;
}









