
#include <bits/stdc++.h>
using namespace std;

string pattern(string A){
	vector<string> maping{"0","1","2","3","4","5","6","7","8","9"};
	string res = "";
	int count = 1;
	char cur = A[0];
	for(int i=1; i<=A.length(); i++){
		if(cur == A[i] && i<(A.length())){
			count++;
		}
		else{
			res += maping[count] + cur;
			cout<<count<<cur;
			cur = A[i];
			count = 1;
		}
	}
	return res;
}

string countAndSay(int A){
	if(A == 1){
		return "1";
	}
	string res = "1";
	for(int i=2; i<=A; i++){
		res = pattern(res);
	}
	return res;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		cout<<"\nresult: "<<countAndSay(n)<<endl;
	}
	return 0;
}