/*
Inputs:  
input_file  : Name of input file. input.txt
output_file : Name of output file, output.txt
run_size : Size of a run (can fit in RAM)
num_ways : Number of runs to be merged

Output:
1) Read input_file such that at most 'run_size' elements
   are read at a time. Do following for the every run read
   in an array.
      a) Sort the run using MergeSort.
      b) Store the sorted run in a temporary file, say 'i' 
         for i'th run.
2) Merge the sorted files using the approach discussed here
*/

// C++ program to implement external sorting using  
// merge sort 
#include <bits/stdc++.h> 
using namespace std; 
  
struct MinHeapNode 
{ 
    // The element to be stored 
    int element; 
  
    // index of the array from which the element is taken 
    int i; 
}; 
  
// Prototype of a utility function to swap two min heap nodes 
void swap(MinHeapNode* x, MinHeapNode* y); 
  
// A class for Min Heap 
class MinHeap 
{ 
    MinHeapNode* harr; // pointer to array of elements in heap 
    int heap_size;     // size of min heap 
  
public: 
    // Constructor: creates a min heap of given size 
    MinHeap(MinHeapNode a[], int size); 
  
    // to heapify a subtree with root at given index 
    void MinHeapify(int); 
  
    // to get index of left child of node at index i 
    int left(int i) { return (2 * i + 1); } 
  
    // to get index of right child of node at index i 
    int right(int i) { return (2 * i + 2); } 
  
    // to get the root 
    MinHeapNode getMin() {  return harr[0]; } 
  
    // to replace root with new node x and heapify() 
    // new root 
    void replaceMin(MinHeapNode x) 
    { 
        harr[0] = x; 
        MinHeapify(0); 
    } 
}; 
  
// Constructor: Builds a heap from a given array a[] 
// of given size 
MinHeap::MinHeap(MinHeapNode a[], int size) 
{ 
    heap_size = size; 
    harr = a; // store address of array 
    int i = (heap_size - 1) / 2; 
    while (i >= 0) 
    { 
        MinHeapify(i); 
        i--; 
    } 
} 
  
// A recursive method to heapify a subtree with root 
// at given index. This method assumes that the 
// subtrees are already heapified 
void MinHeap::MinHeapify(int i) 
{ 
    int l = left(i); 
    int r = right(i); 
    int smallest = i; 
    if (l < heap_size && harr[l].element < harr[i].element) 
        smallest = l; 
    if (r < heap_size && harr[r].element < harr[smallest].element) 
        smallest = r; 
    if (smallest != i) 
    { 
        swap(&harr[i], &harr[smallest]); 
        MinHeapify(smallest); 
    } 
} 
  
// A utility function to swap two elements 
void swap(MinHeapNode* x, MinHeapNode* y) 
{ 
    MinHeapNode temp = *x; 
    *x = *y; 
    *y = temp; 
} 
  
// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for(j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
            arr[k++] = L[i++]; 
        else
            arr[k++] = R[j++]; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
        arr[k++] = L[i++]; 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while(j < n2) 
        arr[k++] = R[j++]; 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l + (r - l) / 2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
  
FILE* openFile(char* fileName, char* mode) 
{ 
    FILE* fp = fopen(fileName, mode); 
    if (fp == NULL) 
    { 
        perror("Error while opening the file.\n"); 
        exit(EXIT_FAILURE); 
    } 
    return fp; 
} 
  
