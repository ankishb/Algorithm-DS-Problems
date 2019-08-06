/*
Approach:
1. Maintain a queue, to collect the rotten oranges place initially. Push (-1,-1) at end.
2. While queue is not empty, which can be Checked by using delimiter, just like levele order transversal
	1. while queue not empty:
		1. Check for each neighbour, if there is a fresh orange
		2. rot it push it back in the queue
		3. pop current element
	2. Pop current  

3. At last, Check if every orange is rotten now, if not return -1
*/

#include <bits/stdc++.h>
using namespace std;
#define vvect vector<vector<int> >
#define vect vector<int>

void solve(){
	int r, c;
	cin>>r>>c;
	vvect T(r, vect(c, 0));
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			cin>>T[i][j];
		}
	}

	cout<<"------ rotten oranges --------- \n";
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			cout<<T[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
 {
	int test;
	cin>>test;
	while(test--){
	    solve();
	}
	return 0;
}