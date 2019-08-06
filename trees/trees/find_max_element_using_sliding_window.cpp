
#include <bits/stdc++.h>
using namespace std;
#define loop(x,n) for(int x = 0; x < n; ++x)

void get_max_using_sliding_window(int arr[], int n, int k){
    deque<int> deq;
    deque<int>::iterator it;

    // fill first k element in dequeue as max element
    for(int i=0; i<k; i++){
        while(!deq.empty() && arr[deq.back()] <= arr[i]){
            deq.pop_back();
        }
        deq.push_back(i);
    }
    

    for(int i=k; i<n; i++){
        // cout<<"out: "<<arr[deq.front()]<<" ";
        cout<<arr[deq.front()]<<" ";


        // cout<<endl<<"==== ";
        // for (it = deq.begin(); it != deq.end(); ++it){ 
        //     cout << *it<< " "<< arr[*it] <<" "; 
        // }
        // cout<<" ===="<<endl;



        while(!deq.empty() && deq.front() <= i-k){
            // remove the element from deque, as it is not part of current sliding window
            deq.pop_front();
        }
        while(!deq.empty() && arr[deq.back()] <= arr[i]){
            // Add the element in dequeue, if it is greater than the back element
            deq.pop_back();
        }
        deq.push_back(i);
        // cout<<"out: "<<arr[deq.front()]<<" ";
    }
    cout<<arr[deq.front()]<<" ";
    cout<<endl<<"======= Done ========="<<endl;
}

int main()
{
    int test;
    cin >> test;

    while(test--){
        int n;
        cin>>n;

        int arr[n];
        loop(ii, n){
            cin>>arr[ii];
        }
        
        int k;
        cin>>k;

        get_max_using_sliding_window(arr, n, k);
        // cout<<endl<<"========="<<endl;
        // loop(ii, n){
        //     cout<<arr[ii]<<" ";
        // }
        // cout<<endl<<"========="<<endl;
    }
    return 0;
}


