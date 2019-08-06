#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

bool minHeap_(const int &a, const int &b){
    return a>b;
}

int main() {
    priority_queue<int, vector<int>, greater<int> > pq;
    vector<int> min_heap;
    int q;
    cin>>q;
    cin.ignore(1);
    while(q--){
        
        string s;
        getline(cin, s);
        // cout<<s<<endl;
        if(s.length()==3){
            int el = (int)(s[2] - '0');
            if(s[0] == '1'){
                // pq.push(el);
                min_heap.push_back(el);
                make_heap(min_heap.begin(), min_heap.end(), minHeap_);
                // add_operation(pq, s[2]);
            }
            else{
                auto itr = find(min_heap.begin(), min_heap.end(), el);
                min_heap.erase(itr);
                make_heap(min_heap.begin(), min_heap.end(), minHeap_);
            }
        }
        else{
            cout<<min_heap.front()<<endl;
        }
    }
    return 0;
}
