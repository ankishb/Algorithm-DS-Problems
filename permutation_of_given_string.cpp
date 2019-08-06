
#include <bits/stdc++.h>
using namespace std;

void print(vector<char> result){
	for(int i=0; i<result.size(); i++){
		cout<<result[i];
	}
	cout<<endl;
}

void permute(vector<char> char_, vector<int> count, vector<char> result, int level){
	if(result.size() == level){ // why level
		print(result);
		return;
	}

	for(int i=0; i<count.size(); i++){
		if(count[i] != 0){
			result[level] = char_[i];
			count[i]--;
			permute(char_, count, result, level+1);
			count[i]++;
		}
	}
}

void get_permuatation(string s){
	map<char, int> my_map;
	vector<char> char_;
	vector<int> count;
	vector<char> result(s.length());

	for(int i=0; i<s.length(); i++){
		my_map[s[i]]++;
	}

	map<char, int>::iterator itr;
	for(itr=my_map.begin(); itr!=my_map.end(); ++itr){
		char_.push_back(itr->first);
		count.push_back(itr->second);
	}

	permute(char_, count, result, 0);
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		string s;
		cin>>s;
		get_permuatation(s);
	}
	return 0;
}



