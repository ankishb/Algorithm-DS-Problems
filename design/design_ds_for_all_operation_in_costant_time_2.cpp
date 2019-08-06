/*
Design a data structure that supports all following operations in average O(1) time. (No Duplicate)

    insert(val): Inserts an item val to the set if not already present.
    remove(val): Removes an item val from the set if present.
    getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
*/


class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */




class RandomizedSet {
public:
	unordered_map<int, int> my_map;
	vector<int> vect;
	int n;
    /** Initialize your data structure here. */
    RandomizedSet() {
        n = 0;
        srand(time(0));
    }

    void print_all(){
        // cout<<"vector: ";
        // for(auto itr : vect) cout<<itr<<" ";
        // cout<<"\nmap: ";
        // for(auto itr : my_map) cout<<"("<<itr.first<<","<<itr.second<<") ";
        // cout<<endl;
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(my_map.find(val) != my_map.end()) return false;
        n = vect.size();
        vect.push_back(val);
        my_map[val] = n;
        print_all();
        return true;
    }
	
	void update_vectore_map(int d_idx){
		int value = vect.back();
		int idx = vect.size() - 1;
		vect.pop_back();
		vect[d_idx] = value;
		my_map[value] = d_idx;
	}

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
    	auto itr = my_map.find(val);
        if(itr != my_map.end()){
        	update_vectore_map(my_map[val]);
        	my_map.erase(itr);
            print_all();
        	return true;
        }
        print_all();
        return false;        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        print_all();
        n = vect.size();
        int idx = rand()%n;
        cout<<idx<<endl;
        return vect[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */