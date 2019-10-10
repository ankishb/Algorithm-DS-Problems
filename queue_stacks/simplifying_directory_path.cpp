
// new try
/*
1. tranverse through each character and collect all the path between slashes
    - If "/.", don't do anything
    - If "/..", we go on path (if we are at home, them we stay there) <----------- edge case
    - If path name, push in container

Note: i use deque, sto save some time, otherwise, we prepare a string from stack, 
    where each string should be reversed to collect all in order. And finally, we
    reverse the entire string to get answer.
*/
string Solution::simplifyPath(string s) {
    int n = s.length(), i = 0;
    if(n == 0) return "";
    string sub = "";
    deque<string> store;
    while(i < n){
        if(s[i] == '/'){
            sub = "/"; 
            i++;
        }
        while(i < n && s[i] != '/'){
            sub += s[i]; i++;
        }
        // cout<<sub<<" ";
        if(sub == "/." || sub == "/") continue;
        if(sub == "/.."){
            if(!store.empty()) store.pop_back();
        }
        else store.push_back(sub);
    }
    sub = "";
    while(!store.empty()){
        sub += store.front();
        store.pop_front();
    }
    return (sub == "") ? "/" : sub;
}



// old try
#include <bits/stdc++.h>
using namespace std;

void simplifyPath(string A){
	stack<string> stacking;
	while(!stacking.empty()){
		stacking.pop();
	}
    string temp;
    int i=0;
    while(i<A.length()){
        cout<<A[i]<<"--\n";
        if(A[i] == '/'){
            i++;
            temp = "/";
            while(A[i]!='/' && i<=A.length()-1){
                temp = temp+A[i];
                i++;
            }
            cout<<temp<<endl;
            stacking.push(temp);
            while(!stacking.empty() && stacking.top() == "/."){
                stacking.pop();
            }
            while(!stacking.empty() && stacking.top()=="/.."){
                stacking.pop();
                if(!stacking.empty()){
                	stacking.pop();
                }
                
            }
        }
    }
    while(!stacking.empty() && stacking.top()=="/.."){
        stacking.pop();
        stacking.pop();
    }
    while(!stacking.empty() && stacking.top() == "/"){
        stacking.pop();
    }
    string ans = "";
    while(!stacking.empty()){
        ans = stacking.top()+ans;
        stacking.pop();
    }
    // return ans;
    cout<<ans<<endl;
}

int main()
{
	int test;
	cin>>test;
	cin.ignore(1);
	while(test--){
		string str;
		getline(cin, str);
		// cin>>str;// as input doesn't contain white spaces
		simplifyPath(str);
	}
	return 0;
}