// https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/

#include <bits/stdc++.h>
using namespace std;

void get_permutation(string str, int left, int right, vector<string> ans){
	if(left == right){
		ans.push_back(str);
		cout<<str<<endl;
	}

	for(int i=left; i<=right; i++){
		swap(str[left], str[i]);
		get_permutation(str, left+1, right, ans);
		// swapping it back to get original one
		swap(str[left], str[i]);
	}
}

void _get_permutation(string str, int left, int right, vector<string> &ans){
	if(left == right){
		ans.push_back(str);
		cout<<str<<" ";
		// return ans;
	}

	for(int i=left; i<=right; i++){
		swap(str[left], str[i]);
		_get_permutation(str, left+1, right, ans);
		// swapping it back to get original one
		swap(str[left], str[i]);
	}
}

void __get_permutation(string str, int left, int right, set<string> &ans){
	if(left == right){
		ans.insert(str);
		cout<<str<<" ";
		// return ans;
	}

	for(int i=left; i<=right; i++){
		swap(str[left], str[i]);
		__get_permutation(str, left+1, right, ans);
		// swapping it back to get original one
		swap(str[left], str[i]);
	}
}

void solve(){
	string str;
	getline(cin, str);
	vector<string> ans;

	// get_permutation(str, 0, str.length()-1, ans);
	_get_permutation(str, 0, str.length()-1, ans);
	cout<<"\n---------"<<ans.size()<<endl;
	cout<<endl<<"-- Permuattion in lexical order -- \n";
	sort(ans.begin(), ans.end());
	for(int i=0; i<ans.size(); i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}

void solve_easy(){
	string str;
	getline(cin, str);
	set<string> ans;

	__get_permutation(str, 0, str.length()-1, ans);
	// cout<<"\n---------"<<ans.size()<<endl;
	cout<<endl<<endl<<"-- Permuattion in lexical order -- \n";
	// sort(ans.begin(), ans.end());
	set<string>::iterator it;
	for(it=ans.begin(); it!=ans.end(); ++it){
		cout<<*it<<" ";
	}
	cout<<endl;
}

int main()
{
	int test;
	cin>>test;
	cin.ignore(1);
	while(test--){
		// solve();
		solve_easy();
	}
	return 0;
}