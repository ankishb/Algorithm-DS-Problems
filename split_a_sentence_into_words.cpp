#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)

void solve_easy1(){
    int n;
    cin>>n;
    unordered_map<string, int> my_map;
    string s[n];
    for(int i=0; i<n; i++){
        cin>>s[i];
        my_map[s[i]]++;
    }
    
    int ans = 0;
    for(auto itr : my_map){
        if(itr.second == 2){
            ans++;
        }
    }
    cout<<ans<<endl;
}

void solve_easy2(){
    int n;
    cin>>n;
    string str;
    cin.ignore(1);
    getline(cin, str);
    unordered_map<string, int> my_map;
    
    string word = "";
    for(int i=0; i<=str.length(); i++){
    	if(str[i] == ' ' || i==str.length()){
    		if(word.length() > 0){
    			cout<<word<<endl;
    			my_map[word]++;
    			word = "";
    		}
    	}
    	else{
    		word = word + str[i];
    	}
    }
    
    int ans = 0;
    for(auto itr : my_map){
        if(itr.second == 2){
            ans++;
        }
    }
    cout<<ans<<endl;
}

void solve(){
    int n;
    cin>>n;
    string str;
    cin.ignore(1);
    getline(cin, str);
    unordered_map<string, int> my_map;
    
    // Used to split string around spaces. 
    istringstream ss(str); 
  
    do { 
        string word; 
        ss >> word; 
        my_map[word]++;
    } while (ss); 
    
    int ans = 0;
    for(auto itr : my_map){
        if(itr.second == 2){
            ans++;
        }
    }
    cout<<ans<<endl;
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