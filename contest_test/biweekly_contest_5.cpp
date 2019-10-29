
class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        unordered_map<int, int> my_map;
        for(auto itr : A){
        	my_map[itr]++;
        }
        int max_no = -1;
        for(auto itr : my_map){
        	if(itr.second == 1){
        		max_no = max(max_no, itr.first);
        	}
        }
        return max_no;
    }
};


class Solution {
public:
    bool isArmstrong(int N) {
        string temp = to_string(N);
        int n = N.length();
        int no = 0;
        for(int i=0; i<n; i++){
        	no += pow((temp[i]-'0'),n);
        }
        return (no == N);
    }
};






class Solution {
	vector<int> rank;
	vector<int> parent;
	int n;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	    
public:
    // void print_pq(){
    //     while(!pq.empty()){
    //         cout << pq.top().second <<" ";
    //         pq.pop();
    //     }
    //     cout<<endl;
    // }
        
	void init_set(int n_){
		rank.resize(n_,0);
		parent.resize(n_,0);
		n = n_;
		for(int i=0; i<n_; i++) parent[i] = i;
	}

	void print_parent(){
        for(auto itr : parent) cout<<itr<<" ";
		cout<<endl;
	}

	int find(int x){
		if(parent[x] != x) parent[x] = find(parent[x]);
		return parent[x];
	}


	void merge(int x, int y){
		int parent_x = find(x);
		int parent_y = find(y);
		if(parent_x != parent_y){
			if(rank[parent_x] < rank[parent_y]){
				parent[parent_x] = parent_y;
			}
			else if(rank[parent_x] > rank[parent_y]){
				parent[parent_y] = parent_x;
			}
			else{
				parent[parent_y] = parent_x;
				rank[parent_x] = rank[parent_x] + 1;
			}

		}
	}
	bool check_cycle(){
		if(n==2) return true;
		for(int i=2; i<n; i++){
			if(parent[i] != parent[i-1]){
				return false;
			}
		}
		return true;
	}

	int spanning_tree(vector<pair<int, int>> adj[]){
		int source = 1;
	    vector<int> dist(n, INT_MAX);
	    vector<bool> visited(n);
	    pq.push(make_pair(0, source));
	    // visited[source] = true;

        int temp;
	    int u, v, w, ans=0;
	    while(!pq.empty()){
	        u = pq.top().second;
            temp = pq.top().first;
            pq.pop();
            if(visited[u] == true) continue;
            cout<< u <<" " << temp <<" :: ";
            ans += temp;
            visited[u] = true;

            for(int i=0; i<adj[u].size(); i++){
                v = adj[u][i].first;
                w = adj[u][i].second;

                if(visited[v] == false && w < dist[v]){
                    dist[v] = w;
                    pq.push(make_pair(w, v));
                }
            }
            // print_pq();
	    }
        cout<<endl;
        for(auto itr : dist) cout<< itr<<" ";
        cout<<endl;
	    return ans;
	}
	
    int minimumCost(int N, vector<vector<int>>& conections) {
        init_set(N+1);
        vector<pair<int, int>> adj[N+1];
        int u, v, w;
        for(auto itr : conections){
        	u=itr[0], v=itr[1], w=itr[2];
        	merge(u,v);
        	adj[u].push_back(make_pair(v,w));
        	adj[v].push_back(make_pair(u,w));
        }
        // for(int j=0; j<N+1; j++){
        //     cout<< j <<" :: ";
        //     for(int i=0; i<adj[j].size(); i++) cout<<adj[j][i].first <<" ";
        //     cout<< endl;
        // }
        // print_parent();
        bool check = check_cycle();
        if(!check) return -1;
        parent.clear();
        rank.clear();
        // return 1;
        return spanning_tree(adj);
    }
};







class Solution {
private:
    vector<vector<int>> adj;
    vector<int> vis;
    stack<int> store;
    
public:
    bool helper(int i, int &count){
        vis[i] = -1; // visiting (in progress)
        count++;
        for(auto itr : adj[i]){
            if(vis[itr] == -1) return false;
            // count++;
            if(!vis[itr]){
                if(helper(itr, count) == false) return false;
            }
        }
        vis[i] = 1; // visited
        store.push(i);
        return true;
    }
    
    void topological_sort(int n, bool &cycle, int &max_len){
        vis.resize(n, false);
        int len;
        bool flag;
        for(int i=0; i<n; i++){
        	len = 0;
            if(!vis[i]){
            	bool flag = helper(i, len);
                if(flag == false){
                    cycle = true;
                    break;
                }
                max_len = max(max_len, len);
            }
        }
    }

    int minimumSemesters(int n, vector<vector<int>>& relations) {
        adj.resize(n);
        int u, v;
        for(int i=0; i<relations.size(); i++){
            v = relations[i][0], u = relations[i][1];
            adj[u].push_back(v);
        }
        
        int max_len = 0;
        bool cycle = false;
        topological_sort(n, cycle, max_len);
        if(cycle) return -1;
        return max_len;
    }
};


