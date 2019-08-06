
#include <bits/stdc++.h>
using namespace std;

void get_subsets(vector<int> &A){
	vector<vector<int> > ans;
	int temp;
	for(int i=0; i<pow(2, A.size()); i++){
		temp = i;
		vector<int> v;
		if(i==0){
			ans.push_back(v);
			// ans.insert(v);
		}
		else{
			int j = A.size()-1;
			while(temp!=0){
				if(temp&1 == 1){
					v.push_back(A[j]);
				}
				j--;
				temp = temp>>1;
			}
			sort(v.begin(), v.end());
			ans.push_back(v);
			// ans.insert(v);
		}
	}
	sort(ans.begin(), ans.end());

	cout<<"\n All subset of given vectors \n";
	for(auto itr: ans){
		for(auto itr2: itr){
			cout<<itr2;
		}
		cout<<endl;
	}


// 	for(int i=0; i<ans.size(); i++){
// 	// 	for(int j=0; j<ans[i].size(); j++){

// 	// set<vector<int> >::iterator itr;
// 	// for(itr=ans.begin(); itr!=ans.end(); ++itr){
// 		for(int j=0; j<ans[i].size(); j++){
// 			cout<<ans[i][j];
// 		}
// 		cout<<endl;
// 	}
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n, el;
		cin>>n;
		vector<int> vect;
		while(n--){
			cin>>el;
			vect.push_back(el);
		}

		get_subsets(vect);
	}
	return 0;
}