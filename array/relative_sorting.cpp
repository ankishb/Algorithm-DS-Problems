
// new one
/*
1. Create map of arr1 (to consider the freq of each element)
2. Iterate over arr2 (as we need to maintian order relative to arr2), 
    and fill new arr with the same frew of element stored in map
3. Iterate over arr1 and fill the ans vector with element doesn't 
    appered in arr2
4. sort the element inserted on step-3
*/
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr2.size();
        unordered_map<int,int> map;
        for(auto a : arr1){
            map[a]++;
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(map.find(arr2[i]) != map.end()){
                while(map[arr2[i]] != 0){
                    ans.push_back(arr2[i]);
                    map[arr2[i]]--;
                }
                map.erase(arr2[i]);
            }
        }
        int idx = ans.size();
        for(auto a : arr1){
            if(map.find(a) != map.end()){
                ans.push_back(a);
            }
        }
        sort(ans.begin()+idx, ans.end());
        return ans;
    }
};

/* Explanation
We need sorting by arr2 first and then the remaining element of arr1 in increasing order
1. Make an hash map, with key in order w.r.t arr2
2. Then we want to sort aall remaining element of arr1 not in arr2,
    we maintain their key as in order what shift them by 1000(upper bound of size of array)
*/
// an elegant approach
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& A, vector<int>& B) {

        int key[1001], idx = 0;
        for (int i = 0; i < 1001; i++) key[i] = 1000+i;
        for (int b : B) key[b] = idx++;
        sort(A.begin(), A.end(), [key](int c, int d){
            return key[c] < key[d];
        });
        return A;
    }
};

// another elegant approach
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        vector<int> key(1001, INT_MAX);
        for(int i=0; i<arr2.size(); i++) {
            key[arr2[i]] = i;
        }
        
        sort(arr1.begin(), arr1.end(), [key](int a, int b) 
             {
                 if (key[a] == key[b] && key[a] == INT_MAX) {
                     return a<b;
                 } else {
                     return key[a] < key[b];
                 }
             });
        return arr1;
    }
};



// old approach and complicated (but good in comparison to memory complexity)
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        unordered_map<int, int> my_map;
        for(auto itr : arr2){
        	my_map.insert({itr, 0});
        }
        vector<int> rest;
        for(int i=0; i<arr1.size(); i++){
        	// if found
        	if(my_map.find(arr1[i]) != my_map.end()){
        		my_map[arr1[i]]++;
        	}
        	else{
        		rest.push_back(arr1[i]);
        	}
        }
        sort(rest.begin(), rest.end());
        int i=0, j=0, count;
        while(i < n){
        	count = my_map[arr2[j]];
        	while(count != 0){
        		arr1[i] = arr2[j];
        		i++;
        		count--;
        	}
        	j++;
        	if(j >= arr2.size()) break;
        }
        j = 0;
        while(i < n){
        	arr1[i] = rest[j];
        	i++; j++;
        }
        return arr1;
    }
};