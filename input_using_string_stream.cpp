#include <bits/stdc++.h>
using namespace std;

int main()
{
    string inp1 = "i am ankish";
    string inp2 = "i,,am,ankish";
    vector<string> ans;
    stringstream ss1(inp1);
    string s;
    while(ss1 >> s){
        cout<<s<<"\n";
    }
    stringstream ss2(inp2);
    while(getline(ss2, s, ',')){
        if(s.length() > 0) cout<<s<<"\n";
    }
    return 0;
}