class TrieNode{
public:
    TrieNode *parent[26];
    int freq;
    TrieNode(){
        memset(parent, 0, sizeof(parent));
        freq = 0;
    }
};

class trie{
public:
    TrieNode* root;
    trie(){
        TrieNode* temp = new TrieNode();
        root = temp;
    }
    
    void insert(string s){
        TrieNode* start = root;
        for(auto ch : s){
            int c = ch-'a';
            if(start->parent[c] == NULL){
                start->parent[c] = new TrieNode();
            }
            start->freq++;
            start = start->parent[c];
        }
    }
    string get_prefix(string s){
        TrieNode* start = root;
        string ans = "";
        for(int i=0; i<s.length(); i++){
            int c = s[i]-'a';
            start = start->parent[c];
            ans += s[i];
            if(start->freq == 1) return ans;
        }
        return ans;
    }
};

vector<string> Solution::prefix(vector<string> &A) {
    trie t;
    vector<string> ans;
    for(auto s : A){
        t.insert(s);
    }
    for(auto s : A){
        ans.push_back(t.get_prefix(s));
    }
    return ans;
}
