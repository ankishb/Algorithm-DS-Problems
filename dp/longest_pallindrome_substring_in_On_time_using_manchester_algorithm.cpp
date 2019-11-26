
int manachersAlgorithm(String s, int N) {
    String str = getModifiedString(s, N);
    int len = (2 * N) + 1;
    int[] P = new int[len];
    int c = 0; //stores the center of the longest palindromic substring until now
    int r = 0; //stores the right boundary of the longest palindromic substring until now
    int maxLen = 0;
    for(int i = 0; i < len; i++) {
        //get mirror index of i
        int mirror = (2 * c) - i;
        
        //see if the mirror of i is expanding beyond the left boundary of current longest palindrome at center c
        //if it is, then take r - i as P[i]
        //else take P[mirror] as P[i]
        if(i < r) {
            P[i] = Math.min(r - i, P[mirror]);
        }
        
        //expand at i
        int a = i + (1 + P[i]);
        int b = i - (1 + P[i]);
        while(a < len && b >= 0 && str.charAt(a) == str.charAt(b)) {
            P[i]++;
            a++;
            b--;
        }
        
        //check if the expanded palindrome at i is expanding beyond the right boundary of current longest palindrome at center c
        //if it is, the new center is i
        if(i + P[i] > r) {
            c = i;
            r = i + P[i];
            
            if(P[i] > maxLen) { //update maxlen
                maxLen = P[i];
            }
        }
    }
    return maxLen;
}

String getModifiedString(String s, int N){
    StringBuilder sb = new StringBuilder();
    for(int i = 0; i < N; i++){
        sb.append("#");
        sb.append(s.charAt(i));
    }
    sb.append("#");
    return sb.toString();
}












#include <bits/stdc++.h>
using namespace std;
#define SIZE 100000 + 1

int P[SIZE * 2];

// Transform S into new string with special characters inserted.
string convertToNewString(const string &s) {
    string newString = "@";

    for (int i = 0; i < s.size(); i++) {
        newString += "#" + s.substr(i, 1);
    }

    newString += "#$";
    return newString;
}

string longestPalindromeSubstring(const string &s) {
    string Q = convertToNewString(s);
    int c = 0, r = 0;                // current center, right limit

    for (int i = 1; i < Q.size() - 1; i++) {
        // find the corresponding letter in the palidrome subString
        int iMirror = c - (i - c);

        if(r > i) {
            P[i] = min(r - i, P[iMirror]);
        }

        // expanding around center i
        while (Q[i + 1 + P[i]] == Q[i - 1 - P[i]]){
            P[i]++;
        }

        // Update c,r in case if the palindrome centered at i expands past r,
        if (i + P[i] > r) {
            c = i;              // next center = i
            r = i + P[i];
        }
    }

    // Find the longest palindrome length in p.

    int maxPalindrome = 0;
    int centerIndex = 0;

    for (int i = 1; i < Q.size() - 1; i++) {

        if (P[i] > maxPalindrome) {
            maxPalindrome = P[i];
            centerIndex = i;
        }
    }

    cout << maxPalindrome << "\n";
    return s.substr( (centerIndex - 1 - maxPalindrome) / 2, maxPalindrome);
}

int main() {
    string s = "kiomaramol\n";
    cout << longestPalindromeSubstring(s);
    return 0;
}