
// new one(and logic is simple(but still 3 test cases left as TLE))
/*
Idea is to collect city-size which are connected
*/
class disjoint_set{
public:
    vector<int> parent, rank;
    unordered_map<int,int> comm;
    disjoint_set(int n){
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=1; i<n; i++){
            comm[i] = 1;
            parent[i] = i;
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
        if(px == py) return ;
        if(rank[px] < rank[py]){
            parent[px] = py;
            comm[py] += comm[px];
            comm.erase(px);
        }
        else if(rank[px] > rank[py]){
            parent[py] = px;
            comm[px] += comm[py];
            comm.erase(py);
        }
        else{
            parent[px] = py;
            comm[py] += comm[px];
            comm.erase(px);
            rank[py]++;
        }
    }
};


// Complete the roadsAndLibraries function below.
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    disjoint_set set_(n+1);
    for(auto road : cities){
        set_.merge(road[0], road[1]);
    }
    long cost = 0;
    for(auto p : set_.comm){
        cout<<p.first<<" "<<p.second<<endl;
        int size = p.second;
        if(size*c_lib <= (size-1)*c_road + c_lib){
            cost += size*c_lib;
        }
        else{
            cost += (size-1)*c_road + c_lib;
        }
    }
    return cost;
}




// old one(passes only 4-5 test cases)
class disjointSet{
public:
    int n;
    vector<int> parent, rank;
    disjointSet(int no){
        parent.resize(no);
        rank.resize(no,0);
        n = no;
        for(int i=0; i<no; i++){
            parent[i] = i;
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
        }
        else if(rank[px] > rank[py]){
            parent[py] = px;
        }
        else{
            parent[py] = px;
            rank[px]++;
        }
    }
    void getSetCount(unordered_map<int,int> &my_map){
        for(int i=1; i<n; i++){
            my_map[parent[i]]++;
        }
    }
};

// Complete the roadsAndLibraries function below.
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    disjointSet dSet(n+1);
    // dSet.init(n+1);
    for(auto c : cities){
        dSet.merge(c[0], c[1]);
        dSet.merge(c[1], c[0]);
    }

    unordered_map<int, int> my_map;
    dSet.getSetCount(my_map);

    long long int cost = 0;
    int count, temp, tCost;
    for(auto itr : my_map){
        count = itr.second;
        if(c_lib <= c_road){
            cost += count*c_lib;
            continue;
        }
        temp = 1;
        tCost = c_lib*temp + (count-temp)*c_road;
        temp++;
        while(temp <= count){
            tCost = min(tCost, c_lib*temp + (count-temp)*c_road);
            temp++;
        }
        cost += tCost;
    }
    return cost;
}
