class disjointSet{
public:
    int n;
    vector<int> parent, rank;
    disjointSet(int no){
        parent.resize(no);
        rank.resize(no);
        n = no;
        for(int i=0; i<no; i++) parent[i] = i;
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
        if(px == py) return ;
        if(rank[px] < rank[py]) parent[px] = py;
        else if(rank[px] > rank[py]) parent[py] = px;
        else{
            parent[py] = px;
            rank[px]++;
        }
    }
    void update_parent(){
        for(int i=0; i<n; i++){
            int j = find(i);
        }
    }
    void getCount(unordered_map<int,int>&map){
        update_parent();
        // for(int i=1; i<n; i++){
        //     cout<<i<<" "<<parent[i]<<endl;
        //     map[parent[i]]++;
        // }
        for(auto p : parent){
            cout<<p<<" ";
            map[p]++;
        }
    }
};

vector<int> componentsInGraph(vector<vector<int>> gb) {
    int n = gb.size();
    disjointSet mySet(2*n+1);
    for(auto e : gb){
        mySet.merge(e[0], e[1]);
        // mySet.merge(e[1], e[0]);
    }
    int minc = INT_MAX, maxc = INT_MIN;
    unordered_map<int,int> map;
    mySet.getCount(map);
    for(auto itr : map){
        if(itr.second > 1) minc = min(minc, itr.second);
        maxc = max(maxc, itr.second);
    }
    vector<int> ans({minc, maxc});
    return ans;
}