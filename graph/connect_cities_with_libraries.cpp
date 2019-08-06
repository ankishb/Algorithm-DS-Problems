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
