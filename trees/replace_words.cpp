/*
1. create trie with the given dictionary of words
2. breaks the sentence into words and search it in trie model.
3. search for each word, if we encounter is_word flag in between the current word, then we replace it
*/

class TrieNode{
public:
    TrieNode *child[26];
    bool is_word;
    TrieNode(bool flag = false){
        memset(child, 0, sizeof(child));
        is_word = flag;
    }
};

class Solution {
public:
    TrieNode *root = new TrieNode(false);
    
    void insert(string s){
        TrieNode* start = root;
        for(int i=0; i<s.length(); i++){
            int ch = s[i] - 'a';
            if(start->child[ch] == NULL){
                start->child[ch] = new TrieNode();
            }
            start = start->child[ch];
        }
        start->is_word = true;
    }
    string get_word(string s){
        TrieNode* start = root;
        int n = s.length();
        string ans = "";
        for(int i=0; i<n; i++){
            int ch = s[i] - 'a';
            if(start->child[ch] == NULL || start->is_word == true){
                break;
            }
            ans += s[i];
            start = start->child[ch];
        }
        
        return (start->is_word == true) ? ans : s;
    }
    string replaceWords(vector<string>& dict, string sent) {
        for(int i=0; i<dict.size(); i++){
            insert(dict[i]);   
        }
        string ans = "", cur = "";
        int n = sent.length();
        for(int i=0; i<=n; i++){
            if(i==n || (i<n && sent[i] == ' ')){
                // cout<<cur<<" ";
                string word = get_word(cur);
                if(word == "") word = cur;
                ans += word;
                if(i<n) ans += " ";
                cur = "";
            }
            else{
                cur += sent[i];
            }
        }
        return ans;
    }
};