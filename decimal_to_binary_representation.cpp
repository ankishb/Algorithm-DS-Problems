
// #include <boost/lexical_cast.hpp>
#include <bits/stdc++.h>
using namespace std;

string findDigitsInBinary(int no){
	string ans="", cur;
	while(no!=0){
		int rem = no%2;
		string cur = to_string(rem);
		// cur = lexical_cast<string>(rem)
		ans = cur+ans;
		no = no/2;
	}
	return ans;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int no;
		cin>>no;
		string binary = findDigitsInBinary(no);
		cout<<binary<<endl;
	}
}