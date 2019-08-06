
#include <bits/stdc++.h>
using namespace std;

void reverse_string(){
	string str;
	getline(cin, str);

	vector<string> vect;
	int idx=0, count=0, i;
	for(i=0; i<str.length(); i++){
		if(str[i] == '.'){
			vect.push_back(str.substr(idx, i-idx));
			idx = i+1;
			count++;
		}
	}
	// append last word
	vect.push_back(str.substr(idx, i-idx));
	count++;

	// vector<string>::iterator it;
	// for(it=vect.end(); it!=vect.begin(); --it){
	// 	cout<<it<<'.';
	// }
	vector<string>::iterator it;
	for(int it=count-1; it>=0; it--){
		if(it == 0){
			cout<<vect[it]<<endl;
		}
		else{
			cout<<vect[it]<<'.';
		}	
	}
}

int main()
{
	int test;
	cin>>test;
	cin.ignore(1);
	while(test--){
		reverse_string();
	}
	return 0;
}