
#include <bits/stdc++.h>
using namespace std;

void attendance_record(){
	int n;
	cin>>n;
	string first, second;
	unordered_map<string, int> my_map;
	vector<pair<string, string> > vect;
	for(int i=0; i<n; i++){
		cin>>first>>second;
		vect.push_back(make_pair(first, second));
		my_map[first]++;
	}
	for(auto itr:vect){
		if(my_map[itr.first] == 1){
			cout<<itr.first<<'\n';
		}
		else{
			cout<<itr.first<<" "<<itr.second<<"\n";
		}
	}
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		attendance_record();
	}
	return 0;
}