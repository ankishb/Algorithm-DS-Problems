/*
Approach:
1. we check if value at current index is same as index+1, then we increment index
2. else swap the element of current index with the element at index of that value-1
3. repeat current index reach at end of array.
*/
int minimumSwaps(vector<int> arr) {
    int n = arr.size();
    int idx = 0, count = 0;
    while(idx != n-1){
        if(arr[idx]-1 == idx) idx++;
        else{
            swap(arr[idx], arr[arr[idx]-1]);
            count++;
        }
    }
    return count;
}