
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

void anagramic_pair(vector<string> &A){
	vector<vector<int> > ans;
	unordered_map<string, vector<int> > map_;
	for(int i=0; i<A.size(); i++){
		string temp = A[i];
		sort(temp.begin(), temp.end());
		map_[temp].push_back(i+1);
	}

	for(auto it=map_.begin(); it!=map_.end(); ++it){
		// cout<<endl<<(*it).first<<" -> ";
		cout<<endl<<it->first<<" -> ";
		for(auto it2 = ((*it).second).begin(); it2!=((*it).second).end+(); ++it2)
		cout<<*it2<<" ";
		// ans[it.second] = it.first;
		// ans.push_back(it->second);
	}
	// return ans;
}

int main()
{
	int test;
	cin>>test;
	cin.ignore(1);
	while(test--){
		int n;
		cin>>n;
		string s;
		vector<string> vect;
		while(n--){
			cin>>s;
			vect.push_back(s);
		}
		anagramic_pair(vect);
	}
	return 0;
}