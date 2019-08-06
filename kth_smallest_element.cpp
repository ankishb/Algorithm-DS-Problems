
#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int random_partition(int arr[], int start, int end){
	srand(time(NULL)); 
    int random = start + rand() % (end - start); 
    int pivot = arr[random];

    swap(arr[random], arr[end]);

    int pivot_index = -1;
    for(int i=start; i<=end-1; i++){
    	if(arr[i] < pivot){
    		pivot_index++;
    		swap(arr[pivot_index], arr[i]);
    	}
    } 
    pivot_index++;
    // now move pivot element at right position
    swap(arr[end], arr[pivot_index]);
    cout<<endl<<"pivot element: "<<pivot<<endl;
    return pivot_index;
}

int kth_smallest_element(int arr[], int start, int end, int k){
	if(k>0 && k<= end-start+1){
		cout<<"entering here..."<<endl;
		int pivot_index = random_partition(arr, start, end);
		cout<<"--"<<pivot_index<<"=="<<k-1<<endl;
		if(pivot_index == k-1){
			return arr[pivot_index];
		}
		if(pivot_index > k-1){
			return kth_smallest_element(arr, start, pivot_index-1, k);
		}
		// (k-(pivot_index+1))
		else{
			return kth_smallest_element(arr, pivot_index+1, end, k-(pivot_index+1));
		}
	}
}

int main()
{
	int test;
	cin>>test;

	while(test--){
		int n;
		cin>>n;

		int arr[n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}

		int k;
		cin>>k;

		cout<<kth_smallest_element(arr, 0, n-1, k)<<endl;
	}
	return 0;
}

