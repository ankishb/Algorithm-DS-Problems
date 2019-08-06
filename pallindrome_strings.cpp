
#include <bits/stdc++.h>
using namespace std;

// A-Z ==> 65-90
// a-z ==> 97-122
void isPalindrome(string A){
	string str = "";
	for(int i=0; i<A.length(); i++){
		int ascii = A[i];
		if((ascii>=65 && ascii<=90)){
			str += (A[i]+32);
		}
		else if((ascii>=97 && ascii<=122) || (ascii>=48 && ascii<=57)){
			str += A[i];
		}
	}
	for(int i=0; i<=ceil((str.length())/2); i++){
		if(str[i] != str[str.length()-1-i]){
			cout<<0<<endl;
			break;
		}
	}
	cout<<1<<endl;
}

int main()
{
	int test;
	cin>>test;
	cin.ignore(1);
	while(test--){
		string str;
		getline(cin, str);
		isPalindrome(str);
	}
	return 0;
}