
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