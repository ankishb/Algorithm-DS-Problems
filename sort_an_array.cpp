https://leetcode.com/problems/sort-an-array/

class Solution {
public:
    void bubbleSort(vector<int> &A){
        int n = A.size();
        // optimization
        bool swapFlag = false;
        for(int i=0; i<n; i++){
            swapFlag = false;
            for(int j=1; j<n-i; j++){
                if(A[j] < A[j-1]){
                    swap(A[j], A[j-1]);
                    swapFlag = true;
                }
            }
            if(swapFlag == false) break;
        }
    }

    void mergeSortUtil(vector<int> &A, int l, int m, int r){
        int n1 = m-l+1;
        int n2 = r-m;
        cout<< n1 <<" "<< n2 << endl;
        vector<int> arr1(n1), arr2(n2);
        for(int i=l; i<=m; i++){
            arr1[i-l] = A[i];
            cout<< A[i] <<" ";
        }
        for(int i=m+1; i<=r; i++){
            arr1[i-m-1] = A[i];
            cout<< A[i] <<" ";
        }
        
        int i1=0, i2=0;
        while(i1 < n1 && i2 < n2){
            if(arr1[i1] <= arr2[i2]){
                A[l] = arr1[i1];
                i1++; l++;
            }
            else{
                A[l] = arr2[i2];
                i2++; l++;
            }
        }
        while(i1 < n1){
            A[l] = arr1[i1];
            i1++; l++;
        }
        while(i2 < n2){
            A[l] = arr2[i2];
            i2++; l++;
        } 
        for(int i=l-n1-n2; i<=r; i++) cout<<A[i]<<" ";
        cout<<endl;
    }

    void mergeSort(vector<int> &A, int l, int r){
        if(l >= r) return;
        int mid = l + (r - l)/2;
        mergeSort(A, l, mid);
        mergeSort(A, mid+1, r);
    
        mergeSortUtil(A, l, mid, r);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        // bubbleSort(nums);
        mergeSort(nums, 0, nums.size()-1);
        // sort(nums.begin(), nums.end());
        return nums;
    }
};