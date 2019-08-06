
#include <bits/stdc++.h>
using namespace std;

// merge two sorted array
void merge(vector<int> &A, int l, int m, int r){
    cout<<"Before: ";
    for(int ii=l; ii<=r; ii++){
        if(ii == m+1) cout<<"\t";
        cout<<A[ii]<<" ";
    }
	int n1 = m-l+1;
	int n2 = r-m;

	vector<int> arr1(n1, 0), arr2(n2, 0);
	for(int i=0; i<n1; i++){
		arr1[i] = A[l+i];
	}
	for(int i=0; i<n2; i++){
		arr2[i] = A[m+1+i];
	}

	int idx1=0, idx2=0, k=l;
	// while one of them is true
	while(idx1 < n1 && idx2 < n2){
		if(arr1[idx1] <= arr2[idx2]){
			A[k] = arr1[idx1];
			idx1++; k++;
		}
		else{
			A[k] = arr2[idx2];
			idx2++; k++;
		}
	}
	while(idx1 < n1){
		A[k] = arr1[idx1];
		idx1++; k++;
	}
	
	while(idx2 < n2){
		A[k] = arr2[idx2];
		idx2++; k++;
	}
	
    cout<<"\t After: ";
    for(int ii=l; ii<=r; ii++){
        if(ii == m+1) cout<<"\t";
        cout<<A[ii]<<" ";
    }
    cout<<endl;
}

void merge_sort(vector<int> &A, int l, int r){
	if(l >= r) return;
	int mid = l + (r-l)/2;
	merge_sort(A, l, mid);
	merge_sort(A, mid+1, r);
	merge(A, l, mid, r);
}

int main()
{
	int test; cin>>test;
	while(test--){
		int n; cin>>n;
		vector<int> A(n, 0);
		for(int i=0; i<n; i++){
			cin>>A[i];
		}
		merge_sort(A, 0, n-1);
		cout<<"After merge sort: ";
		for(auto itr : A) cout<<itr<<" ";
		cout<<endl;
	}
	return 0;
}