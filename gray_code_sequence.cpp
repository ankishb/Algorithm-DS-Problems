
#include <bits/stdc++.h>
using namespace std;

vector<int> get_gay_code_seq(int n, vector<int> &ans){
	int total_cases = pow(2, n);
	if(n==0){
		return ans;
	}

	ans.push_back(0);
	ans.push_back(1);
	if(n == 1){
		return ans;
	}

	int digit;
	for(int bits_len=2; bits_len<=n; bits_len++){
		cout<<bits_len<<" ";
		for(int i=ans.size()-1; i>=0; i--){
			// cout<<ans[i]<<" ";
			digit = ans[i] + pow(2, bits_len-1);
			ans.push_back(digit);
		}
	}

	return ans;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;

		vector<int> ans;
		get_gay_code_seq(n, ans);
		cout<<"\n Gray Code \n";
		for(int i=0; i<ans.size(); i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}