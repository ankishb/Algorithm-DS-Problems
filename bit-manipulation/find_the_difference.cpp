
class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = s.length(), bit = 0;
        for(int i=0; i<n; i++){
            bit = bit ^ (int)(s[i]-'a') ^ (int)(t[i]-'a');
        }
        bit = bit ^ (t[n]-'a');
        return (char)(bit+'a');
    }
};