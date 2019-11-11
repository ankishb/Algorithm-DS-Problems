
class Solution {
public:
    void merge(vector<int>& A1, int m, vector<int>& A2, int n) {
        int idx = A1.size();
        m--; n--; idx--;
        while(m >= 0 && n >= 0){
            if(A1[m] > A2[n]){
                A1[idx--] = A1[m--];
            }
            else{
                A1[idx--] = A2[n--];
            }
        }
        while(n >= 0){
            A1[idx--] = A2[n--];
        }
    }
};


// Given two sorted arrays P[] and Q[] in non-decreasing order with size X and Y. The task is to merge the two sorted arrays into one sorted array (in non-decreasing order).

// Note: Expected time complexity is O((X+Y) log(X+Y)). DO NOT use extra space. 

#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)
#define rloop(i, start, end) for(int i=end-1; i>=start; i--)


void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print_array(int arr1[], int arr2[], int n, int m){
	loop(i, 0, n){
		cout<<arr1[i]<<" ";
	}
	// cout<<endl;
	loop(i, 0, m){
		cout<<arr2[i]<<" ";
	}
	cout<<endl;
}

// quadratic time complexity
void merge_sort(int arr1[], int arr2[], int n, int m){
	rloop(i, 0, m){
		if(arr2[i] < arr1[n-1]){
			swap(arr2[i], arr1[n-1]);
			for(int j=n-2; j>=0 && arr1[j+1]<arr1[j]; j--){
				swap(arr1[j+1], arr1[j]);
			}
		}
	}
}

void optimal_merge_sort(int arr1[], int arr2[], int n, int m){
	int gap = ceil((n+m)*1.0/2);
	while(gap != 0){
		cout<<"gap"<<gap<<"--"<<endl;
		int l_idx, r_idx;
		loop(i, 0, n+m-gap){
			l_idx = i;
			r_idx = i+gap;

			cout<<"indexes: "<<l_idx<<" "<<r_idx<<endl;
			// there are 3 possibilities
			// 	1. if both are on left
			// 	2. if both are on right
			// 	3. if one is on left and other is on right
			if(l_idx < n && r_idx < n){
				if(arr1[l_idx] > arr1[r_idx]){
					swap(arr1[l_idx], arr1[r_idx]);
				}
			}
			else if(l_idx >= n && r_idx >= n){
				l_idx -= n;
				r_idx -= n;
				if(arr2[l_idx] > arr2[r_idx]){
					swap(arr2[l_idx], arr2[r_idx]);
				}
			}
			else if(l_idx < n && r_idx >= n){
				r_idx -= n;
				if(arr1[l_idx] > arr2[r_idx]){
					swap(arr1[l_idx], arr2[r_idx]);
				}
			}
		}
		cout<<endl;
		print_array(arr1, arr2, n, m);
		if(gap == 1){
			gap = 0;
		}
		else{
			gap = ceil(gap*1.0/2);
		}
	}
	cout<<endl;
}



void solve(){
	int n, m;
	cin>>n>>m;
	int arr1[n], arr2[m], i;
	loop(i, 0, n){
		cin>>arr1[i];
	}
	loop(i, 0, m){
		cin>>arr2[i];
	}

	if(arr1[0] < arr2[0]){
		// merge_sort(arr1, arr2, n, m);
		optimal_merge_sort(arr1, arr2, n, m);
		print_array(arr1, arr2, n, m);
	}
	else{
		// merge_sort(arr2, arr1, m, n);
		optimal_merge_sort(arr2, arr1, m, n);
		print_array(arr2, arr1, m, n);
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









/*
Appoach:
We are returning vector(num1), therefore we need to place all the smaller item in num1 and all the greater item in num2. To do this, we follows:
1. swap the smaller element from list2 with list1 
2. we place the element in list1 at appropriate position in list1.
*/


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int num1_i = m-1;
        int num2_i = n-1;
        while(num1_i>=0 && num2_i >= 0){// && num1_i != -1){
            cout<<nums1[num1_i]<<" "<<nums2[num2_i]<<endl;
        	if(nums1[num1_i] > nums2[num2_i]){
        		// swap
        		swap(nums2[num2_i], nums1[num1_i]);
        		int j = num1_i;
        		while(j>=1 && nums1[j-1] > nums1[j]){
        			swap(nums1[j], nums1[j-1]);
        			j--;
        		}
        	}
        	else num2_i--;
            
        }
        for(auto itr : nums2){
        	nums1[m] = itr;
            m++;
        }
    }
};