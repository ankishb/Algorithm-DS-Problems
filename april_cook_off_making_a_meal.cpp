// Given a positive integer N, print count of set bits in it. For example, if the given number is 6(binary: 110), output should be 2 as there are two set bits in it. 

#include <bits/stdc++.h>
using namespace std;

void validate_meal(){
	int n;
	cin>>n;

	cin.ignore(1);
	string str[n];
	int hash[26] = {0};
	for(int i=0; i<n; i++){
		cin>>str[i];
		for(int j=0; j<str[i].length(); j++){
			hash[str[i][j] - 'a']++;
		}
	}
	 

	// string result = "codechef";
	// for(int i=0; i<result.length(); i++){
	// 	cout<<result[i]<<"-"<<int(result[i] - 'a')<<endl;
	// }

	int codechef[] = {2,14,3,4,7,5};
	hash[2] /= 2;
	hash[4] /= 2;
	int min =  10000;
	for(int i=0; i<6; i++){
		min = (min < hash[codechef[i]]) ? min : hash[codechef[i]] ;
	}
	cout<<min<<endl;
}

int main()
{
	int test;
	cin>>test;

	while(test--){
		validate_meal();
	}
	return 0;
}