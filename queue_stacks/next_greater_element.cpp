
// newest one (leetcode)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        stack<int> s;
        for(auto d : nums2){
            while(!s.empty() && s.top() < d){
                map[s.top()] = d;
                s.pop();
            }
            s.push(d);
        }
        
        vector<int> ans;
        for(auto d : nums1){
            if(map.find(d) == map.end()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(map[d]);
            }
        }
        return ans;
    }
};

// newest one (interviewBit)
#define ll long long int 
void next_greater(vector<ll> A){
    int n = A.size();
    stack<ll> s;
    vector<ll> ans(n, -1);
    for(int i=0; i<n; i++){
        while(!s.empty() && A[i] > A[s.top()]){
            ans[s.top()] = A[i];
            s.pop();
        }
        s.push(i);
    }
    for(auto a : ans){
        cout<<a<<" ";
    }cout<<endl;
}


// old one
#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)
#define rloop(i, end) for(int i=end; i>=0; i--)


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
