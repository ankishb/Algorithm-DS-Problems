#include <bits/stdc++.h>
using namespace std;

/*
1. start with bob
2. whoever will reach at 0th index, that is winner
*/
// player 0: bob
// player 1: andy
string winner(vector<int> arr, vector<pair<int,int>> A, int j, bool player){
    if(A[j].second == 0) {
        return (player) ? "ANDY" : "BOB";
    }
    player = 1 - player;
    int idx = j;
    while(idx < arr.size() && A[idx].second >= A[j].second){
        idx++;
    }
    return winner(arr, A, idx, player);
}

bool customSort(const pair<int,int> &p1, const pair<int, int> &p2){
    return (p1.first > p2.first);
}


int main()
{
    int test; cin>>test;
    while(test--){
        int n; cin>>n;
        int el;
        vector<int> arr;
        vector<pair<int,int>> A;
        bool incOrder = true;
        for(int i=0; i<n; i++){
            cin>>el;
            if(i>0 && el<arr[i-1]) incOrder = false;
            arr.push_back(el);
            A.push_back(make_pair(el, i));
        }
        if(incOrder == true){
            if(n%2 == 0) cout<<"ANDY\n";
            else cout<<"BOB\n";
        }
        else{
            sort(A.begin(), A.end(), customSort);
            // for(auto itr : A) cout<<itr.first<<" ";
            // cout<<endl;
            // for(auto itr : A) cout<<itr.second<<" ";
            // cout<<endl;
            cout<<winner(arr, A, 0, 0)<<endl;
        }
    }
    return 0;
}