// Merges k sorted files.  Names of files are assumed 
// to be 1, 2, 3, ... k 
void mergeFiles(char *output_file, int n, int k) 
{ 
    FILE* in[k]; 
    for (int i = 0; i < k; i++) 
    { 
        char fileName[2]; 
  
        // convert i to string 
        snprintf(fileName, sizeof(fileName), "%d", i); 
  
        // Open output files in read mode. 
        in[i] = openFile(fileName, "r"); 
    } 
  
    // FINAL OUTPUT FILE 
    FILE *out = openFile(output_file, "w"); 
  
    // Create a min heap with k heap nodes.  Every heap node 
    // has first element of scratch output file 
    MinHeapNode* harr = new MinHeapNode[k]; 
    int i; 
    for (i = 0; i < k; i++) 
    { 
        // break if no output file is empty and 
        // index i will be no. of input files 
        if (fscanf(in[i], "%d ", &harr[i].element) != 1) 
            break; 
  
        harr[i].i = i; // Index of scratch output file 
    } 
    MinHeap hp(harr, i); // Create the heap 
  
    int count = 0; 
  
    // Now one by one get the minimum element from min 
    // heap and replace it with next element. 
    // run till all filled input files reach EOF 
    while (count != i) 
    { 
        // Get the minimum element and store it in output file 
        MinHeapNode root = hp.getMin(); 
        fprintf(out, "%d ", root.element); 
  
        // Find the next element that will replace current 
        // root of heap. The next element belongs to same 
        // input file as the current min element. 
        if (fscanf(in[root.i], "%d ", &root.element) != 1 ) 
        { 
            root.element = INT_MAX; 
            count++; 
        } 
  
        // Replace root with next element of input file 
        hp.replaceMin(root); 
    } 
  
    // close input and output files 
    for (int i = 0; i < k; i++) 
        fclose(in[i]); 
  
    fclose(out); 
} 
  
// Using a merge-sort algorithm, create the initial runs 
// and divide them evenly among the output files 
void createInitialRuns(char *input_file, int run_size, 
                       int num_ways) 
{ 
    // For big input file 
    FILE *in = openFile(input_file, "r"); 
  
    // output scratch files 
    FILE* out[num_ways]; 
    char fileName[2]; 
    for (int i = 0; i < num_ways; i++) 
    { 
        // convert i to string 
        snprintf(fileName, sizeof(fileName), "%d", i); 
  
        // Open output files in write mode. 
        out[i] = openFile(fileName, "w"); 
    } 
  
    // allocate a dynamic array large enough 
    // to accommodate runs of size run_size 
    int* arr = (int*)malloc(run_size * sizeof(int)); 
  
    bool more_input = true; 
    int next_output_file = 0; 
  
    int i; 
    while (more_input) 
    { 
        // write run_size elements into arr from input file 
        for (i = 0; i < run_size; i++) 
        { 
            if (fscanf(in, "%d ", &arr[i]) != 1) 
            { 
                more_input = false; 
                break; 
            } 
        } 
  
        // sort array using merge sort 
        mergeSort(arr, 0, i - 1); 
  
        // write the records to the appropriate scratch output file 
        // can't assume that the loop runs to run_size 
        // since the last run's length may be less than run_size 
        for (int j = 0; j < i; j++) 
            fprintf(out[next_output_file], "%d ", arr[j]); 
  
        next_output_file++; 
    } 
  
    // close input and output files 
    for (int i = 0; i < num_ways; i++) 
        fclose(out[i]); 
  
    fclose(in); 
} 
  
// For sorting data stored on disk 
void externalSort(char* input_file,  char *output_file, int num_ways, int run_size) { 
    // read the input file, create the initial runs
    // and assign the runs to the scratch output files 
    createInitialRuns(input_file, run_size, num_ways); 
  
    // Merge the runs using the K-way merging 
    mergeFiles(output_file, run_size, num_ways); 
} 
  
  
// Driver program to test above 
int main() 
{ 
    // No. of Partitions of input file. 
    int num_ways = 10; 
  
    // The size of each partition 
    int run_size = 1000; 
  
    char input_file[] = "input.txt"; 
    char output_file[] = "output.txt"; 
  
    FILE* in = openFile(input_file, "w"); 
  
    srand(time(NULL)); 
  
    // generate input 
    for (int i = 0; i < num_ways * run_size; i++) 
        fprintf(in, "%d ", rand()); 
  
    fclose(in); 
  
    externalSort(input_file, output_file, num_ways, run_size); 
  
    return 0; 
} 

/*
This code won’t work on online compiler as it requires file creation permissions. When run local machine, it produces sample input file “input.txt” with 10000 random numbers. It sorts the numbers and puts the sorted numbers in a file “output.txt”. It also generates files with names 1, 2, .. to store sorted runs
*/















#include <bits/stdc++.h>
using namespace std;

struct MinHeapNode
{
    // The element to be stored
    int element;
    // index of the array from which the element is taken
    int i;
};

