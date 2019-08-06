class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        vector<int> parent(n, 0);
        for(int i=0; i<n; i++) parent[i] = i;
        
        int min_parent, max_parent;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=j && M[i][j]==1 && parent[i] != parent[j]){
                    if(parent[i] > parent[j]){
                        min_parent = j; max_parent = i
                    }
                    else{
                        min_parent = j; max_parent = i;
                    }
                    while(parent[max_parent] != max_parent){
                        parent[max_parent] = min_parent;
                    }
                    
                }
            }
        }
        
        sort(parent.begin(), parent.end());
        int friend_circle = 1;
        for(int i=1; i<n; i++){
            if(parent[i] == parent[i-1]) continue;
            friend_circle++;
        }
        parent.clear();
        return friend_circle;
    }
};















// union by rank and path compression
// There are 3 cases:
// rank[x] > rank[y], parent[y] = x;
// rank[x] < rank[y], parent[x] = y;
// rank[x] == rank[y], pick anyone, and rank++
class findUnion{
public:
    int *parent;
    int *rank;
    findUnion(int n){
        parent = new int[n * sizeof(int)];
        rank = new int[n * sizeof(int)];
        for(int i=0; i<n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int i){
        if(parent[i] == !i){
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void Union(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);

        if(rank[x_parent] < rank[y_parent]){
            parent[x_parent] = y_parent;
        }
        else if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        }
        else{
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        }
    }
    
    void print_(int n){
        for(int i=0; i<n; i++){
            cout<<parent[i]<<" ";
        }
        cout<<endl;
        for(int i=0; i<n; i++){
            cout<<rank[i]<<" ";
        }
        cout<<endl;
    }
    
    int get_count(int n){
        sort(parent, parent+n);
        int count = 1;
        cout<<parent[0]<<" ";
        for(int i=1; i<n; i++){
            cout<<parent[i]<<" ";
            if(parent[i] == parent[i-1]) continue;
            count++;
        }
        cout<<endl;
        return count;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        findUnion disjoint_set(n);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=j && M[i][j]==1){
                    disjoint_set.Union(i, j);
                }
            }
        }
        
        disjoint_set.print_(n);
        return disjoint_set.get_count(n);
    }
};





[
    [1,1,0,0,0,0,0,1,0,0,0,0,0,0,0],
    [1,1,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,1,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,1,0,1,1,0,0,0,0,0,0,0,0],
    [0,0,0,0,1,0,0,0,0,1,1,0,0,0,0],
    [0,0,0,1,0,1,0,0,0,0,1,0,0,0,0],
    [0,0,0,1,0,0,1,0,1,0,0,0,0,1,0],
    [1,0,0,0,0,0,0,1,1,0,0,0,0,0,0],
    [0,0,0,0,0,0,1,1,1,0,0,0,0,1,0],
    [0,0,0,0,1,0,0,0,0,1,0,1,0,0,1],
    [0,0,0,0,1,1,0,0,0,0,1,1,0,0,0],
    [0,0,0,0,0,0,0,0,0,1,1,1,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,1,0,0],
    [0,0,0,0,0,0,1,0,1,0,0,0,0,1,0],
    [0,0,0,0,0,0,0,0,0,1,0,0,0,0,1]
]

