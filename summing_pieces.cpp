// Inp:
// 2
// 10
// 1 12 123 1234 12345 123456 1234567 12345678 123456789 12345678910
// 10
// 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000
// Out: 
// 752017145
// 999906809



#include <bits/stdc++.h>
using namespace std;
#define ll long long int
# define mod 1000000007

void get_all_pieces(vector<int> &vect, vector<vector<int> > &ans, vector<int> &subset, int start, int n){
	if(start >= n){
		// for(auto itr:subset){
		// 	cout<<itr<<" ";
		// }
		cout<<endl;
		ans.push_back(subset);
		return ;
	}

	for(int i=start; i<n; i++){
		cout<<"start: "<<start<<" i: "<<i<<endl;
		// get a sum of subset
		int sum = 0;
		for(int j=start; j<i+1; j++){
			sum += vect[j];
		}
		subset.push_back(sum*(i-start+1));
		get_all_pieces(vect, ans, subset, i+1, n);
		subset.pop_back();
	}
}

void get_pieces_sum(vector<int> &vect, vector<ll> &ans, vector<ll> &subset, int start, int n){
	if(start >= n){
		ll sum = 0;
		for(auto itr:subset){
			sum += itr;
		}
		sum = sum%mod;
		ans.push_back(sum);
		return ;
	}

	for(int i=start; i<n; i++){
		// cout<<"start: "<<start<<" i: "<<i<<endl;
		// get a sum of subset
		ll sum = 0;
		for(int j=start; j<i+1; j++){
			sum += vect[j];
		}
		subset.push_back(sum*(i-start+1));
		get_pieces_sum(vect, ans, subset, i+1, n);
		subset.pop_back();
	}
}

void get_all_subsets(vector<int> vect){
	vector<vector<int> > all_pieces;
	vector<ll> ans;
	vector<ll> subset;
	int n = vect.size();
	// get_all_pieces(vect, all_pieces, subset, 0, n);
	get_pieces_sum(vect, ans, subset, 0, n);

	// for(auto itr1 : all_pieces){
	// 	for(auto itr2 : itr1){
	// 		cout<<itr2<<" ";
	// 	}
	// 	cout<<'\n';
	// }

	ll sum = 0;
	for(auto itr : ans){
		sum += itr;
		cout<<itr<<" ";
	}
	cout<<sum%mod<<endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<int> vect(n,0);
		for(int i=0; i<n; i++){
			cin>>vect[i];
		}
		get_all_subsets(vect);
	}
	return 0;
}