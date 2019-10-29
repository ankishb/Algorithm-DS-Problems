
/* why this one is not working (could not understood error)
class trie_node{
public:
    bool is_leaf;
    unordered_map<char, trie_node*> child;
    trie_node(){
        is_leaf = false;
    }
};

class Trie {
public:
    trie_node *root;
    // Initialize your data structure here. 
    Trie() {}
    
    // Inserts a word into the trie. 
    void insert(string word) {
        if(root == NULL){
            root = new trie_node();
        }
        trie_node *temp = root;
        for(auto ch : word){
            // cout<<(temp->child[ch] == NULL)<<" ";
            // if(temp->child.find(ch) == temp->child.end()){
            if(temp->child[ch] == NULL){
                temp->child[ch] = new trie_node();
            }
            temp = temp->child[ch];
        }
        temp->is_leaf = true;
    }
    
    // Returns if the word is in the trie.
    bool search(string word) {
        if(root == NULL) return false;
        trie_node *temp = root;
        for(auto ch : word){
            if(temp->child.find(ch) == temp->child.end()){
                return false;
            }
            temp = temp->child[ch];
        }
        if(temp->is_leaf) return true;
        return false;
    }
    
    // Returns if there is any word in the trie that starts with the given prefix. 
    bool startsWith(string prefix) {
        if(root == NULL) return false;
        trie_node *temp = root;
        for(auto ch : prefix){
            if(temp->child.find(ch) == temp->child.end()){
                return false;
            }
            temp = temp->child[ch];
        }
        return true;
    }
};
*/


class TrieNode{
public:
    TrieNode *child[26];
    bool is_word;
    
    TrieNode(bool flag = false){
        memset(child, NULL, sizeof(child));
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















class trie_node{
public:
    trie_node *child[26];
    bool is_word;
    trie_node(){
        is_word = false;
        memset(child, NULL, sizeof(child));
    }
};
class Trie {
public:
    trie_node *root;
    /** Initialize your data structure here. */
    Trie() {
        root = new trie_node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        trie_node *temp = root;
        for(auto c : word){
            int ch = c-'a';
            if(temp->child[ch] == NULL){
                temp->child[ch] = new trie_node(); 
            }
            temp = temp->child[ch];
        }
        temp->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        trie_node *temp = root;
        for(auto c : word){
            int ch = c-'a';
            if(temp->child[ch] == NULL){
                return false;
            }
            temp = temp->child[ch];
        }
        return temp->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        trie_node *temp = root;
        for(auto c : prefix){
            int ch = c-'a';
            if(temp->child[ch] == NULL){
                return false;
            }
            temp = temp->child[ch];
        }
        return true;
    }
};