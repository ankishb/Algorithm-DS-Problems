#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> ans;
vector<int> cuts;
vector<vector<LL> > dp;
vector<vector<int> > parent;

LL rec(int l, int r){
    if(l+1 >= r)return 0;
    
    LL &ret = dp[l][r];
    if(ret != -1) return ret;

    ret = LLONG_MAX;
    int bestind;    //stores the best index

    for(int i = l + 1; i < r; i++) {
        //recurrence
        LL p = rec(l,i) + rec(i,r) + (LL)cuts[r] - (LL)cuts[l];

        //update best
        //note that we choose lexicographically smallest index
        //if multiple give same cost
        if(p < ret) {
            ret = p;
            bestind = i;
        }
    }

    //store parent of (l, r)
    parent[l][r] = bestind;

    return ret;
}

//function for building solution
void back(int l, int r){
    //base case
    if(l+1 >= r)return;

    //first choose parent of (l,r)
    ans.push_back(cuts[parent[l][r]]);

    //call back recursively for two new segments
    //calling left segment first because we want lexicographically smallest
    back(l, parent[l][r]);
    back(parent[l][r], r);
}

void solve(int A, vector<int> &B) {
    //insert A and 0
    B.push_back(A);
    B.insert(B.begin(),0);


    int n = B.size();
    cuts.clear();
    
	for(int i = 0; i < n; i++)
        cuts.push_back(B[i]);

    //initialise dp array
    dp.resize(n);
    parent.resize(n);
    ans.clear();
    
    for(int i = 0; i < n; i++){
        
		dp[i].resize(n);
        parent[i].resize(n);
        for(int j = 0; j < n; j++)
            dp[i][j] =- 1;
    }

    //call recurrence
    LL best = rec(0, n-1);
 
    //build solution
    back(0, n-1);
}


int main() {
	
	int arr[] = {1, 2, 5};
	vector<int> v(arr, arr + sizeof arr / sizeof arr[0]);
	solve(6, v);
	
	for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
	return 0;
