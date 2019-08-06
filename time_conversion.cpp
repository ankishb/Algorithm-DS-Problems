#include <bits/stdc++.h>
using namespace std;

/*
Approach:
There are two cases:
1. If time is PM, just add 12 in the time.
    1. On add, handle case, when it exceed 24, then change it into 00:min:sec notation
2. If time is AM, then there are two cases:
    1. If hour is < 12, just print it after removing AM 
    2. If hour is 12, then check, if it has min/sec > 0, for exp: 12:25:00AM, this is clearly different case.
*/

string timeConversion(string s) {
    int n = s.length();
    string ans = "";
    int no = 10*(s[0]-'0') + (s[1]-'0');
    if(s[8] == 'P'){
    	if(no == 12){
    		for(int i=0; i<=7; i++) ans += s[i];
    	}
    	else{
	        no = no+12;
	        ans += ((no/10)%10 + '0');
	        ans += (no%10 + '0');
	        for(int i=2; i<=7; i++) ans += s[i];
	    }
    }
    else{
        if(no == 12){
        	ans += '0';
        	ans += '0';
            for(int i=2; i<=7; i++) ans += s[i];
        }
    	else{
            for(int i=0; i<=7; i++) ans += s[i];
        }
    }
    return ans;
}



