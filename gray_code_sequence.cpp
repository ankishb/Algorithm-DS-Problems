
// new solution
vector<int> Solution::grayCode(int n) {
    if(n == 0) return {};
    vector<int> ans({0,1});
    if(n == 1) return ans;
    for(int i=2; i<=n; i++){
        int no = pow(2,i-1);
        int size = ans.size();
        for(int j=size-1; j>=0; j--){
            ans.push_back(no|ans[j]);
        }
    }
    return ans;
}




// old solution
#include <bits/stdc++.h>
using namespace std;

vector<int> get_gay_code_seq(int n){
	int total_cases = pow(2, n);
	if(n==0) return ans;
	vector<int> ans({0,1});
	if(n == 1) return ans;

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