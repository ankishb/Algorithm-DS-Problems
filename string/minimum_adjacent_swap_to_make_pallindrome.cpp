#include <iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main() {
    while(1){
        string s;
        cin>>s;
        if(s == "0") break;
        
        // first check, if it is a valid pallindrome
        unordered_map<char,int> map;
        for(auto ch : s){
            map[ch]++;
            // erase if count == 2 
            if(map[ch] == 2){
                map.erase(ch);
            }
        }
        if(map.size() > 1){
            cout<<"Impossible\n";
            continue;
        }
        int swap_c = 0;
        int i = 0, j, n = s.length();
        while(i<n/2){
            j = n-i-1;
            while(s[i] != s[j]) j--;
            while(j < n-i-1){
                swap(s[j], s[j+1]);
                swap_c++;
                j++;
            }
            i++;
        }
        cout<<swap_c<<endl;
    }
	return 0;
}
