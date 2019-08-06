
#include <bits/stdc++.h>
using namespace std;

void get_indices(int arr[], int left, int right){
	if(left > right){
		return ;
	}
	int n = rand() % (right - left + 1) + left;
	cout<<arr[n]<<endl;
	// indices.push_back(n);

	get_indices(arr, left, n-1);
	get_indices(arr, n+1, right);
}

vector<int> fixed_get_indices(vector<int> indices, int left, int right){
	srand(10);

	if(left > right){
		return indices;
	}
	int n = rand() % (right - left + 1) + left;
	cout<<n<<endl;
	indices.push_back(n);

	indices = fixed_get_indices(indices, left, n-1);
	indices = fixed_get_indices(indices, n+1, right);
}

void shuffle_data(int arr[], int n){
	vector<int> indices;
	// get_indices(arr, 0, n-1);
	indices = fixed_get_indices(indices, 0, n-1);
	cout<<indices.size()<<endl;

	// int shuffled_arr[n] = {0};
	// for(int i=0; i<n; i++){
	// 	shuffled_arr[indices[i]] = arr[i];
	// }

	// cout<<endl<<"==== shuffled w/o seed ===="<<endl;
	// for(int i=0; i<n; i++){
	// 	cout<<shuffled_arr[i]<<" ";
	// }
}

void shuffle_data(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}

	cout<<"hello! entering in debugging mode"<<endl;
	shuffle_data(arr, n);
	// fixed_shuffle_data(arr, n);
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		shuffle_data();
	}
	return 0;
}