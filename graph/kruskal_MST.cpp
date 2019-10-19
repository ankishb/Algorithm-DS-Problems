
// new one and little different(used naive find-union approach)
#define pii pair<int,int>
#define f first
#define s second

class naive_disjoint_set{
public:
    vector<int> parent;
    naive_disjoint_set(int n){
        for(int i=0; i<n; i++){
            parent.push_back(i);
        }
    }
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    bool merge(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px == py) return false;
        parent[px] = py;
        return true;
    }
};

void bubble_sort(vector<pii> &A){
    pii p1, p2;
    for(int i=0; i<A.size(); i++){
        bool no_change = true;
        for(int j=i+1; j<A.size(); j++){
            if(A[i].f > A[j].f){
                p1 = A[i];
                p2 = A[j];
                A[j] = p1;
                A[i] = p2;
                no_change = false;
            }
        }
        if(no_change) break;
    }
}
int kruskals(int V, vector<int> us, vector<int> vs, vector<int> ws) {
    vector<pii> sort_ws;
    for(int i=0; i<ws.size(); i++){
        sort_ws.push_back({ws[i], i});
    }
    bubble_sort(sort_ws);
    for(auto itr : sort_ws){
        cout<<itr.first<<" "<<itr.second<<endl;
    }
    cout<<"\n--------------------\n";
    sort(sort_ws.begin(), sort_ws.end());
    for(auto itr : sort_ws){
        cout<<itr.first<<" "<<itr.second<<endl;
    }
    
    naive_disjoint_set set_(V+1);
    int idx, u, v, w, total_w = 0;
    for(int i=0; i<sort_ws.size(); i++){
        idx = sort_ws[i].second;
        w = sort_ws[i].first;
        u = us[idx];
        v = vs[idx];
        if(set_.merge(u, v)){
            total_w += w;
        }
    }
    return total_w;
}


// old and good one(in term of computation complexity)
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