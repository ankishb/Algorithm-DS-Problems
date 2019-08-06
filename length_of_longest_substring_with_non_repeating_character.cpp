// Given a string, find the length of the longest substring without repeating characters. For example, the longest substrings without repeating characters for “ABDEFGABEF” are “BDEFGA” and “DEFGAB”, with length 6.

#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s;
	getline(cin, s);
	int hash[26] = {0};
	int count = 0;
	int max_len = INT_MIN;
	for(int i=0; i<s.length(); i++){
		if(hash[s[i]-'a'] != 0){
			max_len = max(max_len, count);
			// int hash[26] = {0};
			i = hash[s[i]-'a'];
			memset(hash, 0, sizeof(hash));
			count = 1;
			hash[s[i]-'a'] = i+1;
			// i--; //start from current step again.
		}
		else{
			count++;
			hash[s[i]-'a'] = i+1;;
		}
	}
	max_len = max(max_len, count);
	cout<<max_len<<endl;
}

void solve2(){
	string s;
	getline(cin, s);
	
	set<char> hash;
	int i=0, j=0, max_len=0;
	while(j<s.length()){
		if(!hash.count(s[j])){
			hash.insert(s[j]);
			j++;
			max_len = max(max_len, j-i);
		}
		else{
			hash.erase(s[i]);
			i++;
		}
	}
	cout<<max_len<<endl;
}

int main()
 {
	int test;
	cin>>test;
	cin.ignore(1);
	while(test--){
	    solve();
	}
	return 0;
}





// leetcode
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool hash[256];
        memset(hash, 0, sizeof(hash));
        
        int n = s.length();
        int i=0, j=0;
        int max_len = INT_MIN;
        while(j<n){
            if(hash[s[j]] == 0){
                hash[s[j]] = 1;
                max_len = max(max_len, j-i+1);
                j++;
            }
            // character repeats, increase index i, and remove char from hash
            else{
                hash[s[i]] = 0;
                i++;
            }
        }
        return max_len;
    }
};
