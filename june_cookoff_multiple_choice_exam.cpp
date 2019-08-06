
#include <bits/stdc++.h>
using namespace std;

int get_score(string s1, string s2){
	int n = s1.length();
	int score = 0;
	for(int i=0; i<n; i++){
		if(s1[i] == s2[i]) score++;
		else if(s2[i] == 'N') continue;
		else if(s1[i] != s2[i]) i++;
	}
	return score;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		string s1, s2;
		cin>>s1>>s2;
		int score = get_score(s1, s2);
		cout<<score<<endl;
	}
	return 0;
}