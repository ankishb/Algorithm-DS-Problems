// Given two sorted arrays A and B of size M and N respectively and an element k. The task is to find the element that would be at the k’th position of the final sorted array.

#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)
#define rloop(i, start, end) for(int i=end-1; i>=start; i--)


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

void solve(){
	int n, m, k;
	cin>>n>>m>>k;
	int arr1[n], arr2[m], i;
	loop(i, 0, n){
		cin>>arr1[i];
	}
	loop(i, 0, m){
		cin>>arr2[i];
	}

	int idx1=0, idx2=0;
	while(idx1<n && idx2<m && k--){

		if(k == 0){
			if(arr1[idx1] < arr2[idx2]){
				cout<<arr1[idx1];
			}
			else{
				cout<<arr2[idx2];
			}
		}
		else if(arr1[idx1] < arr2[idx2]){
			idx1++;
		}
		else if(arr1[idx1] > arr2[idx2]){
			idx2++;
		}
	}

	while(idx1<n && k--){
		if(k == 0){
			cout<<arr1[idx1];
		}
		idx1++;
	}

	while(idx2<m && k--){
		if(k == 0){
			cout<<arr2[idx2];
		}
		idx2++;
	}
	cout<<endl;
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




//// same but working
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
	    int n, m, k;
	    cin>>m>>n>>k;
	    int arr1[m] = {0}, arr2[n] = {0};
	    for(int i = 0; i < m; i++) cin>>arr1[i];
	    for(int i = 0; i < n; i++) cin>>arr2[i];
	    
	    int i = 0, j = 0, c = 0, temp;
	    while (i < m && j < n){ 
            c++;
            if (arr1[i] < arr2[j]) {
                temp = arr1[i++]; 
            }
            else{
                temp = arr2[j++];
            }
            if(c == k){
                break;
            }
        } 
        while(i < m && c < k){
            c++;
            temp = arr1[i++];
        }
        while(j < n && c < k){
            c++;
            temp = arr2[j++];
        }
        k < (m + n + 1) ?cout<<temp<<endl : cout<<"-1\n";
	}
	return 0;
}