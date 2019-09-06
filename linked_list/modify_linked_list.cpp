
#include <bits/stdc++.h>
using namespace std;

void jump_and_move(vector<int> A){
    int n = A.size();
    vector<int> ans;
    for(int i=0; i<n-2; i++){
        if(A[i]==A[i+1] && A[i+2]==100){
            A[i] = 100;
            A[i+1] = A[i] + floor(A[i]*1.1);
        }
    }
    int count_100 = 0;
    if(A[0] == 100) count_100++;
    else cout<<A[0];
    
    for(int i=0; i<n; i++){
        if(A[i] == 100) count_100++;
        else{
            cout<<"->"<<A[i];
            // ans.push_back(A[i]);
        }
    }
    for(int i=0; i<count_100; i++){
        cout<<"->"<<100;
        // ans.push_back(100);
    }
    cout<<endl;
}

int main()
{
    int test;
    cin>>test;
    while(test--){
        int n; cin>>n;
        vector<int> A(n, 0);
        for(int i=0; i<n; i++){
            cin>>A[i];
        }
        jump_and_move(A);
    }
    return 0;
}