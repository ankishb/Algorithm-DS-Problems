
#include <bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int left, int right, int k){
	int mid;
	while(left<=right){
		mid = (left+right)/2;
		if(arr[mid] == k && arr[mid-1]!=k){
			return mid;
		}
		else if(k > arr[mid]){
			left = mid+1;
		}
		else{
			right = mid-1;
		}
	}
}

void count_occurance(int arr[], int n, int k){
	int idx = binary_search(arr, 0, n-1, k);
	int count=0;
	for(int i=idx; i<n; i++){
		if(arr[i]==k){
			count++;
		}
		else{
			break;
		}
	}
	cout<<count<<endl;
}

int main()
{
	int test;
	cin>>test;

	while(test--){
		int k, n;
		cin>>n;

		int arr[n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		cin>>k;

		count_occurance(arr, n, k);
	}
	return 0;
}




/*
int binary_search(vector<int> arr, int left, int right, int k){
    int mid;
    while(left<=right){
        mid = (left+right)/2;
        if(arr[mid] == k && arr[mid-1]!=k){
            return mid;
        }
        else if(k > arr[mid]){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
}


int Solution::findCount(const vector<int> &A, int B) {
// }
// void count_occurance(int arr[], int n, int k){
    int n = A.size();
    int k = B;
    int idx = binary_search(A, 0, n-1, k);
    int count=0;
    for(int i=idx; i<n; i++){
        if(A[i]==k){
            count++;
        }
        else{
            break;
        }
    }
    // cout<<count<<endl;
    return count;
}


*/