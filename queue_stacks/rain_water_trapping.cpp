
// leetcode
class Solution {
public:
    int trap(vector<int>& A) {
        return left_right_w_memory(A);
        // return left_right_wo_memory(A);
        // return stack_two_pass(A);
        // return stack_one_pass(A);
    }
    // using stacks
    int stack_two_pass(vector<int>& A) {
        stack<int> s;
        int max_el, traps = 0, n = A.size();
        if(n <= 1) return 0;
        max_el = A[0];
        s.push(A[0]);
        for(int i=1; i<n; i++){
            if(A[i] >= max_el){
                // we need to fill water in the collected elevations
                while(!s.empty()){
                    traps += (max_el - s.top());
                    s.pop();
                }
                max_el = A[i];
            }
            s.push(A[i]);
        }
        if(s.size() <= 1) return traps;
        // else we need to reverse the process, ans proceed till stored max_el
        while(!s.empty()) s.pop();
        int danger = max_el;
        max_el = A[n-1];
        for(int i=n-2; i>=0; i--){
            if(A[i] >= max_el){
                // we need to fill water in the collected elevations
                while(!s.empty()){
                    traps += (max_el - s.top());
                    s.pop();
                }
                max_el = A[i];
            }
            if(A[i] == danger) break;
            s.push(A[i]);
        }
        return traps;
    }
    // using simple logic of left and right maximum
    int left_right_w_memory(vector<int>& A) {
        int trap_water = 0;
        int n = A.size();
        if(n <= 1) return 0;
        vector<int> max_l(A);
        vector<int> max_r(A);
        for(int i=1; i<n; i++){
            max_l[i] = max(max_l[i-1], A[i]);
        }
        for(int i=n-2; i>=0; i--){
            max_r[i] = max(max_r[i+1], A[i]);
        }
        // for(auto a : max_l) cout<<a<<" "; cout<<endl;
        // for(auto a : max_r) cout<<a<<" "; cout<<endl;
        
        for(int i=0; i<n; i++){
            trap_water += (min(max_l[i], max_r[i]) - A[i]);
        }
        return trap_water;
    }
    int left_right_wo_memory(vector<int>& A) {
        int n = A.size();
        int left = 0, right = n-1;
        int maxLeft = 0, maxRight = 0;
        int sum = 0;
        
        while(left <= right) {
            if(A[left] <= A[right]) {
                if(A[left] >= maxLeft) {
                    maxLeft = A[left];
                } 
                else {
                    sum += maxLeft - A[left];
                }
                left++;
            } 
            else {
                if(A[right] >= maxRight) {
                    maxRight = A[right];
                } 
                else {
                    sum += maxRight - A[right];
                }
                right--;
            }
        }
        return sum;
    }
    int stack_one_pass(vector<int> height) {
        int n = height.size();
        if (n < 2) return 0;
        
        stack<int> s ;
        int water = 0, i = 0;
        while (i < n) {
            if (s.empty() || height[i] <= height[s.top()]) {
                s.push(i++);
            } else {
                int pre = s.pop();
                if (!s.empty()) {
                    // find the smaller height between the two sides
                    int minHeight = min(height[s.top()], height[i]);
                    // calculate the area
                    water += (minHeight - height[pre]) * (i - s.top() - 1);
                }
            }
        }
        return water;
    }
};




// interview-bit
#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)

void trap_water(vector<int> &A){
	int left[A.size()] = {0};
	int right[A.size()] = {0};

	left[0] = A[0];
	for(int i=1; i<A.size(); i++){
		left[i] = max(left[i-1], A[i]);
	}

	
	right[A.size()-1] = A[A.size()-1];
	for(int i=A.size()-2; i>=0; i--){
		right[i] = max(right[i+1], A[i]);
	}

	// cout<<"\n ---- left -----\n";
	// for(int i=0; i<A.size(); i++){
	// 	cout<<left[i]<<" ";	
	// }

	// cout<<"\n ---- right -----\n";
	// for(int i=0; i<A.size(); i++){
	// 	cout<<right[i]<<" ";
	// }
	// cout<<endl;


	int ans = 0;
	for(int i=0; i<A.size(); i++){
		ans += min(left[i], right[i]) - A[i];
	}

	cout<<ans<<endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		int el;
		vector<int> vect;
		loop(i, 0, n){
			cin>>el;
			vect.push_back(el);
		}
		trap_water(vect);
	}
	return 0;
}




// C++ program to find maximum amount of water that can 
// be trapped within given set of bars. 
// Space Complexity : O(1) 

#include<iostream> 
using namespace std; 

int findWater(int arr[], int n) 
{ 
	// initialize output 
	int result = 0; 
	
	// maximum element on left and right 
	int left_max = 0, right_max = 0; 
	
	// indices to traverse the array 
	int lo = 0, hi = n-1; 
	
	while(lo <= hi) 
	{ 
		if(arr[lo] < arr[hi]) 
		{ 
			if(arr[lo] > left_max) 
			// update max in left 
			left_max = arr[lo]; 
			else
			// water on curr element = max - curr 
			result += left_max - arr[lo]; 
			lo++; 
		} 
		else
		{ 
			if(arr[hi] > right_max) 
			// update right maximum 
			right_max = arr[hi]; 
			else
			result += right_max - arr[hi]; 
			hi--; 
		} 
	} 
	
	return result; 
} 

int main() 
{ 
	int arr[] = {0, 1, 2, 1, 3, 1}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout << "Maximum water that can be accumulated is "
		<< findWater(arr, n); 
} 
