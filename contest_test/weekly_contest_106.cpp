
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n = A.size();
        if(n <= 1) return A;
        int even_i=0, odd_i=1;
        int odd_n, even_n;
        if(n%2 == 0){
        	odd_n = n-1;
        	even_n = n-2;
        }
        else{
        	odd_n = n-2;
        	even_n = n-1;
        }
        while(odd_i<=odd_n && even_i<=even_n){
            cout<<odd_i<<" "<<even_i<<" :: ";
        	// first find the places for both even_i and odd_i
        	while(odd_i<=odd_n && A[odd_i]%2 == 1){
        		odd_i += 2;
        	}
        	while(even_i<=even_n && A[even_i]%2 == 0){
        		even_i += 2;
        	}
            
            cout<<odd_i<<" "<<even_i<<endl;
            if(odd_i<=odd_n && even_i<=even_n){
                swap(A[odd_i], A[even_i]);
            }
            else{ break; }
        	
            odd_i += 2;
            even_i += 2;
        }
        return A;
    }
};









class Solution {
public:
	void get_count(vector<int> A, int k, int cur_sum, int idx, int &count){
		if(cur_sum > k) return;
		if(cur_sum == k) count++;
		for(int i=idx; i<A.size(); i++){
			get_count(A, k, cur_sum+A[i], i+1, count);
		}
	}

    int threeSumMulti(vector<int>& A, int target) {
        int count = 0;
        int cur_sum = 0;
        sort(A.begin(), A.end());
        get_count(A, target, cur_sum, 0, count);
        return count;
    }
};







class Solution {
public:
    void print_stack(stack<char> s){
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
    }
    int minAddToMakeValid(string str) {
    	stack<char> s;
    	int i=0, n=str.length();
    	while(i < n){
    		if(s.empty()) s.push(str[i]);
    		else if(str[i] == ')'){
    			if(!s.empty() && s.top()=='('){
    				s.pop();
    			}
                else s.push(str[i]);
    		}
    		else s.push(str[i]);
    		i++;
    	}
        print_stack(s);
    	return s.size();
    }
};











class DisjointSet{
	vector<int> rank;
	vector<int> parent;
	int n;

public:
	DisjointSet(int n_){
		vector<int> temp(n_, 0);
		rank = temp;
		parent = temp;
		n = n_;
		makeset();
	}

	void makeset(){
		for(int i=0; i<n; i++){
			parent[i] = i;
		}
	}

	void print_parent(){
        for(auto itr : parent) cout<<itr<<" ";
		cout<<endl;
	}
    
    void get_data(unordered_map<int, int> &my_map){
        for(auto itr : parent){
            my_map[itr]++;
        }
    }

	int find(int x){
		if(parent[x] != x){
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}

	void union_(int x, int y){
		int x_set = find(x);
		int y_set = find(y);
		// if both element belong to same set
		if(x_set == y_set){
			return ;
		}
		// find rank of them, take union according
		// 1. Choose parent to that set, which have higher rank
		// 2. If rank equal, run path compression algo
		if(rank[x_set] < rank[y_set]){
			parent[x_set] = y_set;
		}
		else if(rank[x_set] > rank[y_set]){
			parent[y_set] = x_set;
		}
		else{
			parent[y_set] = x_set;
			rank[x_set] = rank[x_set]+1;
		}
	}
};


class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
    	int n = graph.size();
    	DisjointSet set(n);
    	for(int i=0; i<n; i++){
    		for(int j=0; j<n; j++){
    			if(graph[i][j] == 1){
    				set.union_(i, j);
    			}
    		}
    	}
    	
        unordered_map<int, int> my_map;
    	set.print_parent();
        set.get_data(my_map);
        
        sort(initial.begin(), initial.end());
        int parent, cost_i;
    	int m = initial.size();
    	vector<int> cost(m, 0);
    	for(int i=0; i<m; i++){
    		parent = set.find(initial[i]);
            cost_i = my_map[parent];
            cost[i] = cost_i;
    	}
        
        int ans = INT_MIN;
        int id = 0;
        for(int i=0; i<m; i++){
            if(ans < cost[i]){
                ans = cost[i];
                id = i;
            }
        }  
    	return initial[id];
    }
};