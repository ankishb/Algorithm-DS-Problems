// Time: O(nlogn), Space O(1)
class Solution {
public:
    int maximumProduct(vector<int>& A) {
        int n = A.size();
        sort(A.begin(), A.end());
        // for(auto itr:A) cout<<itr<<" ";
        return max({A[0]*A[1]*A[2], A[0]*A[1]*A[n-1], A[n-3]*A[n-2]*A[n-1]});
    }
};




// Time: O(n), Space O(n)
/*
Approach:
1. Collect left_max and left_min on the left of each element.
2. Collect right_max and right_min on the right of each element.
3. Scan the array and track ans as follows:
ans = max({left-max*right-max*el, left-min*right-min*el, ...})
*/


class Solution {
public:
    int maximumProduct(vector<int>& A) {
        int n = A.size();
        if(n == 3) return A[0]*A[1]*A[2];
    	vector<int> left_max(n, INT_MIN);
    	vector<int> left_min(n, INT_MAX);
    	vector<int> right_max(n, INT_MIN);
    	vector<int> right_min(n, INT_MAX);

    	left_min[0] = -1; right_max[n-1] = -1;
    	left_max[0] = -1; right_min[n-1] = -1;
    	for(int i=1; i<n; i++){
    		left_max[i] = max(left_max[i-1], A[i-1]);
    		left_min[i] = min(left_min[i-1], A[i-1]);
    	}

    	for(int i=n-2; i>=0; i--){
    		right_max[i] = max(right_max[i+1], A[i+1]);
    		right_min[i] = min(right_min[i+1], A[i+1]);
    	}
        
        for(int i=0; i<n; i++){
            cout<<left_min[i]<<" "<<left_max[i]<<" "<<A[i]<<" "<<right_min[i]<<" "<<right_max[i]<<endl;
        }
        
        int ans = INT_MIN;
    	for(int i=1; i<n-1; i++){
    		if(A[i] > 0){
    			ans = max({ans, A[i]*left_min[i]*right_min[i], A[i]*left_max[i]*right_max[i]});
    		}
    		else if(A[i] == 0){
    			ans = max(ans, 0);
    		}
    		else{
    			ans = max({ans, A[i]*left_min[i]*right_max[i], A[i]*left_max[i]*right_min[i]});
    		}
    	}
    	return ans;
    }
};




// Time: O(n), Space O(1)
/*
Approach:
Scan the array and collect first max, second max and third max
And also collect first min, second min and third min
*/

// A O(n) C++ program to find maximum product pair in 
// an array. 
#include <bits/stdc++.h> 
using namespace std; 
  
/* Function to find a maximum product of a triplet 
   in array of integers of size n */
int maxProduct(int arr[], int n) 
{ 
    // if size is less than 3, no triplet exists 
    if (n < 3) 
        return -1; 
  
    // Initialize Maximum, second maximum and third 
    // maximum element 
    int maxA = INT_MIN, maxB = INT_MIN, maxC = INT_MIN; 
  
    // Initialize Minimum and second mimimum element 
    int minA = INT_MAX, minB = INT_MAX; 
  
    for (int i = 0; i < n; i++) 
    { 
        // Update Maximum, second maximum and third 
        // maximum element 
        if (arr[i] > maxA) 
        { 
            maxC = maxB; 
            maxB = maxA; 
            maxA = arr[i]; 
        } 
  
        // Update second maximum and third maximum element 
        else if (arr[i] > maxB) 
        { 
            maxC = maxB; 
            maxB = arr[i]; 
        } 
  
        // Update third maximum element 
        else if (arr[i] > maxC) 
            maxC = arr[i]; 
  
        // Update Minimum and second mimimum element 
        if (arr[i] < minA) 
        { 
            minB = minA; 
            minA = arr[i]; 
        } 
  
        // Update second mimimum element 
        else if(arr[i] < minB) 
            minB = arr[i]; 
    } 
  
    return max(minA * minB * maxA, 
               maxA * maxB * maxC); 
} 
  
// Driver program to test above function 
int main() 
{ 
    int arr[] = { 1, -4, 3, -6, 7, 0 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    int max = maxProduct(arr, n); 
  
    if (max == -1) 
        cout << "No Triplet Exists"; 
    else
        cout << "Maximum product is " << max; 
  
    return 0; 
} 
