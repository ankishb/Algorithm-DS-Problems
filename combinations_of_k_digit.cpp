

#include <bits/stdc++.h>
using namespace std;

void rec(int n, int j, int k, vector<vector<int> > &ans, vector<int> &temp){
    if(temp.size() == k){
        ans.push_back(temp);
        return ;
    }
    for(int jj=j; jj<=n; jj++){
        temp.push_back(jj);
        rec(n, jj+1, k, ans, temp);
        temp.pop_back();
    }
}

void get_all_combination(int n, int k){
    vector<int> temp;
    vector<vector<int> > ans;
    rec(n, 1, k, ans, temp);

    cout<<"\n All combinations \n";
    for(auto itr1:ans){
        for(auto itr2 : itr1){
            cout<<itr2<<" ";
        }
        cout<<endl;
    }
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n, k;
        cin>>n>>k;
        get_all_combination(n, k);
	}
	return 0;
}
