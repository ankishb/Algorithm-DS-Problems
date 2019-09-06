
class Solution {
public:
    vector<string> m{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    string get_morse_code(string word){
        string code = "";
        for(auto ch : word){
            code += m[ch - 'a'];
        }
        return code;
    }
    
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_map<string, int> map;
        for(auto w : words){
            string morse_code = get_morse_code(w);
            map[morse_code]++;
        }
        return map.size();
    }
};