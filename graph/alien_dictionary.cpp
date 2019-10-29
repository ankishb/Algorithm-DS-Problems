vector<bool> visit;
stack<int> store;
    
void helper(vector<int> adj[], int u){
    visit[u] = true;
    for(auto v : adj[u]){
        if(visit[v]) continue;
        helper(adj, v);
    }
    store.push(u);
}

string topo_sort(vector<int> adj[], int n, int k){
    visit.resize(26, false);
    while(!store.empty()){
        store.pop();
    }
    
    for(int i=0; i<26; i++){
        if(!visit[i]) helper(adj, i);
    }
    string order = "";
    while(!store.empty()){
        order += (store.top() + 'a');
        store.pop();
    }
    // reverse(order.begin(), order.end());
    // cout<<order<<endl;
    return order;
}

string printOrder(string dict[], int n, int k){
    vector<int> adj[26];
    for(int i=0; i<n-1; i++){
        string s1 = dict[i];
        string s2 = dict[i+1];
        int n1 = s1.length(), n2 = s2.length();
        for(int j=0; j<min(n1, n2); j++){
            if(s1[j] != s2[j]){
                adj[s1[j]-'a'].push_back(s2[j]-'a');
                break;
            }
        }
    }
    
    return topo_sort(adj, n, k);
}