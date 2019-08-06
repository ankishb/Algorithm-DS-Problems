/*
Approach:
Track parenthese count as open_count and close_count
	1. If open_count < n, put a open parenthese
	2. if open_count > close_count, put a close parenthese
*/


class Solution {
public:
	void get_parentheses(vector<string> &store, string cur, int open_count, int close_count, int n){
		if(open_count == close_count && open_count == n){
			store.push_back(cur);
			return ;
		}
		if(open_count < n){
            // cur = cur+"(";
			get_parentheses(store, cur+"(", open_count+1, close_count, n);
		}
		if(open_count > close_count){
			get_parentheses(store, cur+")", open_count, close_count+1, n);
		}
	}

    vector<string> generateParenthesis(int n) {
        int open_count = 0;
        int close_count = 0;
        string cur = "";
        vector<string> store;
        get_parentheses(store, cur, open_count, close_count, n);
        return store;
    }
};



#include <bits/stdc++.h>
using namespace std;

void rec(int n, int open, int close, vector<string> &ans, vector<char> &temp){
	if(temp.size() == 2*n){
		string s(temp.begin(), temp.end());
		ans.push_back(s);
		return ;
	}
	
	if(open<n){
		temp.push_back('(');
		rec(n, open+1, close, ans, temp);
		temp.pop_back();
	}

	if(open>close){
		temp.push_back(')');
		rec(n, open, close+1, ans, temp);
		temp.pop_back();
	}

}

vector<string> get_all_parenthesis(int n){
	vector<string> ans;
	vector<char> temp;
	if(n==0){
		return ans;
	}
	rec(n, 0, 0, ans, temp);

	return ans;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;

		vector<string> ans;
		ans = get_all_parenthesis(n);
		cout<<"\n Gray Code \n";
		for(int i=0; i<ans.size(); i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