// Comparison object to be used to order the heap
struct comp
{
    bool operator()(const MinHeapNode lhs, const MinHeapNode rhs) const
    {
        return lhs.element > rhs.element;
    }
};

FILE* openFile(char* fileName, char* mode)
{
    FILE* fp = fopen(fileName, mode);
    if (fp == NULL)
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    return fp;
}

// Merges k sorted files. Names of files are assumed to be 1, 2, ... k
void mergeFiles(char *output_file, int n, int k)
{
    FILE* in[k];
    for (int i = 0; i < k; i++)
    {
        char fileName[2];

        // convert i to string
        snprintf(fileName, sizeof(fileName), "%d", i);

        // Open output files in read mode.
        in[i] = openFile(fileName, "r");
    }

    // FINAL OUTPUT FILE
    FILE *out = openFile(output_file, "w");

    // Create a min heap with k heap nodes.  Every heap node has first
    // element of scratch output file
    MinHeapNode harr[k];
    priority_queue<MinHeapNode, std::vector<MinHeapNode>, comp> pq;

    int i;
    for (i = 0; i < k; i++)
    {
        // break if no output file is empty and
        // index i will be no. of input files
        if (fscanf(in[i], "%d ", &harr[i].element) != 1)
            break;

        // Index of scratch output file
        harr[i].i = i;
        pq.push(harr[i]);
    }

    int count = 0;

    // Now one by one get the minimum element from min heap and replace
    // it with next element. Run till all filled input files reach EOF
    while (count != i)
    {
        // Get the minimum element and store it in output file
        MinHeapNode root = pq.top();
        pq.pop();
        fprintf(out, "%d ", root.element);

        // Find the next element that should replace current root of heap.
        // The next element belongs to same input file as the current
        // minimum element.
        if (fscanf(in[root.i], "%d ", &root.element) != 1 )
        {
            root.element = INT_MAX;
            count++;
        }

        // Replace root with next element of input file
        pq.push(root);
    }

    // close input and output files
    for (int i = 0; i < k; i++)
        fclose(in[i]);

    fclose(out);
}

// Using a merge-sort algorithm, create the initial runs and divide them
// evenly among the output files
void createInitialRuns(char *input_file, int run_size, int num_ways)
{
    // For big input file
    FILE *in = openFile(input_file, "r");

    // output scratch files
    FILE* out[num_ways];
    char fileName[2];
    for (int i = 0; i < num_ways; i++)
    {
        // convert i to string
        snprintf(fileName, sizeof(fileName), "%d", i);

        // Open output files in write mode.
        out[i] = openFile(fileName, "w");
    }

    // allocate a dynamic array large enough to accommodate runs of
    // size run_size
    int* arr = (int*)malloc(run_size * sizeof(int));

    bool more_input = true;
    int next_output_file = 0;

    int i;
    while (more_input)
    {
        // write run_size elements into arr from input file
        for (i = 0; i < run_size; i++)
        {
            if (fscanf(in, "%d ", &arr[i]) != 1)
            {
                more_input = false;
                break;
            }
        }

        // sort array using merge sort
        sort(arr, arr + i);

        // write the records to the appropriate scratch output file
        // can't assume that the loop runs to run_size
        // since the last run's length may be less than run_size
        for (int j = 0; j < i; j++)
            fprintf(out[next_output_file], "%d ", arr[j]);

        next_output_file++;
    }

    // close input and output files
    for (int i = 0; i < num_ways; i++)
        fclose(out[i]);

    fclose(in);
}

/* Program to demonstrate External merge sort*/
int main()
{
    // No. of Partitions of input file
    int num_ways = 10;

    // The size of each partition
    int run_size = 1000;

    char input_file[] = "input.txt";
    char output_file[] = "output.txt";

    FILE* in = openFile(input_file, "w");

    srand(time(NULL));

    // generate input
    for (int i = 0; i < num_ways * run_size; i++)
        fprintf(in, "%d ", rand());

    fclose(in);

    // read the input file, create the initial runs,
    // and assign the runs to the scratch output files
    createInitialRuns(input_file, run_size, num_ways);

    // Merge the runs using the K-way merging
    mergeFiles(output_file, run_size, num_ways);

    return 0;
}