#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0; i<n; i++){
        cin>>A[i];
    }
    int nq, key, idx;
    cin>>nq;
    for(int i=0; i<nq; i++){
        cin>>key;
        int low = 0, high = n-1, mid;
        while(low <= high){
            mid = low + (high - low)/2;
            if(A[mid] >= key){
                idx = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        if(A[idx] == key) cout<<"Yes ";
        else cout<<"No ";
        cout<<idx+1<<endl;
    }
    return 0;
}
