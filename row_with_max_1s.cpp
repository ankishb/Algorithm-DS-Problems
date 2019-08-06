
#include <bits/stdc++.h>
using namespace std;
#define max_ 1005
int T[max_][max_];

void find_row_with_max_1s(int n, int m){
	int i=0, j=m-1;
	int max_row = 0;
	while(i!=n-1 && T[i][j] == 0){
		if(T[i][j] == 1){
			j--;
			j = max(0, j);
			max_row = max(max_row, n-j);
			cout<<"--"<<max_row<<endl;
			if(j==0){
				break;
			}
		}
		else{
			i++;
			i = min(i, n-1);
		}
	}
	cout<<max_row<<endl;
}

void solve1(){
	int n, m;
	cin>>n>>m;
	// vector<int> vect;
	int count, max_row_1s=INT_MIN, row_idx=-1;
	for(int i=0; i<n; i++){
		count = 0;
		for(int j=0; j<m; j++){
			cin>>T[i][j];
			if(T[i][j] == 1){
				count++;
			}
		}
		if(count > max_row_1s){
			max_row_1s = count;
			row_idx = i;
		}
	}
	cout<<row_idx<<endl;
}

void solve2(){
	int n, m;
	cin>>n>>m;
	vector<int> vect;
	int count, max_row_1s=INT_MIN, row_idx=-1;
	for(int i=0; i<n; i++){
		count = 0;
		for(int j=0; j<m; j++){
			cin>>T[i][j];
			if(T[i][j] == 1){
				count++;
			}
		}
		vect.push_back(count);
	}

	vector<int>::iterator it;
	it = max_element(vect.begin(), vect.end());
	cout<<it-vect.begin()<<endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		// solve1();
		solve2();
		// find_row_with_max_1s(n, m);
	}
	return 0;
}

