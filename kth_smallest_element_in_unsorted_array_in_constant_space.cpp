
#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)
#define rloop(i, end) for(int i=end; i>=0; i--)

// void kth_smallest_1(vector<int> &A, int B){
//     priority_queue<int, vector<int>, greater<int> > pq;
//     for(int i=0; i<A.size(); i++){
//         pq.push(A[i]);
//     }
//     for(int i=0; i<B-1; i++){
//         // cout<<pq.top()<<" ";
//         pq.pop();
//     }
//     // cout<<endl;
//     cout<<pq.top()<endl;
// }

void kth_smallest(vector<int> &A, int B){
	int n= A.size();
    int global_max = INT_MAX;
    int local_max = INT_MIN;
    int max_idx = -1;
	if(B>1){
		loop(i, 0, n){ 
		    if(A[i]>local_max){
		        local_max = A[i];
		        max_idx = i;
		    }
		}
	}
	global_max = min(global_max, local_max);
	cout<<local_max<<" "<<global_max<<" "<<max_idx<<endl;

    int loop_count = n-B;
    while(loop_count--){
        local_max = INT_MIN;
        loop(i, 0, n){
            if(A[i]<global_max && A[i]>local_max && i!=max_idx){
                local_max = A[i];
                max_idx = i;
            }
        }
        global_max = min(global_max, local_max);
        cout<<local_max<<" "<<global_max<<" "<<max_idx<<"----\n";
    }
    cout<<global_max<<endl;
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
	    int k;
	    cin>>k;
	    kth_smallest(vect, k);
	}
	return 0;
}

