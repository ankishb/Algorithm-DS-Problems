
// newest (using deque)
vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size();
    vector<int> ans(n ,0);
    deque<int> dq;
    for(int i=0; i<n; i++){
        while(!dq.empty() && dq.back() >= A[i]){
            dq.pop_back();
        }
        ans[i] = (dq.empty()) ? -1 : dq.back();
        dq.push_back(A[i]);
    }
    return ans;
}



// new try
/*
As we can see, if element is > than top of stack, we fill it
otherwise, we remove all the previous element(which are > than current) in stack,
*/
vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size();
    if(n == 0) return {};
    stack<int> s;
    s.push(A[0]);
    vector<int> ans(n, -1);
    for(int i=1; i<n; i++){
        while(!s.empty() && s.top() >= A[i]){
            s.pop();
        }
        if(s.empty()) ans[i] = -1;
        else ans[i] = s.top();
        
        s.push(A[i]);
    }
    return ans;
}


// old one
#include <bits/stdc++.h>
using namespace std;

void prevSmaller(vector<int> &A){
	int lower_b, min;
	vector<int> ans;
	ans.push_back(-1);
	for(int i=1; i<A.size(); i++){
		int j = i-1;
		min = A[i];
		while(j>=0){
			if(A[j]<A[i]){
				min = A[j];
				break;
			}
			else{
				j--;
			}
		}
		min = (min<A[i])?min:-1;
		ans.push_back(min);
	}

	cout<<"\n ---- vector ---- \n";
	for(int i=0; i<ans.size(); i++){
		cout<<ans[i]<<" ";
	}
	cout<<"\n ---- vector ---- \n";
}

void optimal(vector<int> &A){
	vector<int> ans;
	stack<int> stacking;
	ans.push_back(-1);
	stacking.push(A[0]);
	for(int i=1; i<A.size(); i++){
		while(!stacking.empty() && A[i]<stacking.top()){
			stacking.pop();
		}
		if(stacking.empty()){
			ans.push_back(-1);
		}
		else{
			ans.push_back(stacking.top());
		}
		stacking.push(A[i]);
	}

	cout<<"\n ---- vector ---- \n";
	for(int i=0; i<ans.size(); i++){
		cout<<ans[i]<<" ";
	}
	cout<<"\n ---- vector ---- \n";
}


int main()
{
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<int> vect;
		int el;
		for(int i=0; i<n; i++){
			cin>>el;
			vect.push_back(el);
		}
		
		// prevSmaller(vect);
		optimal(vect);
	}
	return 0;
}