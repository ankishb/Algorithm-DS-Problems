#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)

void visit_group(vector<vector<char> > &pattern, 
    vector<vector<bool> > &visited, int i, int j){
    if(pattern[i][j] == 'O') return;
    int n = pattern.size();
    int m = pattern[0].size();
    if(i-1>=0 && !visited[i-1][j] && pattern[i-1][j] == 'X'){
        visited[i-1][j] = true;
        visit_group(pattern, visited, i-1, j);
    }
    if(j-1>=0 && !visited[i][j-1] && pattern[i][j-1] == 'X'){
        visited[i][j-1] = true;
        visit_group(pattern, visited, i, j-1);
    }
    if(i+1<n && !visited[i+1][j] && pattern[i+1][j] == 'X'){
        visited[i+1][j] = true;
        visit_group(pattern, visited, i+1, j);
    }
    if(j+1<m && !visited[i][j+1] && pattern[i][j+1] == 'X'){
        visited[i][j+1] = true;
        visit_group(pattern, visited, i, j+1);
    }
}

int count_group(vector<vector<char> > pattern){
    int n = pattern.size();
    int m = pattern[0].size();
    int count = 0;
    vector<vector<bool> > visited(n, vector<bool>(m,0));
    // memset(visited, 0, sizeof(visited));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visited[i][j]) continue;
            if(pattern[i][j] == 'O'){
                visited[i][j] = true;
            }
            else{
                count++;
                visit_group(pattern, visited, i, j);
            }
        }
    }
    return count;
}

void solve(){
    int n, m;
    cin>>n>>m;
    cin.ignore(1);
    string str;
    getline(cin, str);
    vector<vector<char> > pattern;
    vector<char> temp;
    for(int i=0; i<str.length(); i++){
        if(str[i] == ' '){
            pattern.push_back(temp);
            temp.clear();
        }
        else{
            temp.push_back(str[i]);
        }
    }
    if(temp.size() != 0){
    	pattern.push_back(temp);
    }
    
    cout<<count_group(pattern)<<endl;
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