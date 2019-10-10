#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)

string first(string s, int n){
    vector<int> pos;
    for(int i=0; i<s.length(); i++){
        if(s[i] == ' '){
            pos.push_back(i);
        }
    }
    if(pos.size() == 0) return s;
    for(int i=pos.size()-1; i>=0; i--){
        s = s.substr(0,pos[i]) + "%20" + s.substr(pos[i]+1);
    }
    return s;
}
string second(string s, int n){
    string s1 = "";
    for(int i=0; i<s.length(); i++){
        if(s[i] == ' ') s1 += "%20";
        else s1 += s[i];
    }
    return s1;
}

void solve(){
    string s;
    cin.ignore(1);
    getline(cin, s);
    int n; 
    cin>>n;
    // cout<<first(s, n)<<endl;
    cout<<second(s, n)<<endl;
}

int main()
 {
	int test;
	cin>>test;
	while(test--){
	    solve();
	}
	return 0;
}