#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vii vector<vector<int>>
#define f first
#define s second
#define ll long long int 

// creat a signature function here

void total_msg(string s, string dec, vector<string> &ans){
    int n = s.length();
    if(n == 0){
        ans.push_back(dec);
        return ;
    }
    if(n >= 1){
        string s_ = s.substr(1);
        char ch = (s[0]-1+'A');
        total_msg(s_, dec+ch, ans);
    }
    if(n >= 2){
        int no = stoi(s.substr(0, 2));
        if(no >= 1 && no <= 26){
            string s_ = s.substr(2);
            char ch = (no-1+'A');
            total_msg(s_, dec+ch, ans);
        }   
    }
}


int main()
 {
	int test;
	cin>>test;
	while(test--){
	    // input and call signature function
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    vector<string> ans;
	    for(auto ch : s){
	        if(ch == '0'){
	            cout<<0<<endl;
	            continue;
	        }
	    }
	    total_msg(s, "", ans);
	   // for(auto dec : ans){
	   //     cout<<dec<<" ";
	   // }cout<<endl;
	    cout<<ans.size()<<endl;
	}
	return 0;
}