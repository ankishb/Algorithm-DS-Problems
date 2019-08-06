
#include<bits/stdc++.h>
using namespace std;

string check_balanced_brackets(string str){
	stack<char> s;
	map<char, char> my_map;
	my_map[']'] = '[';
	my_map['}'] = '{';
	my_map[')'] = '(';

	for(int i=0; i<str.length(); i++){
		if(str[i]=='[' || str[i]=='{' || str[i]=='('){
			s.push(str[i]);
		}
		else{
			char pair = my_map[str[i]];
			if(s.empty()){
			    return "not balanced";
			}
			else if(s.top() == pair){
				s.pop();
			}
			else{
				return "not balanced";
			}
		}
	}
    if(!s.empty()){
        return "not balanced";
    }
	return "balanced";
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		string s;
		cin>>s;
		string ans = check_balanced_brackets(s);
		cout<<ans<<endl;
	}
	return 0;
}