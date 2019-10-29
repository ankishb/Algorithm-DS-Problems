
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vii vector<vector<int>>
#define f first
#define s second
#define ll long long int 

// creat a signature function here
void solve(){
	int n;
    cin>>n;
    char ch;
    queue<char> q;
    unordered_map<char, int> freq;
    for(int i=0; i<n; i++){
        cin>>ch;
        freq[ch]++;
        q.push(ch);
        while(!q.empty() && freq[q.front()] > 1){
            q.pop();
        }
        if(q.empty()) cout<<-1<<" ";
        else cout<<q.front()<<" ";
    }
    cout<<endl;
}



int main()
 {
	int test;
	cin>>test;
	while(test--){
	    // input and call signature function
	    solve();
	}
	return 0;
}