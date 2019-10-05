
// new one
int Solution::largestRectangleArea(vector<int> &h) {
    int n = h.size(), max_area = 0;
    stack<int> s;
    for(int i=0; i<n; i++){
        if(s.empty() || h[s.top()] <= h[i]){
            s.push(i);
        }
        else{
            while(!s.empty() && h[s.top()] > h[i]){
                int top = s.top(); s.pop();
                if(s.empty()) max_area = max(max_area, i*h[top]);
                else max_area = max(max_area, (i-s.top()-1)*h[top]);
            }
            s.push(i);
        }
    }
    int i = h.size();
    while(!s.empty()){
        int top = s.top(); s.pop();
        if(s.empty()) max_area = max(max_area, i*h[top]);
        else max_area = max(max_area, (i-s.top()-1)*h[top]);
    }
    return max_area;
}


// old but gold
long largestRectangle(vector<int> h) {
    int n = h.size();
    stack<long> s;
    long maxArea = INT_MIN, curArea, idx;
    int i;
    for(i=0; i<n; i++){
        if(s.empty()) s.push(i);
        else if(h[i] >= h[s.top()]) s.push(i);
        else{
            while(!s.empty() && h[s.top()] > h[i]){
                idx = s.top(); s.pop();
                if(s.empty()) curArea = h[idx]*i;
                else curArea = h[idx]*(i-s.top()-1);
                maxArea = max(maxArea, curArea);
            }
            s.push(i);
        }
    }
    while(!s.empty()){
        idx = s.top(); s.pop();
        if(s.empty()) curArea = h[idx]*i;
        else curArea = h[idx]*(i-s.top()-1);
        maxArea = max(maxArea, curArea);
    }
    return maxArea;
}



#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)

void largestRectangle(vector<int> &A){
	stack<int> stacking;
	int n = A.size();
	int stack_top;
	int max_area = INT_MIN;
	int area;
	int i = 0;
	while(i<n){
		if(stacking.empty()){
			stacking.push(i);
		}
		else if(A[i]>=A[stacking.top()]){
			stacking.push(i);
		}
		else{
			while(!stacking.empty() && A[i]<A[stacking.top()]){
				stack_top = stacking.top();
				stacking.pop();
				if(stacking.empty()){
					area = A[stack_top]*i;
				}
				else{
					area = A[stack_top]*(i-stacking.top()-1);
				}
				cout<<area<<"---\n";
				max_area = max(max_area, area);
			}
			stacking.push(i);
		}
		i++;
	}
	cout<<endl;
	while(!stacking.empty()){
		// cout<<A[stacking.top()]<<" ";
		// stacking.pop();

		stack_top = stacking.top();
		stacking.pop();
		if(stacking.empty()){
			area = A[stack_top]*i;
		}
		else{
			area = A[stack_top]*(i-stacking.top()-1);
		}
		cout<<area<<"----\n";
		max_area = max(max_area, area);
	}

	cout<<endl<<max_area<<endl;
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
	    largestRectangle(vect);
	}
	return 0;
}


