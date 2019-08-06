
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL) return true;
        if(root1==NULL || root2==NULL) return false;
        if(root1->val != root2->val) return false;
        // cout<< root1->val <<" "<< root2->val << endl;
        
        bool left_same = flipEquiv(root1->left, root2->left);
        bool right_same = flipEquiv(root1->right, root2->right);
        bool left_mirror = flipEquiv(root1->left, root2->right);
        bool right_mirror = flipEquiv(root1->right, root2->left);
        
        return (left_same && right_same)
            || (left_mirror && right_mirror);
    }
};







class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        deque<int> dq;
        for(int i=n-1; i>=0; i--){
        	if(dq.size()>1){
        		dq.push_front(dq.back());
        		dq.pop_back();
        	}
        	dq.push_front(deck[i]);
        }
        vector<int> ans;
        while(!dq.empty()){
        	ans.push_back(dq.front());
        	dq.pop_front();
        }
        return ans;
    }
};




class Solution {
private:
	stack<pair<int, int>> store;
	vector<int> cur;
	vector<bool> mask(4, false);
public:
	void store_it(){
		int a = cur[0]*cur[1];
		int b = cur[2]*cur[3];
		if(a <= 23 && b <= 59){
			store.push(make_pair(a, b));
		}
	}

	void get_permutation(vector<int> A){
		if(cur.size() > 4) return;
		if(cur.size() == 4) store_it();

		for(int i=0; i<A.size(); i++){
			if(mask[i] == false){
				mask[i] = true;
				cur.push_back(A[i]);
				get_permutation(A);
				mask[i] = false;
				cur.pop_back();
			}
		}
	}

    string largestTimeFromDigits(vector<int>& A) {
        get_permutation(A);
        if(store.size() == 0) return "";
        pair<int, int> temp = store.top();
        int a=temp.first, b=temp.second;
        store.pop()

        while(!store.empty()){
        	if(store.top()->first > a){
        		a = store.top().first;
        		b = store.top().second;
        	}
        	store.pop();
        }
        string a_ = to_string(a);
        string b_ = to_string(b);
        return a_ + b_;
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

	int get_big_set_size(){
        print_parent();
		unordered_map<int, int> my_map;
		int max_size = 0;
		for(auto itr : parent){
			my_map[itr]++;
			max_size = max(max_size, my_map[itr]);
		}
		return max_size;
	}

	void print_parent(){
        for(auto itr : parent) cout<<itr<<" ";
		cout<<endl;
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

// Function to calculate gcd of two numbers 
int gcd(int a, int b) 
{ 
	if (a == 0) 
		return b; 
	return gcd(b%a, a); 
} 

// Function to calculate all common divisors 
// of two given numbers 
// a, b --> input integer numbers 
int commDiv(int a,int b) 
{ 
	// find gcd of a,b 
	int n = gcd(a, b); 

	// Count divisors of n. 
	int result = 0; 
	for (int i=1; i<=sqrt(n); i++) 
	{ 
		// if 'i' is factor of n 
		if (n%i==0) 
		{ 
			// check if divisors are equal 
			if (n/i == i) 
				result += 1; 
			else
				result += 2; 
		} 
	} 
	return result; 
}

class Solution {
private:
	vector<vector<int>> adj;
public:
// 	int gcd(int a, int b){
// 		if(a == 0) return b;
// 		return (b%a, a);
// 	}

// 	int common_div(int a, int b){
// 		int n = gcd(a, b);
// 		// Count divisors of n. 
// 	    int result = 0; 
// 	    for (int i=1; i<=sqrt(n); i++){ 
// 	        // if 'i' is factor of n 
// 	        if (n%i==0){ 
// 	            // check if divisors are equal 
// 	            if (n/i == i) result += 1; 
// 	            else result += 2; 
// 	        } 
// 	    } 
// 	    return result; 
// 	}

    int largestComponentSize(vector<int>& A) {
        // adj.resize(A.size());
        if(A.size() <= 1) return 0;
        DisjointSet set_(A.size());
        vector<vector<int>> edges;
        
        for(int i=0; i<A.size(); i++){
        	for(int j=i+1; j<A.size(); j++){
                if(commDiv(A[i], A[j]) > 1){
                    cout<< A[i] <<" "<< A[j] <<" : "<< commDiv(A[i], A[j]) << endl;
                    edges.push_back({i, j});
                    edges.push_back({j, i});
                    // set_.union_(i, j);
                    // set_.union_(j, i);
                    // adj[i].push_back(i-1);
                    // adj[i-1].push_back(i);
                }
            }
        }
        for(auto edge : edges){
            set_.union_(edge[0], edge[1]);
            cout<< edge[0] <<" "<< edge[1] << endl;
        }
        return set_.get_big_set_size();
    }
};

