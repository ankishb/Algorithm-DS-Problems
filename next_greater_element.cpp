

#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)
#define rloop(i, end) for(int i=end; i>=0; i--)

// void next_greater(vector<int> &A){
// 	cout<<"\n ---- next greater element in vector ----\n";
// 	for(int i=0; i<A.size(); i++){
// 		cout<<A[i]<<" ";
// 	}
// 	cout<<endl;

// 	vector<int> ans;
// 	stack<int> s;
// 	int n = A.size();
// 	if(n>0){
// 		s.push(A[0]);
// 	}
// 	int j=1;
// 	for(int i=0; i<n; i++){
		
// 		while(s.top()<=A[i] && j<n){
// 			s.push(A[j]);
// 			j++;
// 		}
// 		if(s.top() > A[i]){
// 			ans.push_back(s.top());
// 		}
// 		else{
// 			ans.push_back(-1);
// 		}
// 	}

// 	cout<<"\n ---- next greater element in vector ----\n";
// 	for(int i=0; i<ans.size(); i++){
// 		cout<<ans[i]<<" ";
// 	}
// 	cout<<endl;
// }

void next_greater(vector<int> &A){
	int n = A.size();
	stack<int> s;
	vector<int> ans(n, -1);
	int next;
	s.push(0);
	for(int i=1; i<n; i++){
		next = i;
		while(!s.empty() && A[next]>A[s.top()]){
			ans[s.top()] = A[i];
			// next = s.top();
			s.pop();
		}
		s.push(next);
	}

	cout<<"\n ---- next greater element in vector ----\n";
	for(int i=0; i<ans.size(); i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
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
	    next_greater(vect);
	}
	return 0;
}






// wrong logic

// void print_stack(stack<int> s){
//     vector<int> v;
//     while(!s.empty()){
//         v.push_back(s.top());
//         s.pop();
//     }
//     for(int i=v.size()-1; i>=0; i--){
//         cout<<v[i]<<" ";
//     }
//     cout<<endl;
// }
// vector<int> Solution::nextGreater(vector<int> &A) {
// // void next_greater(vector<int> &A){
//     // cout<<"\n ---- next greater element in vector ----\n";
//     // for(int i=0; i<A.size(); i++){
//     //     cout<<A[i]<<" ";
//     // }
//     // cout<<endl;

//     vector<int> ans;
//     stack<int> s;
//     int n = A.size();
//     if(n>0) s.push(A[0]);
    
//     int j=1;
//     for(int i=0; i<n; i++){
//         while(s.top()<=A[i] && j<n){
//             s.push(A[j]);
//             j++;
//         }
//         print_stack(s);
//         // (s.top() > A[i]) ? ans.push_back(s.top()) : ans.push_back(-1);
//         if(s.top() > A[i]){
//             ans.push_back(s.top());
//         }
//         else{
//             ans.push_back(-1);
//         }
//     }

//     return ans;
// }
