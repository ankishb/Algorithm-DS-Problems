#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)

// class custom_pq{
// public:
//     int a, d;
//     custom_pq(int arr, int dep) : a(arr), d(dep){}
// };

// bool operator<(const custom_pq &p1, const custom_pq &p2){
//     return (p1.d > p2.d);
// }

struct custom_pq{
    int a, d;
    custom_pq(int arr, int dep) : a(arr), d(dep){}
};

struct custom_sort{
    bool operator()(const custom_pq &p1, const custom_pq &p2){
        return (p1.d > p2.d);
    }
};

bool sort_by_sec(const pair<int,int> &p1, const pair<int,int> &p2){
    return (p1.second < p2.second) || 
    (p1.second == p2.second && p1.first < p2.first);
}

void solve(){
    int n; cin>>n;
    vector<pair<int,int>> A(n);
    // for(auto p : A){
    //     cout<<p.first<<" "<<p.second<<endl;
    // }
    string arr, dep;
    int arr1, dep1;
    for(int i=0; i<n; i++){
        cin>>arr;
        arr1 = stoi(arr);
        A[i].first = arr1;
    }
    for(int i=0; i<n; i++){
        cin>>dep;
        dep1 = stoi(dep);
        A[i].second = dep1;
    }
    // for(auto p : A){
    //     cout<<p.first<<" "<<p.second<<endl;
    // }
    
    sort(A.begin(), A.end(), sort_by_sec);
    priority_queue<custom_pq, vector<custom_pq>, custom_sort> pq;
    // priority_queue<custom_pq> pq;
    
    // for(auto p : A){
    //     pq.push(custom_pq(p.first, p.second));
    //     cout<<p.first<<" "<<p.second<<endl;
    // }
    
    for(auto p : A){
        if(pq.empty()) pq.push(custom_pq(p.first, p.second));
        else if(pq.top().d < p.first){
            // Can run the current train on same platform
            custom_pq top = pq.top();
            pq.pop();
            top.d = p.second;
            pq.push(top);
        }
        else{
            pq.push(custom_pq(p.first, p.second));
        }
        // cout<<pq.top().a<<" "<<pq.top().d<<endl;
    }
    cout<<pq.size()<<endl;
    

}

int main()
 {
	int test;
	cin>>test;
	while(test--){
	    solve();
	}
	return 0;
}