
#include <bits/stdc++.h>
using namespace std;

// bool dec_order(const unordered_map<int, int> &m1, const unordered_map<int, int> &m2){
// 	return m1->first > m2->first;
// }

vector<int> get_rank(vector<int> queries, map<int, int> my_map){
	map<int, int>::iterator itr;
	vector<int> ans;
	int m = queries.size();
	int n, ii, q, rank=1;
	bool found;
	for(int i=0; i<m; i++){
		q = queries[i];
		found = false;
		itr = my_map.begin();
		// tranverse through whole map, and find the right position for the query and update rank of all the element after the position
		
		// if(my_map.find(q) != my_map.end()){
		// 	ans.push_back(my_map[q]);
		// 	found = true;
		// }
		// // find position
		while(itr->first > q && found==false){
			cout<<itr->first<<" : "<<itr->second<<endl;
			++itr;
		}
		cout<<itr->first<<" : rank: "<<itr->second<<endl;
		// rank = itr->second;
		// rank++;
		// // update all rank after itr
		// while(itr!=my_map.end() && found==false){
		// 	my_map[itr->first]++;
		// }
		if(!found){
			my_map.insert({q, rank});
		}
		ans.push_back(rank);
		// map<int, int> ordered(my_map.begin(), my_map.end());
		// sort(my_map.begin(), my_map.end(), dec_order);
		for(auto itr_new : my_map){
			cout<<itr_new.first<<" : "<<itr_new.second<<endl;
		}
	}
	return ans;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		int el;
		int rank = 1;
		map<int, int> my_map;
		for(int i=0; i<n; i++){
			cin>>el;
			if(my_map.find(el) == my_map.end()){
				// not found score
				my_map[el] = rank;
				rank++;
			}
		}

		int m;
		cin>>m;
		vector<int> queries(m,0);
		for(int i=0; i<m; i++){
			cin>>queries[i];
		}

		vector<int> ans;
		ans = get_rank(queries, my_map);
		for(auto itr:ans){
			cout<<itr<<" ";
		}
	}
	return 0;
}