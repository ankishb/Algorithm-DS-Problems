
#include <bits/stdc++.h>
using namespace std;

class fenwick_tree{
public:
    vector<int> bit;
    fenwick_tree(int n){
        bit.resize(n+1, 0);
    }
    
    void update(vector<int> A, int idx, int val){
        int n = A.size()+1;
        int diff = val - A[idx];
        idx++;
        while(idx < n){
            bit[idx] += diff;
            idx += (idx & -idx);
        }
    }
    
    int range_sum(vector<int> A, int l, int r){
        int idx, sum_l = 0, sum_r = 0;
        idx = l;
        while(idx > 0){
            sum_l += bit[idx];
            idx -= (idx & -idx);
        }
        idx = r+1;
        while(idx > 0){
            sum_r += bit[idx];
            idx -= (idx & -idx);
        }
        return sum_r - sum_l;
    }
};


int main() {
    int n;
    cin>> n;
    vector<int> A(n);
    for(int i=0; i<n; i++){
        cin>> A[i];
    }
	fenwick_tree bit(n);
	// construct tree
	for(int i=0; i<n; i++){
	    bit.update(A, i, 2*A[i]);    
	}
	for(int i=0; i<=n; i++){
	    cout<<bit.bit[i]<<" ";
	}
	cout<<endl;
	
	int nq;
	cin>> nq;
	for(int i=0; i<nq; i++){
	    int q_type;
	    cin>> q_type;
	    if(q_type == 1){ // range sum
	        int l, r;
	        cin>> l >> r;
	        cout<< bit.range_sum(A, l, r) << endl;
	    }
	    else if(q_type == 2){ // update value
	        int idx, val;
	        cin>> idx >> val;
	        bit.update(A, idx, val);
	    }
	}
	
	return 0;
}
/*
1
7
1 2 3 4 5 6 7
15
1 2 4
1 1 3
1 2 5
1 4 6
1 1 6
2 2 4
1 2 4
1 1 3
1 2 5
2 1 -1
2 4 9
1 2 4
1 1 3
1 1 5
1 4 6

tree: 0 1 3 3 10 5 11 7 
12
9
18
18
27

13
10
19

17
7
22
22
*/