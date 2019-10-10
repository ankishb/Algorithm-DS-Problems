

class disjoint{
public:
    vector<int> parent, rank;
    unordered_map<int,int> comm_size;
    disjoint(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0; i<n; i++){
            parent[i] = i;
            comm_size[i] = 1;
        }
    }
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void merge(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px == py) return;
        if(rank[px] < rank[py]){
            parent[px] = py;
            comm_size[py] += comm_size[px];
            comm_size.erase(px);
        }
        else if(rank[px] > rank[py]){
            parent[py] = px;
            comm_size[px] += comm_size[py];
            comm_size.erase(py);
        }
        else{
            parent[px] = py;
            rank[py]++;
            comm_size[py] += comm_size[px];
            comm_size.erase(px);
        }
    }
    vector<int> get_comm_size(){
        vector<int> size;
        for(auto itr : comm_size){
            size.push_back(itr.second);
        }
        return size;
    }
};

// Complete the journeyToMoon function below.
int journeyToMoon(int n, vector<vector<int>> A) {
    disjoint d(n);
    for(auto e : A){
        d.merge(e[0], e[1]);
    }
    vector<int> c_size = d.get_comm_size();
    for(auto c : c_size) cout<<c<<" "; cout<<endl;

    int ans = 0, m = c_size.size();
    for(int i=0; i<m; i++){
        for(int j=i+1; j<m; j++){
            ans += c_size[i]*c_size[j];
        }
    }
    return ans;
}