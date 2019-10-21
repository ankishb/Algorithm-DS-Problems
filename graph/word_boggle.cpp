#include <bits/stdc++.h>
using namespace std;
#define vvc vector<vector<char>>
#define vs vector<string>
#define pii pair<int,int>

bool is_valid(int n, int m, int x, int y){
    return (x>=0 && x<n && y>=0 && y<m);
}
class helper{
public:
    int x, y;
    string s;
    helper(int x_, int y_, string s_){
        x = x_, y = y_, s = s_;
    }
};
bool bfs(vvc A, string s, int n, int m, int x, int y){
    queue<helper> q;
    q.push(helper(x, y, ""+s[0]));
    A[x][y] = ' ';
    int sn = s.length();
    
    int xs[] = {-1,-1,-1,0,1,1, 1, 0};
    int ys[] = {-1, 0, 1,1,1,0,-1,-1};
    cout<<"reach here\t";
    while(!q.empty()){
        helper f = q.front();
        x = f.x, y = f.y;
        q.pop();
        cout<<f.s<<"\t";
        if(f.s == s) return true;
        
        for(int i=0; i<8; i++){
            if(is_valid(n, m, x+xs[i], y+ys[i]) 
            && A[x+xs[i]][y+ys[i]] != ' '){
                char ch = A[x+xs[i]][y+ys[i]];
                q.push(helper(x+xs[i], y+ys[i], f.s+ch));
                A[x+xs[i]][y+ys[i]] = ' ';
            }
        }
    }
    return false;
}

void find_words(vvc A, vs dict){
    int n = A.size(), m = A[0].size();
    int dn = dict.size();
    vector<string> ans;
    unordered_map<char, vector<string>> easy_map;
    for(auto s : dict){
        easy_map[s[0]].push_back(s);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(easy_map.find(A[i][j]) != easy_map.end()){
                for(auto s : easy_map[A[i][j]]){
                    // cout<<s<<" ";
                    if(bfs(A, s, n, m, i, j)){
                        cout<<"found\t";
                        ans.push_back(s);   
                    }
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    for(auto s : ans) cout<<s<<" ";
    cout<<endl;
}

int main()
 {
	int test;
	cin>>test;
	while(test--){
	    int dn;
	    cin>>dn;
	    vector<string> dict(dn);
	    for(int i=0; i<dn; i++){
	        cin>>dict[i];
	    }
	    int n, m;
	    cin>>n>>m;
	    vector<vector<char>> A(n, vector<char>(m));
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            cin>>A[i][j];
	        }
	    }
	    find_words(A, dict);
	}
	return 0;
}