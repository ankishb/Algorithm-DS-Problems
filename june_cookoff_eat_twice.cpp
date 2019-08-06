
#include <bits/stdc++.h>
using namespace std;

int get_max_tastiness(unordered_map<int, pair<int, int> > my_map){
	int max1 = INT_MIN, key1, index1;
	for(auto itr : my_map){
		pair<int, int> p = itr.second;
		if(max1 < p.first){
			key1 = itr.first;
			max1 = p.first;
			index1 = p.second;
		}
	}
	// cout<<index1<<" : "<<max1<<endl;
	my_map.erase(key1);

	int max2 = INT_MIN, key2, index2;
	for(auto itr : my_map){
		pair<int, int> p = itr.second;
		if(max2 < p.first){
			key2 = itr.first;
			max2 = p.first;
			index2 = p.second;
		}
	}
	// cout<<index2<<" : "<<max2<<endl;
	return max1+max2;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n, m;
		cin>>n>>m;
		int day, tastiness;
		unordered_map<int, pair<int, int> > my_map;
		for(int i=0; i<n; i++){
			cin>>day>>tastiness;
			
			// check if current day is lie in range m
			if(day > m) continue;
			// if item exist on the same day, keep the item with maximum tastiness
			if(my_map.find(day) != my_map.end()){
				pair<int, int> p = my_map[day];
				// if current item's tastiness more, then update it
				if(p.first < tastiness){
					my_map[day] = make_pair(tastiness, i);
				}
			}
			else{
				my_map[day] = make_pair(tastiness, i);
			}
		}

		int ans = get_max_tastiness(my_map);
		cout<<ans<<endl;
	}
	return 0;
}