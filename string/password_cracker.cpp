
#include <bits/stdc++.h>
using namespace std;

void crackPassword(unordered_map<string, int> myMap, vector<int> vectLen[], string s){
    int i = 0, n = s.length();
    string substr, ans = "";
    char a;
    bool found, failed = false;
    int len;
    while(i < n){
        a = s[i]-'a';
        found = false;
        for(int j=0; j<vectLen[a].size(); j++){
            len = vectLen[a][j];
            substr = s.substr(i, len);
            // cout<<substr<<" ";
            if(myMap.find(substr) != myMap.end()){
                ans = ans + substr + " ";
                // cout<<substr<<" ";
                i = i + len;
                found = true;
            }
            if(found) break;
        }
        if(found == false){
            failed = true;
            break;
        }
    }
    
    (failed) ? cout<<"WRONG PASSWORD\n" : cout<<ans<<endl;    
}

int main(){
    int test; cin>>test;
    while(test--){
        int n; cin>>n;
        string s, login;
        unordered_map<string, int> myMap;
        vector<int> vectLen[26];
        for(int i=0; i<n; i++){
            cin>>s;
            myMap[s] = i;
            vectLen[s[0]-'a'].push_back(s.length());
        }
        cin>>login;
        crackPassword(myMap, vectLen, login);
    }
    return 0;
}


string passwordCracker(vector<string> passwords, string loginAttempt) {
    // create an dictionary of string and vector of string len
		unordered_map<string, int> myMap;
    vector<int> vectLen[26];
    string s;
    int n = passwords.size();
    for(int i=0; i<n; i++){
        s = passwords[i];
        myMap[s] = i;
        vectLen[s[0]-'a'].push_back(s.length());
    }

	// now start with index 0 and we check the string length available corresponding to first character, we check the corresponding substr in the map, if available we add it in string ans, else that is "WRONG P.." 
    int i = 0, len;
    n = loginAttempt.length();
    string substr, ans = "";
    char a;
    bool found, failed = false;
    while(i < n){
        a = loginAttempt[i]-'a';
        found = false;
        for(int j=0; j<vectLen[a].size(); j++){
            len = vectLen[a][j];
            substr = loginAttempt.substr(i, len);
            if(myMap.find(substr) != myMap.end()){
                ans = ans + substr + " ";
                i = i + len;
                found = true;
            }
            if(found) break;
        }
        if(found == false){
            failed = true; break;
        }
    }
    
    if (failed) return "WRONG PASSWORD";
    return ans;
}













// python solution
def find_passwords(s, passwords, parts=[]):
    for i in range(1,len(s)+1):
        if s[:i] in passwords:
            new_parts = parts + [s[:i]]
            if i < len(s):
                find_passwords(s[i:], passwords, new_parts)
            else:
                results.append(new_parts)

results = []
find_passwords("abcd", ["ab", "abcd", "cd"])    
print results if results else 'WRONG PASSWORD'

# Result: [['ab', 'cd'], ['abcd']]