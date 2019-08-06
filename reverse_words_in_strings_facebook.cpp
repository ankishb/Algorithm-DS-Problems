// https://www.interviewbit.com/problems/reverse-the-string/

// - A sequence of non-space characters constitutes a word.
// - Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.
// - If there are multiple spaces between words, reduce them to a single space in the reversed string

#include <bits/stdc++.h>
using namespace std;

void reverse_string(string &A){
    int count=0;
    string ans = "";
    for(int i=A.length()-1; i>=0; i--){
    	// cout<<"-- entering loop --"<<endl;
        if(A[i] == ' '){
        	if(count != 0){
        		cout<<A.substr(i+1, count)<<" ";
        		ans += A.substr(i+1, count) + " ";
        	}
            count = 0;
            // idx = 
        }
        else{
            count++;
        }
        // count++;
    }
    if(A[0] != ' '){
    	cout<<A.substr(0, count);
    	ans += A.substr(0, count);
    }
    A = ans;
    cout<<endl;
    cout<<ans<<endl;
}

// int count=0;
// string ans = "";
// for(int i=A.length()-1; i>=0; i--){
//     if(A[i] == ' '){
//         if(count != 0){
//             ans += A.substr(i+1, count) + " ";
//         }
//         count = 0;
//     }
//     else{
//         count++;
//     }
// }
// if(A[0] != ' '){
//     ans += A.substr(0, count);
// }
// A = ans;


int main()
{
	int test;
	cin>>test;
	cin.ignore(1);
	while(test--){
		string A;
		getline(cin, A);
		cout<<A<<endl;
		reverse_string(A);
	}
	return 0;
}




void Solution::reverseWords(string &A) {
    stack<string> s;
    int i=0;
    string a = "";
    int n = A.length();
    while(i<n){
        if(A[i]==' '){
            i++;
        }
        else{
            while(i<n && A[i] !=' '){
                a = a+A[i];
                i++;
            }
            s.push(a);
            a = "";
        }
    }
    A = "";
    while(!s.empty()){
        A = A + s.top() + " ";
        s.pop();
    }
    n = A.length();
    A = A.substr(0, n-1);
}