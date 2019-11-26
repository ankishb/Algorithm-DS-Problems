#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vii vector<vector<int>>
#define f first
#define s second
#define ll long long int 

// creat a signature function here

int get_longest_prefix(string s){
    int n = s.length();
    vector<int> prefix(n, 0);
    int i = 1, j = 0;
    while(i < n){
        if(s[i] == s[j]){
            prefix[i] = j + 1;
            i++; j++;
        }
        else{
            if(j > 0 && s[i-1] == s[j-1]){
                j = prefix[j-1];
            }
            else i++;
        }
    }
    return prefix[n-1];
}


int main()
 {
	int test;
	cin>>test;
	while(test--){
	    // input and call signature function
	    string s;
	    cin >> s;
	    cout << get_longest_prefix(s) << endl;
	}
	return 0;
}