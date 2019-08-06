
#include <bits/stdc++.h>
using namespace std;

void solve1(){
	int n1, n2;
	cin>>n1>>n2;
	int el;
	unordered_map<int, int> my_map;
	for(int i=0; i<n1; i++){
		cin>>el;
		my_map.insert({el, i});
	}

	vector<int> v2;
	for(int i=0; i<n2; i++){
		cin>>el;
		if(my_map.find(el) == my_map.end()){
			// Not found element in map
			v2.push_back(el);
		}
	}
}

// solving using merge sort
void solve(){
	int n1, n2;
	cin>>n1>>n2;
	int el;
	
	vector<int> v1;
	for(int i=0; i<n1; i++){
		cin>>el;
		v1.push_back(el);
	}
	vector<int> v2;
	for(int i=0; i<n2; i++){
		cin>>el;
		v2.push_back(el);
	}

	int left1 = 0, left2 = 0;
	while(left1<n1 || left2<n2){
		if(v1[left1] == v2[left2]){
			cout<<v1[left1]<<" ";
			left1++;
			left2++;
		}
		else if(v1[left1] < v2[left2]){
			cout<<v1[left1]<<" ";
			left1++;
		}
		else{
			cout<<v2[left2]<<" ";
			left2++;
		}
	}
	while(left1 < n1){
		cout<<v1[left1]<<" ";
		left1++;
	}
	while(left2 < n2){
		cout<<v2[left2]<<" ";
		left2++;
	}
	cout<<endl;

}

int main()
{
	int test;
	cin>>test;
	while(test--){
		solve();
	}
}