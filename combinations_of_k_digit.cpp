
// new program
/*
Note: if we use very first base condition, it will not include last element, in that case you need to use n+1.
    And the reason is that when we push last element n, we start with n+1 in the next iteration, which is greater than n and it miss that.
*/
void helper(int start, int end, int k, vector<vector<int>> &store, vector<int> &temp){
    // if(start > end) return;
    if(temp.size() == k){
        store.push_back(temp);
        return;
    }
    for(int i=start; i<=end; i++){
        temp.push_back(i);
        helper(i+1, end, k, store, temp);
        temp.pop_back();
    }
}

vector<vector<int> > Solution::combine(int n, int k) {
    if(n == 0 || k == 0) return {{}};
    vector<vector<int>> store;
    vector<int> temp;
    helper(1, n, k, store, temp);
    
    // for(auto v : store){
    //     for(auto el : v){
    //         cout<<el<<" ";
    //     }
    //     cout<<endl;
    // }
    return store;
}






// old interviewBit submit
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

vector<vector<int> > Solution::combine(int n, int k) {
    vector<int> temp;
    vector<vector<int> > ans;
    rec(n, 1, k, ans, temp);

    return ans;
}







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
