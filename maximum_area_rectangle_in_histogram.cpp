#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)

void brute_force(){
	int n;
	cin>>n;
	// vector<int> vect;
	int vect[n];
	int el;
	loop(i, 0, n){
		cin>>vect[i];
		// cin>>el;
		// vect.push_back(el);
	}

	int* it, max_area = INT_MIN;
	loop(i, 0, n){
		loop(j, i, n){
			// loop(k, i, j+1){
			// 	cout<<vect[k]<<" ";
			// }
			// cout<<endl<<"==========="<<endl;
			it = min_element(vect+i, vect+j+1);
			// cout<<i<<" "<<j<<" "<<*it *(j-i+1)<<endl;
			max_area = max(max_area, *it *(j-i+1));
		}
	}

	cout<<max_area<<endl;
}

// 1
// 7
// 6 2 5 4 5 1 6


void optimal(){
	int n;
	cin>>n;
	int arr[n];
	loop(i, 0, n){
		cin>>arr[i];
	}

	stack<int> stacking;
	int cur_idx, stack_top, area, max_area=0;
	int i=0;
	while(i<n){
	// for(int i=0; i<n+1; i++){
		if(stacking.empty() || arr[i] >= arr[stacking.top()]){
			cout<<arr[i]<<" ";
			stacking.push(i);
			i++;
		}
		else if(arr[i] < arr[stacking.top()]){
			// while(arr[i] <= arr[stacking.top()] && !stacking.empty()){
				stack_top = stacking.top();
				stacking.pop();
				// cout<<"--popping--"<<stack_top<<" "<<i<<" ";
				cout<<"--popping--"<<arr[stack_top]<<" ";
				if(stacking.empty()){
					area = arr[stack_top]*(i);// as i is already increased
				}
				else{
					area = arr[stack_top]*(i-stack_top-1);
				}
				max_area = max(max_area, area);
				cout<<endl<<area<<" -- "<<max_area<<endl;
		}
	}
	while(!stacking.empty()){
		stack_top = stacking.top();
		stacking.pop();
		// cout<<"--popping--"<<stack_top<<" "<<i<<" ";
		cout<<"--popping--"<<arr[stack_top]<<" ";
		if(stacking.empty()){
			area = arr[stack_top]*(i);// as i is already increased
		}
		else{
			area = arr[stack_top]*(i-stack_top-1);
		}
		max_area = max(max_area, area);
		cout<<endl<<area<<" -- "<<max_area<<endl;
	}

	cout<<max_area<<endl;
}


int main()
 {
	int test;
	cin>>test;
	while(test--){
	    // brute_force();
	    optimal();
	}
	return 0;
}









// // C++ program to find maximum rectangular area in 
// // linear time 
// #include<iostream> 
// #include<stack> 
// using namespace std; 

// // The main function to find the maximum rectangular 
// // area under given histogram with n bars 
// int getMaxArea(int hist[], int n) 
// { 
// 	// Create an empty stack. The stack holds indexes 
// 	// of hist[] array. The bars stored in stack are 
// 	// always in increasing order of their heights. 
// 	stack<int> s; 

// 	int max_area = 0; // Initalize max area 
// 	int tp; // To store top of stack 
// 	int area_with_top; // To store area with top bar 
// 					// as the smallest bar 

// 	// Run through all bars of given histogram 
// 	int i = 0; 
// 	while (i < n+1) 
// 	{ 
// 		// If this bar is higher than the bar on top 
// 		// stack, push it to stack 
// 		if (s.empty() || hist[s.top()] <= hist[i]) 
// 			s.push(i++); 

// 		// If this bar is lower than top of stack, 
// 		// then calculate area of rectangle with stack 
// 		// top as the smallest (or minimum height) bar. 
// 		// 'i' is 'right index' for the top and element 
// 		// before top in stack is 'left index' 
// 		else if((hist[s.top()] > hist[i]) || i == n)
// 		{ 
// 			tp = s.top(); // store the top index 
// 			s.pop(); // pop the top 

// 			// Calculate the area with hist[tp] stack 
// 			// as smallest bar 
// 			area_with_top = hist[tp] * (s.empty() ? i : 
// 								i - s.top() - 1); 

// 			// update max area, if needed 
// 			if (max_area < area_with_top) 
// 				max_area = area_with_top; 
// 		} 
// 	} 

// 	// Now pop the remaining bars from stack and calculate 
// 	// area with every popped bar as the smallest bar 
// 	while (s.empty() == false) 
// 	{ 
// 		tp = s.top(); 
// 		s.pop(); 
// 		area_with_top = hist[tp] * (s.empty() ? i : 
// 								i - s.top() - 1); 

// 		if (max_area < area_with_top) 
// 			max_area = area_with_top; 
// 	} 

// 	return max_area; 
// } 

// // Driver program to test above function 
// int main() 
// { 
// 	int hist[] = {6, 2, 5, 4, 5, 1, 6}; 
// 	int n = sizeof(hist)/sizeof(hist[0]); 
// 	cout << "Maximum area is " << getMaxArea(hist, n); 
// 	return 0; 
// } 