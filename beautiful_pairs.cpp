https://www.hackerrank.com/contests/source-code-series-1/challenges/beautiful-pairs-1/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int count_beautiful_pair(vector<int> A){
    int n = A.size();
    if(n < 2) return 0;
    int max_el = A[0], count = 0;
    for(int i=0; i<n; i++){
        if(A[i] >= max_el){
            count += i;
            max_el = A[i];
        }
    }
    return count;
}
int naive(vector<int> A){
    int n = A.size(), count = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(A[i] <= A[j]){
                count++;
            }
        }
    }
    return count;
}

int main() {
    int test;
    cin>>test;
    while(test--){
        int n; cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
        // cout<<count_beautiful_pair(v)<<endl;
        cout<<naive(v)<<endl;
    }
    return 0;
}
