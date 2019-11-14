/*
Input:
4
madam
mamad
damma
daamm

Output:
madam :: 0
madam :: 3
amdma :: 2
madam :: 4
*/

// latest try
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int min_swapping(string s){
    // 1. check if pallindrome is possible
    unordered_map<char, int> freq;
    for(auto ch : s) freq[ch]++;
    bool miss = false;
    for(auto f : freq){
        if(f.second % 2 == 0) continue;
        if(f.second % 2 == 1){
            if(!miss) miss = true;
            else return -1;
        }
    }
    // 2. Now find min operation
    int n = s.length();
    int count = 0;
    for(int i=0; i<n/2; i++){
        if(s[i] == s[n-i-1]) continue;
        int j, k;
        // let if s[i] is the middle most character for n is odd
        // find s[j] == s[n-i-1]
        for(j=i+1; j<=n-i-1; j++){
            if(s[j] == s[n-i-1]) break;
        }
        
        // let if s[n-i-1] is the middle most character for n is odd
        // find s[n-i-1] == s[k]
        for(k=n-i-2; k>=i; k--){
            if(s[k] == s[i]) break;
        }
        
        // count min of both
        count += min(j-i, n-i-1-k);
        if(j-i < n-i-1-k){
            // take jth character at ith place
            for(int l=j; l>i; l--){
                swap(s[l], s[l-1]);
            }
        }
        else{
            // take kth character at (n-i-1)th place
            for(int l=k; l<n-i-1; l++){
                swap(s[l], s[l+1]);
            }
        }
    }
    cout << s << " :: ";
    return count;
}

int main()
{
    int test;
    cin >> test;
    while(test--){
        string s;
        cin>>s;
        
        cout << min_swapping(s) << endl;
    }
    return 0;
}

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
        while(i < n/2){
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







// correct one
/*
daamm
correct ans = 4
acc to above code : 6
*/
#include<bits/stdc++.h>
using namespace std;

int freq[256];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    while(cin >> s) {
        if(s[0] == '0') break;
        memset(freq, 0, sizeof(freq));
        int ns = s.length();
        for(int i=0; i<ns; i++) {
            freq[(int)s[i]]++;
        }
        int d = 0;
        for(int i=0; i<256; i++) {
            d += freq[i]%2;
        }
        if(d > 1) {
            printf("Impossible\n");
            continue;
        }
        d = 0;
        for(int i=0; i<ns/2; i++){
            if(s[i] == s[ns-i-1]) continue;
            int j, k;
            for(j=i+1; s[j] != s[ns-i-1]; j++);
            for(k=ns-2-i; s[k] != s[i]; k--);
            d += min(j-i, ns-i-1-k);
            if(j-i < ns-i-k-1){
                for(int l=j; l>i; l--){
                    swap(s[l], s[l-1]);
                }
            } 
            else{
                for(int l=k; l<ns-i-1; l++){
                    swap(s[l], s[l+1]);
                }
            }
        }
        cout<< s << endl << d <<endl;
    }
    return 0;
}