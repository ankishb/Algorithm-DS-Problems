
vector<int> Solution::slidingMaximum(const vector<int> &A, int k) {
    int n = A.size();
    vector<int> ans;
    if(n == 0) return ans;

    deque<int> dq;
    for(int i=0; i<k; i++){
        while(!dq.empty() && A[dq.back()] <= A[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(A[dq.front()]);
    
    for(int i=k; i<n; i++){
        if(!dq.empty() && i - dq.front() >= k) dq.pop_front();
        while(!dq.empty() && A[dq.back()] <= A[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        
        ans.push_back(A[dq.front()]);
    }
    return ans;
}





vector<int> Solution::slidingMaximum(const vector<int> &vect, int qi) {
// int find_min_max(vector<int> vect, int qi){
    queue<int> q;
    q.push(0);
    for(int i=1; i<qi; i++){
        if(vect[i] > vect[q.back()]){
            q.push(i);
        }
    }
    vector<int> ans;
    int min_ans = INT_MAX;
    for(int i=qi; i<vect.size(); i++){
        // min_ans = min(min_ans, vect[q.back()]);
        ans.push_back(vect[q.back()]);
        // check if the front element still exist in current query.
        if(i-q.front() >= qi){
            q.pop();
        }
        // check if current element should be inserted in queue
        if(q.empty()){
            q.push(i);
        }
        else if(vect[i] > vect[q.back()]){
            q.push(i);
        }
    }
    ans.push_back(vect[q.back()]);
    // min_ans = min(min_ans, vect[q.back()]);
    return ans;
}


#include <bits/stdc++.h>
using namespace std;

void sliding_window_max(vector<int> &A, int B){
	deque<int> dq;
	vector<int> ans;
	for(int i=0; i<B; i++){
		while(!dq.empty() && A[dq.back()] <= A[i]){
			dq.pop_back();
		}
		dq.push_back(i);
	}

	for(int i=B; i<A.size(); i++){
		ans.push_back(A[dq.front()]);
		while(!dq.empty() && dq.front()<=i-B){
			dq.pop_front();
		}
		while(!dq.empty() && A[dq.back()]<=A[i]){
			dq.pop_back();
		}
		dq.push_back(i);
	}
	ans.push_back(A[dq.front()]);

	
	cout<<"\n ---- sliding window max ----- \n";
	for(int i=0; i<ans.size(); i++){
		cout<<ans[i]<<" ";
	}
	cout<<"\n ---- sliding window max ----- \n";
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
		for(int i=0; i<n; i++){
			cin>>el;
			vect.push_back(el);
		}
		int k;
		cin>>k;
		sliding_window_max(vect, k);
	}
	return 0;
}
