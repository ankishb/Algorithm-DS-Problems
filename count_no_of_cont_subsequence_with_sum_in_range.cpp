// Given an array of non negative integers A, and a range (B, C),
// find the number of continuous subsequences in the array which have sum S in the range [B, C] or B <= S <= C

// Continuous subsequence is defined as all the numbers A[i], A[i + 1], .... A[j]
// where 0 <= i <= j < size(A)

#include <bits/stdc++.h>
using namespace std;

int count_subseq(vector<int> &A, int sum){
	int left=0, right=0;
	int count = 0;
	int seq_sum = 0;
	while(left<=right){
		if(seq_sum+A[right] <= sum && right<A.size()-1){
			seq_sum += A[right];
			right++;
			count++;
		}
		else if(seq_sum+A[right] <= sum && right == A.size()-1){
			seq_sum -= A[left];
			left++;
			count++;
		}
		else{
			seq_sum -= A[left];
			left++;
		}
	}
	cout<<count<<endl;
	return count;
}

int numRange(vector<int> &A, int B, int C) {
	int count=0;
	return count_subseq(A, C) - count_subseq(A, B-1);
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n;
		vector<int> vect;
		int el;
		for(int i=0; i<n; i++){
			cin>>el;
			vect.push_back(el);
		}
		int left, right;
		cin>>left>>right;

		numRange(vect, left, right);
	}
}