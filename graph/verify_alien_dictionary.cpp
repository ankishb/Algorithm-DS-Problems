
class Solution {
public:
    unordered_map<char, int> map;
    bool check(string s1, string s2){
        int n1 = s1.length(), n2 = s2.length();
        for(int i=0; i<min(n1, n2); i++){
            if(map[s1[i]] < map[s2[i]]) return true;
            if(map[s1[i]] > map[s2[i]]) return false;
            if(map[s1[i]] == map[s2[i]]) continue;
        }
        return (n1 <= n2);
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size(), m = order.size();
        for(int i=0; i<m; i++){
            map[order[i]] = i;
        }
        for(int i=1; i<n; i++){
            if(!check(words[i-1], words[i])){
                return false;
            }
        }
        return true;
    }
};