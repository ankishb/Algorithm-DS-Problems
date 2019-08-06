
#include <bits/stdc++.h>
using namespace std;

void solve(){
	string str;
	cin>>str;
	int n = str.length();
	stack<char> s;
	int count = 0;

	for(int i=0; i<n; i++){
		if(s.empty() && str[i]=='}'){
			count++;
			s.push('{');
		}
		// else if(s.empty() && str[i] == '{'){
		// 	s.push('{')
		// }
		else if(str[i] == '}' && s.top()=='{'){
			s.pop();
		}
		else{
			s.push(str[i]);
		}
	}

	if(s.size()%2 == 0){
		count += s.size()/2;
	}
	else{
		count = -1;
	}
	cout<<count<<endl;
}

int main()
 {
	int test;
	cin>>test;
	while(test--){
	    solve();
	}
	return 0;
}