
#include <bits/stdc++.h>
using namespace std;

/*
By default in c++, it is Intro-Sort, which is combination of
Quick-Sort, Heap-Sort and Insertion-Sort. It has best, avg
and worst time complexity is O(N log(N))
===========================================================
- [x] bubble sort
- [x] insertion sort
- [ ] selection sort
- [x] quick sort
- [x] merge sort
- [x] heap sort
===========================================================


===========================================================
						Bubble Sort
===========================================================
Method:
1. Run two loop, outer loop indicate where to start
2. Swap the elements, if current element is bigger than right element
- doing this, at each step, it will take bigger element at the right hand side

Optimized Implementation:
The above function always runs O(n^2) time even if the array is sorted. It can be optimized by stopping the algorithm if inner loop didn’t cause any swap.

Worst and Average Case Time Complexity: O(n*n). Worst case occurs when array is reverse sorted.
Best Case Time Complexity: O(n). Best case occurs when array is already sorted.
Auxiliary Space: O(1)
Boundary Cases: Bubble sort takes minimum time (Order of n) when elements are already sorted.
Sorting In Place: Yes
Stable: Yes
===========================================================


===========================================================
						Insertion Sort
===========================================================
Method:
1. run 2 loop
2. At each loop, we will insert the ith element at the right place in array(0 - i)
- it means at each step i(outer loop), we have array(0 - i) in sorted state

Time Complexity: O(n*2)
Auxiliary Space: O(1)
Boundary Cases: Insertion sort takes maximum time to sort if elements are sorted in reverse order. And it takes minimum time (Order of n) when elements are already sorted.
Algorithmic Paradigm: Incremental Approach
Sorting In Place: Yes
Stable: Yes
Uses: Insertion sort is used when number of elements is small. It can also be useful when input array is almost sorted, only few elements are misplaced in complete big array.
===========================================================

This task is simple and O(m+n) if we are allowed to use extra space. But it becomes really complicated when extra space is not allowed and doesn’t look possible in less than O(m*n) worst case time.


===========================================================
						Quick Sort
===========================================================
Method:
1. Select a pivot element(random or last element)
2. bucketization of array as
	1. place all smaller element than pivot, in the left side
	2. place all bigger element in the right side
- At each iteration, we place the pivot at right place in the array

low  --> Starting index,  high  --> Ending index
quickSort(arr[], low, high)
{
    if (low < high)
    {
        // pi is partitioning index, arr[pi] is now
           at right place 
        pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);  // Before pi
        quickSort(arr, pi + 1, high); // After pi
    }
}
===========================================================


===========================================================
						Merge Sort
===========================================================
Method:
1. At each iteration, we split the array in two half till we have at most 2 element
2. Now sort each split and merge with other split to prepare the original split

Complexity (On merging): Time: O(m+n), Space: O(m+n)
Complexity (On merging): Time: O(m*n), Space: O(1)
Overall Complexity: 		Time O(nlogn), Space: O(n) [worst, average, best]
Algorithmic Paradigm: 	Divide and Conquer
Stable: 					Yes
Uses: 
	1. Merge sort on linked list
	2. Inversion Count
	3. Extrenal Sort (External sorting is required when the data being sorted do not fit into the main memory of a computing device (usually RAM) and instead they must reside in the slower external memory, usually a hard disk drive.)
===========================================================
low  --> Starting index,  high  --> Ending index 
mergeSort(arr[], low, high)
{
    if (low < high)
    {
        mid = low + (high - low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
		   merge(arr, low, mid, high); // merge two sorted array
    }
}
===========================================================
*/




void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int arr[], int n){
	bool swap_flag;
	for(int i=0; i<n-1; i++){
		swap_flag = false;
		for(int j=0; j<n-1; j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j], arr[j+1]);
				swap_flag=true;
			}
		}
		if(swap_flag == false){
			break;
		}
	}
}

