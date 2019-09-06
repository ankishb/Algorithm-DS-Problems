
class TrieNode{
public:
    TrieNode *child[26];
    bool is_word;
    
    TrieNode(bool flag = false){
         memset(child, 0, sizeof(child));
        is_word = flag;
    }
};

class Trie {
public:
    TrieNode *root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode(false);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int n = word.length();
        TrieNode *start = root;
        for(int i=0; i<n; i++){
            int ch = word[i] - 'a';
            if(start->child[ch] == NULL){
                start->child[ch] = new TrieNode();
            }
            start = start->child[ch];
        }
        start->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode * start = root;
        for(int i=0; i<word.length(); i++){
            int ch = word[i] - 'a';
            if(start->child[ch] == NULL) return false;
            start = start->child[ch];
        }
        if(start->is_word) return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode * start = root;
        for(int i=0; i<prefix.length(); i++){
            int ch = prefix[i] - 'a';
            if(start->child[ch] == NULL) return false;
            start = start->child[ch];
        }
        return true;
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */




