// Given an integer N, how many structurally unique binary search trees are there that store values 1...N?

// How many labeled Binary Trees can be there with n nodes?
// To count labeled trees, we can use above count for unlabeled trees. The idea is simple, every unlabeled tree with n nodes can create n! different labeled trees by assigning different permutations of labels to all nodes.

// Therefore,

// Number of Labeled Tees = (Number of unlabeled trees) * n!
//                        = [(2n)! / (n+1)!n!]  × n!

// Labeled Tree   : Binary tree
// unlabeled Tree : Binary Serach tree

#include <bits/stdc++.h>
using namespace std;

int current_binary_tree_count(int n, int arr[]){
	int hash[n] = {0}; // for n, (n-1) is the max value, we get
	int result = 0;
	for(int i=1; i<=n; i++){
		if(i-1 == 0){
			cout<<"- "<<n-i<<endl;
			result += arr[n-i];
		}
		else if(n-i == 0){
			cout<<"- "<<i-1<<endl;
			result += arr[i-1];
		}
		else{
			cout<<"- "<<i-1<<" "<<n-i<<endl;
			result += arr[i-1]*arr[n-i];
		}
	}

	// int result=0;
	// cout<<"----- debug ---------"<<endl;
	// for(int i=1; i<n; i++){
	// 	cout<<i<<" "<<hash[i]<<" "<<arr[i]<<endl;
	// }
	// for(int i=1; i<n; i++){
	// 	result += hash[i]*arr[i];
	// }
	return result;
}

int count_binary_tree(){
	int n;
	cin>>n;

	if(n==1){
		return 1;
	}
	if(n==2){
		return 2;
	}
	// if(n==3){
	// 	return 5;
	// }

	int arr[n+1] = {0};
	arr[1] = 1;
	arr[2] = 2;
	// arr[3] = 5;
	
	for(int i=3; i<=n; i++){
		arr[i] = current_binary_tree_count(i, arr);
	}

	return arr[n];
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		cout<<count_binary_tree()<<endl;
	}
	return 0;
}
