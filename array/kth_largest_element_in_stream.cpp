
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vii vector<vector<int>>
#define f first
#define s second
#define ll long long int 
#define vi vector<int>

/*
We need kth largest element from the current element, including current
1. Till index < k, we cann't get any value
2. At index k, we have k element in our heap, we extract top
3. At index > k, 
    If current elemnt is smaller than current, we don't need current element
    else we remove kth element and add current element.
*/
// creat a signature function here
void kth_largest_el(vi A, int k){
    int n = A.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i=0; i<n; i++){
        if(i <= k-1){
            pq.push(A[i]);
            if(i < k-1) cout<<-1<<" ";
            else cout<<pq.top()<<" ";
        }
        else{
            if(A[i] > pq.top()){
                pq.pop();
                pq.push(A[i]);
            }
            cout<<pq.top()<<" ";
        }
    }
    cout<<endl;
}

int main()
 {
	int test;
	cin>>test;
	while(test--){
	    // input and call signature function
	    int k, n;
	    cin>>k>>n;
	    vi A(n);
	    for(int i=0; i<n; i++){
	        cin>>A[i];
	    }
	    kth_largest_el(A, k);
	}
	return 0;
}