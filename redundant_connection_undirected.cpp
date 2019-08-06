// mine solution, doesn;t work, unable to debug

class Solution {
public:
    int find(vector<int> &parent, int i){
		while(i != parent[i]) i = parent[i];
        return i;
	}
    
    bool neighbour(vector<int> &parent, int x, int y){
        int x_set = find(parent, x);
		int y_set = find(parent, y);
        cout<<x_set<<" "<<y_set<<endl;
		if(x_set != y_set) {
            return false;   
        }
        return true;
    }
	void Union(vector<int> &parent, int x, int y){
        parent[x] = y;
	}
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // naiveFindUnion disjoint(2000); // 2000 is chosen randomly (no of vertices)
        vector<int> parent(2000);
        for(int i=0; i<parent.size(); i++){
            parent[i] = i;
        }
        int u, v;
        vector<int> ans;
        for(auto itr : edges){
            u = itr[0];
            v = itr[1];
            if(neighbour(parent, u, v)){
                ans = itr;
            }
            else{
                Union(parent, u, v);
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> p(2000, 0);
        for(int i = 0; i < p.size(); i++ )
            p[i] = i;
        
        vector<int> res;
        for(auto v : edges ){
            int n1 = v[0], n2 = v[1];
            while(n1 != p[n1]) n1 = p[n1];
            while(n2 != p[n2]) n2 = p[n2];
            if( n1 == n2 )
                res = v;
            else
                p[n1] = n2;
        }
        return res;
    }
};



// using DFS approach to detect, if there is a cycle
// Approach:
// 1. DFS tranversal
// 2. For the edge (u,v), For the visited vertex u, if the edge v is also visited, and u is not parent of v, then there is a cycle in graph
// Note: The assumption of this approach is that there are no parallel edges between any two vertices






