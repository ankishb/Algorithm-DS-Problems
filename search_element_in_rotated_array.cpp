
#include <bits/stdc++.h>
using namespace std;
#define loop(i, end) for(int i=0; i<end; i++)

// interview bit
int search_element(vector<int> &A, int B){
	int mid, left=0, right=A.size()-1, max_idx=0;
	while(left<=right){
		mid = (left+right)/2;
		if(A[mid] == B){
			return mid;
		}
		// 3 5 1
		if(A[mid] > A[mid+1] && A[mid] > A[mid-1]){
			max_idx = mid;
			left = right+1;
			// break;
		}
		// 1 2 3
		else if(A[mid+1]>A[mid] && A[mid]>A[mid-1]){
			if(A[mid] < A[0]){
				right = mid-1;
			}
			else{
				left = mid+1;
			}
		}
		// 3 2 1
		else{
			right = mid-1;
		}
	}
	cout<<"Max element index: "<<max_idx<<endl;
	if(B >= A[0]){
		left = 0;
		right = max_idx;
        // cout<<"left: "<<left<<" "<<"right: "<<right<<endl;
        
		while(left<=right){
			mid = (left+right)/2;
			if(A[mid] == B){
				return mid;
			}
			else if(B > A[mid]){
				left = mid+1;
			}
			else{
				right = mid-1;
			}
		}
		return -1;
	}
	else{
	    left = max_idx+1;
		right = A.size()-1;
        // cout<<"left: "<<left<<" "<<"right: "<<right<<endl;
        
			while(left<=right){
			mid = (left+right)/2;
			if(A[mid] == B){
				return mid;
			}
			else if(B > A[mid]){
				right = mid-1;
			}
			else{
				left = mid+1;
			}
		}
		return -1;
	}
}

int main()
 {
	int test;
	cin>>test;
	while(test--){
	    int n;
	    cin>>n;
	    int ele;
	    vector<int> vect;
	    loop(i, n){
	    	cin>>ele;
	    	vect.push_back(ele);
	    }
	    int k;
	    cin>>k;
	    cout<<search_element(vect, k)<<endl;
	}
	return 0;
}