
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n, m;
		cin>>n>>m;
		int key;
		unordered_map<int, int> my_map;
		for(int i=0; i<m; i++){
			cin>>key;
			my_map[key] = key;
		}

		// we need to maintain a max_heap as well for storing the count of flavour available at the moment, when the current choice of customer is not available.
		long long int profit = 0;
		vector<int> choices;

		// if item available, then customer pay my price, otherwise, they pay their price.
		int flavour, my_price, their_price;
		for(int i=0; i<n; i++){
			cin>>flavour>>my_price>>their_price;
			if(my_map[flavour] > 0){
				profit += my_price;
				my_map[flavour]--;
				choices.push_back(flavour);
				if(my_map[flavour] == 0){
					my_map.erase(flavour);
				}
			}
			else{
				int flavour_count = INT_MIN;
				for(auto itr : my_map){
					if(itr.second > flavour_count){
						flavour_count = itr.second;
						flavour = itr.first;
					}
				}
				profit += their_price;
				my_map[flavour]--;
				choices.push_back(flavour);
				if(my_map[flavour] == 0){
					my_map.erase(flavour);
				}
			}
		}

		cout<<profit<<endl;
		for(auto itr : choices){
			cout<<itr<<" ";
		}
		cout<<endl;
	}
	return 0;
}