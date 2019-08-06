
#include <bits/stdc++.h>
using namespace std;

class Trainer{
public:
	int ith_day;
	int n_lecture;
	int sadness;

	Trainer(int x, int y, int z){
		ith_day = x;
		n_lecture = y;
		sadness = z;
	}
};

bool compare(const Trainer &t1, const Trainer &t2){
	return t1.sadness > t2.sadness;
}

int get_min_sadness(vector<Trainer> trainers, int d){
	sort(trainers.begin(), trainers.end(), compare);
	// for(auto itr : trainers){
	// 	cout<<itr.ith_day<<", "<<itr.n_lecture<<", "<<itr.sadness<<endl;
	// }
	int ans = 0;
	vector<bool> vect(d+1, 0);
	bool flag = false;

	for(auto itr : trainers){
		for(int k=0; k<itr.n_lecture; k++){
			flag = false;
			for(int i=itr.ith_day; i<d+1; i++){
				if(vect[i] == false){
					vect[i] = true;
					flag = true;
					break;
				}
			}
			if(flag == false){
				ans += itr.sadness;
			}
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test;
	cin>>test;
	while(test--){
		int n_trainers, n_days;
		cin>>n_trainers>>n_days;
		vector<Trainer> trainers;

		int di, ti, si;
		for(int i=0; i<n_trainers; i++){
			// cin>>di>>ti>>si;
			scanf("%d %d %d", &di, &ti, &si);
			Trainer trainer_i(di, ti, si);
			trainers.push_back(trainer_i);
		}
		cout<<get_min_sadness(trainers, n_days)<<'\n';
	}
	return 0;
}