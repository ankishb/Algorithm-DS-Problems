// Given a string str of lowercase alphabets, the task is to find the length of the longest sub-string of characters in alphabetical order i.e. string “dfabck” will return 3. Note that the alphabetical order here is considered circular i.e. a, b, c, d, e, …, x, y, z, a, b, c, ….

// Examples:

//     Input: str = “abcabcdefabc”
//     Output: 6
//     All valid sub-strings are “abc”, “abcdef” and “abc”
//     And, the length of the longest of these is 6

//     Input: str = “zabcd”
//     Output: 5 
    
#include <bits/stdc++.h>
using namespace std;

void longest_substring(){
	string s;
	getline(cin, s);
	vector<int> vect(s.length(), 1);
	for(int i=1; i<s.length(); i++){
		if(s[i-1]=='z' && s[i]=='a'){
			vect[i] = vect[i-1]+1;
		}
		// else if(((int)(s[i-1]-'a')+1) == ((int)(s[i]-'a'))){
		else if(s[i-1]+1 == s[i]){
			cout<<s[i-1]<<" "<<s[i]<<endl;
			vect[i] = vect[i-1]+1;
		}
	}

	cout<<"\n ---- vector values -----\n";
	for(int i=0; i<vect.size(); i++){
		cout<<vect[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int test;
	cin>>test;
	cin.ignore(1);
	while(test--){
		longest_substring();
	}
	return 0;
}