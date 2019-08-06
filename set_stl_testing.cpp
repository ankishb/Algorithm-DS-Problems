
#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)

void solve(){
    int n;
    cin>>n;
    int arr[n];
    loop(i, 0, n){
        cin>>arr[i];
    }
    set<int> inorder(arr, arr+n);
    set<int>::iterator it;
    int i=0;
    bool bool_flag = false;
    if(inorder.size() != n){
        cout<<"0\n";
        bool_flag = true;
    }
    for(it=inorder.begin(); it!=inorder.end()&&(bool_flag==false); ++it){
        if(*it != arr[i]){
            cout<<"0\n";
            bool_flag = true;
            break;
        }
        i++;
    }
    if (!bool_flag){
    cout<<"1\n";
    }
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