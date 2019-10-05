
/*
Trie Solution:
    1. Build trie with main nodes as child and visit-counter
    2. while inserting, we need to update visit-counter as well
    3. While quering, we will check two thing
        i) If all the character of query-string is present, if not return 0
        ii) From all the character, we need to return minimum count

contacts_optimized:
    1. Maintain hash-map for substrings, with size 1-N, which means
        for length N, we make N substring of size {1, 2, 3, ..., N}
    2. While query, we need value for the corresponding key

contacts_naive:
    1. Make 26 buckets and add the data in the corresponding bucket
    2. For query, we search for all the string in the corresponding bucket 
        with appropriate substring length.
*/
class trie_node{
public:
    trie_node *child[26];
    int visit[26];

    trie_node(){
        memset(child, 0, sizeof(child));
        memset(visit, 0, sizeof(visit));
    }
};
class trie{
public:
    trie_node *root;
    trie(){ root = new trie_node(); }
    
    void build_trie(string s){
        int n = s.length();
        trie_node *r = root;
        for(auto ch : s){
            if(r->child[ch-'a'] == NULL){
                r->child[ch-'a'] = new trie_node();
                r->visit[ch-'a'] = 1;
            }
            else{
                r->visit[ch-'a'] += 1;
            }
            r = r->child[ch-'a'];
        }
    }

    int search(string s){
        trie_node *r = root;
        int ans = INT_MAX;
        for(auto ch : s){
            if(r->child[ch-'a'] == NULL) return 0;
            if(ans == INT_MAX) ans = r->visit[ch-'a'];
            else ans = min(ans, r->visit[ch-'a']);
            r = r->child[ch-'a'];
        }
        return ans;
    }
};

vector<int> contacts(vector<vector<string>> queries) {
    vector<int> ans;
    trie t;
    for(auto e : queries){
        if(e[0] == "add"){
            t.build_trie(e[1]);
        }
        else{
            int response = t.search(e[1]);
            ans.push_back(response);
        }
    }
    return ans;
}
vector<int> contacts_optimized(vector<vector<string>> queries) {
    vector<int> ans;
    unordered_map<string, int> my_map;
    for(auto e : queries){
        if(e[0] == "add"){
            for(int i=1; i<=e[1].length(); i++){
                my_map[e[1].substr(0, i)]++;
                // cout<<e[1].substr(0, i)<<" ";
            }
        }
        else{
            // we search in the corresponding bucket
            ans.push_back(my_map[e[1]]);
        }
    }
    return ans;
}

vector<int> contacts_naive(vector<vector<string>> queries) {
    vector<string> dict[26];
    vector<int> ans;
    int count;
    for(auto e : queries){
        if(e[0] == "add"){
            dict[e[1][0]-'a'].push_back(e[1]);
        }
        else{
            // we search in the corresponding bucket
            count = 0;
            for(auto str : dict[e[1][0]-'a']){
                if(str.substr(0, e[1].length()) == e[1]) count++;
            }
            ans.push_back(count);
        }
    }
    return ans;
}