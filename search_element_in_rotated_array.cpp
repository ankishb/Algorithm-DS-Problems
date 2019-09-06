class Solution {
public:
    int search(vector<int>& A, int t) {
        int n = A.size();
        if(n == 0) return -1;
        if(n == 1) return (A[0] == t) ? 0 : -1;
        // search pivot
        int l = 0, r = n-1, pivot, mid;
        while(l < r){
            mid = l + (r - l)/2;
            if(A[mid] > A[r]) l = mid+1;
            else r = mid;
        }
        pivot = l;
        int rot = l, _mid;
        l = 0, r = n-1;
        while(l <= r){
            mid = l + (r - l)/2;
            _mid = (mid+rot)%n;
            if(A[_mid] == t) return _mid;
            else if(A[_mid] > t) r = mid-1;
            else l = mid+1;
        }
        
        return -1;
    }
};



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