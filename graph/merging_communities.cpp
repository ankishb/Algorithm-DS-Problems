
/*
Note: while merging community, we need to update comminity size as size[parent_x] += size[parent_y], if we make parent_y as child of parent_x.
*/

#include <bits/stdc++.h>
using namespace std;
#define ipair pair<int,int>


class disjointSet{
public:
    int n;
    vector<int> parent, rank;
    unordered_map<int,int> my_map;
    disjointSet(int no){
        parent.resize(no);
        rank.resize(no);
        n = no;
        for(int i=0; i<no; i++){
            parent[i] = i;
            my_map[i] = 1;
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
            my_map[py] += my_map[px];
            my_map.erase(px);
        }
        else if(rank[px] > rank[py]){
            parent[py] = px;
            my_map[px] += my_map[py];
            my_map.erase(py);
        }
        else{
            parent[py] = px;
            rank[px]++;
            my_map[px] += my_map[py];
            my_map.erase(py);
        }
    }
    void print(){
        for(int i=1; i<n; i++){
            cout<<parent[i]<<" ";
        }
    }

    int getCommunitySize(int x){
        return my_map[find(x)];
    }
};


int main()
{
    int n, q, u, v;
    cin>>n>>q;
    char qi;
    disjointSet mySet(n+1);
    for(int i=0; i<q; i++){
        cin>>qi;
        if(qi == 'Q'){
            cin>>u;
            cout<<mySet.getCommunitySize(u)<<endl;
        }
        else{
            cin>>u>>v;
            mySet.merge(u, v);
        }
    }
    // mySet.print();
    return 0;
}










// simple disjoint set, no path compression algorithm
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int findset(int x, vector <int> &r) {
    // we compress path here too
    if (r[x]!=x) r[x]=findset(r[x],r);
    return(r[x]);   
}

int main() {
    int n,q;
    cin >> n >> q;
    
    // makeset
    vector <int> root(n+1);
    vector <int> count(n+1);
    for (int i=1;i<=n;i++) {
        root[i]=i;
        count[i]=1;
    }    
    
    while (q--) {
        char t;
        cin >> t;
        
        if (t=='M') {
            int x,y;
            cin >> x >> y;   
            
            // find root of x & y
            int rx=findset(x,root);
            int ry=findset(y,root);
       
            // skip, already in same community
            if (rx==ry) continue;
 
            // do a union not using ranking 
            root[rx]=ry;
            count[ry]+=count[rx];
            count[rx]=0;
        }
        else if (t=='Q') {
            int p;
            cin >> p;
            cout << count[findset(p,root)] << endl;
        }
    }

    return 0;
}