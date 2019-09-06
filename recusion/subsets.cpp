
void helper(vector<int> A, int idx, vector<int> &temp, 
    set<vector<int>> &store){
    // store.insert(temp);
    for(int i=idx; i<A.size(); i++){
        temp.push_back(A[i]);
        store.insert(temp);
        helper(A, i+1, temp, store);
        temp.pop_back();
        helper(A, i+1, temp, store);
    }    
}

vector<vector<int> > recusive(vector<int> &A) {
    int n = A.size();
    if(n == 0) return {{}};
    sort(A.begin(), A.end());
    set<vector<int>> store;
    vector<vector<int>> store_;
    vector<int> temp;
    store_.push_back(temp);
    helper(A, 0, temp, store);
    
    for(auto v : store){
        store_.push_back(v);
        // for(auto el : v){
        //     cout<<el<<" ";
        // }
        // cout<<endl;
    }
    
    return store_;
}

vector<vector<int> > iterative(vector<int> &A) {
    int n = A.size();
    if(n == 0) return {{}};
    sort(A.begin(), A.end());
    vector<vector<int>> store;
    vector<int> temp;
    store.push_back(temp);
    int m = pow(2, n);

    for(int i=0; i<n; i++){
        temp.clear();
        // int k = i, j = 0, bit;
        // while(k != 0){
        //     bit = (k&1);
        //     if(bit == 1) temp.push_back(A[j]);
        //     j++;
        //     k = k>>1;
        // }
            
        for(int j=i; j<n; j++){
            temp.push_back(A[j]);
            store.push_back(temp);
        }
        
    }
    
    
    
    for(auto v : store){ for(auto el : v) cout<<el<<" "; cout<<endl; }
    
    return store;
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    return recusive(A);
    // return iterative(A);
}






////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
// using reursion, but could not pass all test
void helper(vector<int> A, int idx, vector<int> &temp, 
    set<vector<int>> &store){
    // store.insert(temp);
    for(int i=idx; i<A.size(); i++){
        temp.push_back(A[i]);
        store.insert(temp);
        helper(A, i+1, temp, store);
        temp.pop_back();
        helper(A, i+1, temp, store);
    }    
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    int n = A.size();
    if(n == 0) return {{}};
    sort(A.begin(), A.end());
    set<vector<int>> store;
    vector<vector<int>> store_;
    vector<int> temp;
    store_.push_back(temp);
    helper(A, 0, temp, store);
    
    for(auto v : store){
        store_.push_back(v);
        // for(auto el : v){
        //     cout<<el<<" ";
        // }
        // cout<<endl;
    }
    
    return store_;
}




// using iterative method (power set)
vector<vector<int> > Solution::subsets(vector<int> &A) {
// void get_subsets(vector<int> &A){
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

    return ans;
    // cout<<"\n All subset of given vectors \n";
    // for(int i=0; i<ans.size(); i++){
    // //     for(int j=0; j<ans[i].size(); j++){

    // // set<vector<int> >::iterator itr;
    // // for(itr=ans.begin(); itr!=ans.end(); ++itr){
    //     for(int j=0; j<ans[i].size(); j++){
    //         cout<<ans[i][j];
    //     }
    //     cout<<endl;
    // }
}





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