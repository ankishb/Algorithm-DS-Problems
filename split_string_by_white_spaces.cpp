
#include <bits/stdc++.h>
using namespace std;

void split1(string s){
	string word = "";
	int n = s.length();
	for(int i=0; i<n; i++){
		if(s[i]==' ' && word.length()==0) continue;

		if(s[i] == ' '){
			cout<<word<<endl;
			word = "";
		}
		else{
			word += s[i];
		}
	}
	cout<<word<<endl;
}

void split2(string str){
	istringstream ss(str);
	do{
		string word;
		ss>>word;
		cout<<word<<endl;
	}
	while(ss);
}



int main()
{
	int test;
	cin>>test;
	cin.ignore(1);
	while(test--){
		string str;
		getline(cin, str);
		cout<<"------splitting by simple method-----\n";
		split1(str);
		cout<<"------splitting by string_stream-----\n";
		split2(str);
		// cout<<"splitting by using strtok\n";
		// split3(str);
	}
	return 0;
}