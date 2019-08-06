
#include <bits/stdc++.h>
using namespace std;

void count_distinct_element_in_window(vector<int> vect, int k){
	unordered_map<int, int> my_map;
	for(int i=0; i<k; i++){
		my_map[vect[i]]++;
	}
	vector<int> ans;
	ans.push_back(my_map.size());
	for(int i=k; i<vect.size(); i++){
		cout<<"--------------\n";
		cout<<i<<" -- "<<i-k<<endl;
		my_map[vect[i-k]]--;
		if(my_map[vect[i-k]] == 0 && vect[i-k]!=vect[i]){
			my_map.erase(vect[i-k]);
		}
		my_map[vect[i]]++;
		ans.push_back(my_map.size());
		for(auto itr : my_map){
			cout<<itr.first<<" : "<<itr.second<<endl;
		}
	}

	cout<<"\n final answer \n";
	for(int i=0; i<ans.size(); i++){
		cout<<ans[i]<<" ";
	}

}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int k, n, el;
		cin>>n;
		vector<int> vect;
		while(n--){
			cin>>el;
			vect.push_back(el);
		}
		cin>>k;
		count_distinct_element_in_window(vect, k);
	}
	return 0;
}