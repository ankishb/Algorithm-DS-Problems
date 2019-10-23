
class Solution {
public:
    vector<int> parent;
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
    
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        int gps = n;
        parent.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(M[i][j] == 1 && merge(i, j)) gps--;
            }
        }
        return gps;
    }
};