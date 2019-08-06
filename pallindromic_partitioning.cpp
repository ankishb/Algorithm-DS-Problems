// Given a string s, partition s such that every string of the partition is a palindrome.

// Return all possible palindrome partitioning of s.

#include <bits/stdc++.h>
using namespace std;

// bool check_pallindrome(string s){
// 	cout<<s<<endl;
// 	for(int i=0; i<s.length()/2; i++){
// 		if(s[i] != s[s.length()-i-1]){
// 			return false;
// 		}
// 	}
// 	return true;
// }

// vector<string> brute_force(string s){
// 	vector<string> ans;
	
// 	for(int i=0; i<s.length(); i++){
// 		// if(s[i] == s[i-1] && i>0){
// 		// 	continue;
// 		// }
// 		for(int j=0; j<s.length()-i; j++){
// 			if(check_pallindrome(s.substr(i, j+1))){
// 				// cout<<"hii \n";
// 				ans.push_back(s.substr(i, j+1));
// 			}
// 		}
// 	}

// 	return ans;
// }

bool isPalindrome(string str, int low, int high) { 
    while (low < high) { 
        if (str[low] != str[high]) 
            return false; 
        low++; 
        high--; 
    } 
    return true; 
} 
  
void allPalPartUtil(vector<vector<string> >&allPart, vector<string> &currPart, int start, int n, string str) { 
    if (start >= n){ 
        allPart.push_back(currPart); 
        return; 
    } 

    for (int i=start; i<n; i++) { 
        // If substring str[start..i] is palindrome 
        cout<<i<<"--"<<str.substr(start, i-start+1)<<endl;
        if (isPalindrome(str, start, i)) {
        	currPart.push_back(str.substr(start, i-start+1)); 

            allPalPartUtil(allPart, currPart, i+1, n, str); 
            currPart.pop_back(); 
        } 
    } 
} 
  
// vector<vector<string> > Solution::partition(string str) {
vector<vector<string> > allPalPartitions(string str) { 
    int n = str.length(); 
    vector<vector<string> > allPart; 
    vector<string> currPart;  
    allPalPartUtil(allPart, currPart, 0, n, str); 
  
    return allPart;
} 

int main()
{
	int test;
	cin>>test;
	while(test--){
		string s;
		cin>>s;

		vector<vector<string> > ans;
		ans = allPalPartitions(s);
		cout<<"\n Pallingdromic sequences \n";
		for(int i=0; i<ans.size(); i++){
			for(int j=0; j<ans[i].size(); j++){
				cout<<ans[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}







