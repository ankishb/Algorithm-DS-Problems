#define f first
#define s second

class Solution {
public:
    char sol_wo_memory(string s, string t) {
        int n = s.length(), bit = 0;
        for(int i=0; i<n; i++){
            bit = bit ^ (int)(s[i]-'a') ^ (int)(t[i]-'a');
        }
        bit = bit ^ (t[n]-'a');
        // char ans = bit+'a';
        return (char)(bit+'a');
    }
    char new_try(string s, string t) {
        int n = s.length(), bit = 0, ch1, ch2;
        for(int i=0; i<n; i++){
            ch1 = s[i], ch2 = t[i];
            bit = bit ^ ch1 ^ ch2;
        }
        return (char)(bit^t[n]);
    }
    char sol_w_memory(string s, string t) {
        unordered_map<char, int> map;
        for(auto ch : s) map[ch]++;
        for(auto ch : t) map[ch]--;
        for(auto itr : map){
            if(itr.s != 0) return itr.f;
        }
        return -1;
    }
    char findTheDifference(string s, string t) {
        // return sol_w_memory(s, t);
        // return sol_wo_memory(s, t);
        return new_try(s, t);
    }
};