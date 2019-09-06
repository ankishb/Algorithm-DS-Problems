
class disjointSet{
public:
    int n;
    vector<int> parent, rank;
    disjointSet(int V){
        parent.resize(V,0);
        rank.resize(V,0);
        n = V;
        for(int i=0; i<V; i++) parent[i] = i;
    }
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    bool check_connected(int x, int y){
        int px = find(x);
        int py = find(y);
        return (px == py) ? true : false;
    }
    void merge(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px == py) return;
        if(rank[px] < rank[py]) parent[px] = py;
        else if(rank[px]>rank[py]) parent[py] = px;
        else{
            parent[px] = py;
            rank[py]++;
        }
    }
};
int kruskals(int V, vector<int> us, vector<int> vs, vector<int> ws) {
    disjointSet set(V+1);
    vector<pair<int,int>> ws_;
    for(int i=0; i<ws.size(); i++){
        ws_.push_back(make_pair(ws[i], i));
    }
    sort(ws_.begin(), ws_.end());
    int min_w = 0, idx, u, v, w;
    for(int i=0; i<ws_.size(); i++){
        idx = ws_[i].second;
        w = ws[idx]; u = us[idx]; v = vs[idx];
        // cout<<w<<" "<<u<<" "<<v<<endl;
        if(!set.check_connected(u, v)){
            cout<<u<<" "<<v<<" "<<w<<endl;
            min_w += w;
            set.merge(u, v);
        }
    }
    
    return min_w;
}