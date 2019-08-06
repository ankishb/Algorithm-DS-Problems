// Exp:
// Given s = “the sky is blue“,
// return “blue is sky the“.

// Approach:
// 1. Reverse the given string
// 2. reverse each word
#include <bits/stdc++.h>
using namespace std;

void reverse_(string &str, int start, int end){
    while(start<end){
        swap(str[start], str[end-1]);
        start++;
        end--;
    }
}

void reverse_words(string str){
	int n = str.length();
	reverse_(str, 0, n);
	cout<<"reversed string\n";
	for(int i=0; i<n; i++){
		cout<<str[i];
	}
	int start = 0;
	for(int i=0; i<n; i++){
		if(str[i] == ' '){
			reverse_(str, start, i);
			start = i+1;
		}
	}
	reverse_(str, start, n);
	
	cout<<"\ndesired reversed words string\n";
	for(int i=0; i<n; i++){
		cout<<str[i];
	}
	cout<<endl;
}

int main()
{
	int test;
	cin>>test;
	cin.ignore(1);
	while(test--){
		string str;
		getline(cin, str);
		reverse_words(str);
	}
	return 0;
}