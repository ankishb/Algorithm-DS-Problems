// It is the Indian version of the famous heist “The Italian Job”. N robbers have already broken into the National Museum and are just about to get inside the main vault which is full of jewels. They were lucky that just as they broke into the museum, the guard was leaving the museum for exactly G minutes. But there are other problems too. The main vault has heat sensors that if at any moment of time there are more than two people present in the vault, the alarm goes off.

// To collect the jewels, the ith robber needs to be inside the vault for exactly A[i] minutes, 0 <= i < N, in one continuous stretch. As guard will return after G minutes, they have to finish their tasks within G minutes. The robbers want to know if there exists any arrangement such that demands of each robber is satisfied and also they are not caught?

#include <bits/stdc++.h>
using namespace std;

bool check_robbed(int arr[], int n, int m){
	// n=robbers, m=free-time, arr[], robbing time for each robbers
	int map_[2] = {m, m};
	for(int i=0; i<n; i++){
		if(arr[i] > m){
			return false;
		}
		else if(map_[0] >= arr[i]){
			map_[0] -= arr[i];
		}
		else if(map_[1] >= arr[i]){
			map_[1] -= arr[i];
		}
		else{
			return false;
		}
		cout<<map_[0]<<" "<<map_[1]<<endl;
	}
	return true;
}

string indianJob(int g, vector<int> arr){
	int map_[2] = {g, g};
	for(int i=0; i<arr.size(); i++){
		if(arr[i] > g){
			return "NO";
		}
		else if(map_[0] >= arr[i]){
			map_[0] -= arr[i];
		}
		else if(map_[1] >= arr[i]){
			map_[1] -= arr[i];
		}
		else{
			return "NO";
		}
	}
	return "YES";
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int no_robbers, free_time;
		cin>>no_robbers>>free_time;

		int robbing_timeline[no_robbers];
		for(int i=0; i<no_robbers; i++){
			cin>>robbing_timeline[i];
		}

		bool flag = check_robbed(robbing_timeline, no_robbers, free_time);
		if(flag){
			cout<<"YES"; // robbing can be done
		}
		else{
			cout<<"NO";
		}
		cout<<endl;
	}
	return 0;
}