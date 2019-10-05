

bool isalnum(char ch){
    return (isalpha(ch) || isdigit(ch));
}

int optimized(string s){
    int n = s.length();
    int l = 0, r = n-1;
    while(l < r){
        while(l<r && !isalnum(s[l])) l++;
        while(l<r && !isalnum(s[r])) r--;
        if(tolower(s[l]) != tolower(s[r])) return 0;
        l++; r--;
    }
    return 1;
}


int brute_force(string s){
    string s_ = "";
    int n = s.length();
    for(int i=0; i<n; i++){
        if(isalpha(s[i])) s_ += tolower(s[i]);
        else if(isdigit(s[i])) s_ += s[i];
        else continue;
    }
    // cout<<s_<<endl;
    n = s_.length();
    for(int i=0; i<n/2; i++){
        if(s_[i] != s_[n-i-1]) return 0;
    }
    return 1;
}


int Solution::isPalindrome(string s) {
    // return brute_force(s);
    return optimized(s);
}





// old one
#include <bits/stdc++.h>
using namespace std;

// A-Z ==> 65-90
// a-z ==> 97-122
void isPalindrome(string A){
	string str = "";
	for(int i=0; i<A.length(); i++){
		int ascii = A[i];
		if((ascii>=65 && ascii<=90)){
			str += (A[i]+32);
		}
		else if((ascii>=97 && ascii<=122) || (ascii>=48 && ascii<=57)){
			str += A[i];
		}
	}
	for(int i=0; i<=ceil((str.length())/2); i++){
		if(str[i] != str[str.length()-1-i]){
			cout<<0<<endl;
			break;
		}
	}
	cout<<1<<endl;
}

int main()
{
	int test;
	cin>>test;
	cin.ignore(1);
	while(test--){
		string str;
		getline(cin, str);
		isPalindrome(str);
	}
	return 0;
}