#include <iostream>
using namespace std;

string get_valid_address(string s){
	int n = s.length(), i;
    if(n <= 6) return "";
    string ans = "", sec;
    if(s.substr(0,3) == "ftp"){
        ans += "ftp://";
        i = 3;
    }
    else if(s.substr(0,4) == "http"){ 
        ans += "http://";
        i = 4;
    }
    while(i < n){
        if(sec.length() > 0 && s.substr(i,2) == "ru"){
            ans += sec+".ru";
            i += 2;
            break;
        }
        sec += s[i];
        i++;
    }
    if(s.substr(i) != ""){
        ans += "/"+s.substr(i);
    }
    return ans;
}

int main() {
	string s;
	cin>>s;
	
	cout<<get_valid_address(s)<<endl;
	return 0;
}
// http://sun.ru/x