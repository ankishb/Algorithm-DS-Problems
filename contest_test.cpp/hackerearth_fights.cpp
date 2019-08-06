#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--){
        int n; cin>>n;
        long long int arr[n];
        long long int ans = 0;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            ans += arr[i];
        }
        cout<<ans<<"\n";
    }
    return 0;
}










#include <bits/stdc++.h>
using namespace std;

bool custom_sort(const pair<int, int> &p1, const pair<int, int> &p2){
    return (p1.second > p2.second);
}

int main()
{
    int test;
    cin>>test;
    while(test--){
        int n; cin>>n;
        int k; cin>>k;
        
        vector<pair<int, int> > vect(n);
        int a,b;
        for(int i=0; i<n; i++){
            cin>>a;
            vect[i].first = a;
        }
        for(int i=0; i<n; i++){
            cin>>a;
            vect[i].second = a;
        }
        sort(vect.begin(), vect.end(), custom_sort);
        
        vector<int> max_sum, idx;
        for(int i=0; i<n; i++){
            max_sum.push_back(vect[i].first);
            idx.push_back(i);
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(max_sum[i]<max_sum[i]+vect[j].first
                && max_sum[i]+vect[j].first <= k){
                    max_sum[i] = max_sum[j]+vect[i].first;
                    idx[i] = j;
                }
            }
        }
        int max_val=INT_MIN, max_idx=0;
        for(int i=0; i<n; i++){
            if(max_sum[i] > max_val){
                max_val = max_sum[i];
                max_idx = i;
            }
        }
        for(auto itr : max_sum) cout<<itr<<" ";
        cout<<endl;
        for(int i=0; i<n; i++){
            cout<<idx[i]<<" ";
        }
        cout<<endl;
        for(int i=0; i<n; i++){
            cout<< vect[i].second << " ";
        }
        
        cout<<endl;

        int profit = 0;
        while(max_idx != idx[max_idx]){
            profit += vect[max_idx].second;
            max_idx = idx[max_idx];
        }
        profit += vect[max_idx].second;
        cout<<profit<<endl;

    }
    return 0;
}
