// https://www.interviewbit.com/problems/prime-sum/

#include <bits/stdc++.h>
using namespace std;

bool check_prime(int no){
	if(no == 2 || no==3){
		return true;
	}
	for(int i=2; i<=sqrt(no); i++){
		if(no%i == 0){
			return false;
		}
	}
	return true;
}

void prime_sum(int sum){
	vector<int> ans;
	for(int i=2; i<=sum/2; i++){
		if(check_prime(i)){
			if(check_prime(sum-i)){
				ans.push_back(i);
				ans.push_back(sum-i);
				break;
			}
		}
	}

	cout<<ans[0]<<" "<<ans[1]<<endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int sum;
		cin>>sum;
		prime_sum(sum);
	}
	return 0;
}