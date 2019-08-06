
// 3 3
// -5 -4 -1
// -3 2 4 
// 2 5 8
// Ans : 19

// 4 4
// 0 -2 -7 0
// 9 2 -6 2
// -4 1 -4 1
// -1 8 0 -2
// Ans: 15


#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<int> vect){
	for(int i=0; i<vect.size(); i++){
		cout<<vect[i]<<" ";
	}
	cout<<endl;
}

int kadanes_algo(vector<int> vect){
	print_vector(vect);
	int global_max = INT_MIN;
	int cur_sum = 0;
	for(int i=0; i<vect.size(); i++){
		cur_sum	+= vect[i];
		if(global_max < cur_sum){
			global_max = cur_sum;
		}
		if(cur_sum < 0){
			cur_sum = 0;
		}
	}
	cout<<global_max<<"\n \n";
	return global_max;
}

void maximum_sum_submatrix(vector<vector<int> > vect){
	// cout<<"test input matrix\n";
	// for(auto itr1 : vect){
	// 	for(auto itr2 : itr1){
	// 		cout<<itr2<<" ";
	// 	}
	// 	cout<<endl;
	// }
	int global_max = INT_MIN;
	int cur_sum = 0;
	int n1 = vect.size();
	int n2 = vect[0].size();
	
	for(int l=0; l<n2; l++){
		vector<int> temp(n1, 0);
		for(int r=l; r<n2; r++){
			for(int k=0; k<n1; k++){
				// cout<<vect[k][r]<<" ";
				temp[k] += vect[k][r];
			}
			cout<<"\n";
			int cur_sum = kadanes_algo(temp);
			global_max = max(global_max, cur_sum);
		}
	}
	cout<<global_max<<endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n1, n2;
		cin>>n1>>n2;
		int el;
		vector<vector<int> > vect;
		vector<int> temp;
		for(int i=0; i<n1; i++){
			temp.clear();
			for(int j=0; j<n2; j++){
				cin>>el;
				temp.push_back(el);
			}
			vect.push_back(temp);
		}
		maximum_sum_submatrix(vect);
	}
	return 0;
}
