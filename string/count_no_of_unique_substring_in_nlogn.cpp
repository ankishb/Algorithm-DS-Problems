#include <bits/stdc++.h>
using namespace std;

int LCP(string s1, string s2){
    int n1 = s1.length(), n2 = s2.length();
    int count = 0;
    for(int i=0; i<min(n1, n2); i++){
        if(s1[i] != s2[i]) break;
        count++;
    }
    return count;
}

int main()
{
    int test;
    cin>>test;
    while(test--){
        string s;
        cin>>s;
        int n = s.length();
        vector<string> suffix(n);
        for(int i=0; i<n; i++){
            suffix[i] = s.substr(i);
        }
        sort(suffix.begin(), suffix.end());
        int count = suffix[0].length();
        for(int i=1; i<n; i++){
            count += (suffix[i].length() - LCP(suffix[i-1], suffix[i]));
        }
        count++; //include empty string as well
        cout<<count<<endl;
    }
    return 0;
}