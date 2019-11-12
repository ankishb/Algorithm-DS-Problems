#include <bits/stdc++.h>
using namespace std;

class disjoint_set{
public:
    vector<int> rank, parent;
    unordered_map<int, int> com_size;
    
    disjoint_set(int no){
        rank.resize(no);
        parent.resize(no);
        for(int i=1; i<no; i++){
            parent[i] = i;
            com_size[i] = 1;
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
            com_size[py] += com_size[px];
            com_size.erase(px);
        }
        else if(rank[px] > rank[py]){
            parent[py] = px;
            com_size[px] += com_size[py];
            com_size.erase(py);
        }
        else{
            parent[px] = py;
            com_size[py] += com_size[px];
            rank[py]++;
            com_size.erase(px);
        }
        // cout<<"merged\n";
    }

    vector<int> find_com_size(){
        int min_size = INT_MAX, max_size = 0;
        for(auto c : com_size){
            cout<<c.first<<" "<<c.second<<endl;
            if(c.second > 1 && c.second < min_size){
                min_size = c.second;
            }
            // min_size = min(min_size, c.second);
            max_size = max(max_size, c.second);
        }
        return {min_size, max_size};
    }
};

vector<int> componentsInGraph(vector<vector<int>> gb) {
    disjoint_set sets(gb.size()*2 + 1);
    for(auto e : gb){
        // cout<<"merging--";
        sets.merge(e[0], e[1]);
    }
    return sets.find_com_size();
}







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