void insert_element(int arr[], int el, int sorted_index){
	// need optimization in for loop, by checking the condition...
	for(int i=sorted_index; i>=0; i++){
		if(el < arr[i-1]){
			swap(arr[i-1], el);
		}
	}
	cout<<endl<<"==================="<<endl;
	for(int i=0; i<=sorted_index+1; i++){
		cout<<arr[i]<<" ";
	}
	
}

void insertion_sort(int arr[], int n){

	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	int sorted_till = 0, i;
	for(i=sorted_till+1; i<n; i++){
	
		// // insert_element(arr, arr[i], sorted_till);		
		cout<<endl<<"==================="<<endl;
		for(int j=0; j<=i; j++){
			cout<<arr[j]<<" ";
		}
		cout<<endl;
		for(int j=i-1; j>=0; j--){
			if(arr[j+1] < arr[j]){
				swap(arr[j], arr[j+1]);
			}
		}
		for(int j=0; j<=i; j++){
			cout<<arr[j]<<" ";
		}
		cout<<endl<<"==================="<<endl;
	}
}

int partition(int arr[], int left, int right){
	int pivot_el = arr[right];
	int pivot_index = left-1;
	
	cout<<endl<<"==================="<<endl;
	for(int i=left; i<=right; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	for(int i=left; i<=right-1; i++){
		if(arr[i] <= pivot_el){
			pivot_index++;
			swap(arr[i], arr[pivot_index]);
		}
	}
	pivot_index++;
	swap(arr[pivot_index], arr[right]);
	
	for(int i=left; i<=right; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl<<"==================="<<endl;
	return pivot_index;
}

void quick_sort(int arr[], int left_, int right_){
	int left = left_;
	int right = right_;
	while(left < right){
		// pick right most element as pivot element
		int pivot_index = partition(arr, left, right);

		quick_sort(arr, left, pivot_index-1);
		quick_sort(arr, pivot_index+1, right);
	}
}

void heapify(int arr[], int size, int large_idx){
	int largest_index = large_idx;
	int left = 2*largest_index + 1;
	int right = 2*largest_index + 2;

	// for(int i=0; i<size; i++){
	// 	cout<<arr[i]<<" ";
	// }
	// cout<<endl;

	if(arr[left]>arr[largest_index] && left<size){
		largest_index = left;
	}
	if(arr[right]>arr[largest_index] && right<size){
		largest_index = right;
	}
	if(largest_index != large_idx){
		swap(arr[largest_index], arr[large_idx]);
		// mean it is still not in order, run one more step
		heapify(arr, size, largest_index);
	}
	// cout<<"====== Come out of the recusion ========="<<endl;
}

void heap_sort(int arr[], int size){
	for(int i=size/2-1; i>=0; i--){
		heapify(arr, size, i);
	}
	for(int i=size-1; i>=0; i--){
		for(int j=0; j<size; j++){
			cout<<arr[j]<<" ";
		}
		cout<<endl<<"==========="<<endl;
		
		swap(arr[i], arr[0]);
		heapify(arr, i, 0);
	}
}

void random_partition(int arr[], int start, int end, int n){
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
}





// merge two sorted array
void merge(vector<int> &A, int l, int m, int r){
    // cout<<"Before: ";
    // for(int ii=l; ii<=r; ii++){
    //     if(ii == m+1) cout<<"\t";
    //     cout<<A[ii]<<" ";
    // }
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
	
    // cout<<"\t After: ";
    // for(int ii=l; ii<=r; ii++){
    //     if(ii == m+1) cout<<"\t";
    //     cout<<A[ii]<<" ";
    // }
    // cout<<endl;
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
	int test;
	cin>>test;

	while(test--){
		int n;
		cin>>n;

		int arr[n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}	

		// bubble_sort(arr, n);
		// insertion_sort(arr, n);
		// quick_sort(arr, 0, n-1);
		// heap_sort(arr, n);
		random_partition(arr, 0, n-1, n);

		cout<<endl<<"======== FINAL ANSWER ======="<<endl;
		for(int i=0; i<n; i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
