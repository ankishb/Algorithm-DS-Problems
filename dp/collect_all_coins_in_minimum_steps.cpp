/*
Idea:
use divide and conquer
1. Find minimum height in range(let's say we find 2), 
	- Either we use 2 horizontal pass to collect all
	- Or just a single pass for vertical to collect
2. Now divide the array into 2 half, first one is (start -- mid-1) and right one is (mid+1 -- end)


Input:
	3(test)
	5(N)
	2 1 2 5 1
	5
	3 4 1 2 1
	7
	3 4 1 2 1 0 10

Output:
	4
	4
	5
*/

#include <bits/stdc++.h>
using namespace std;

int get_min_count(vector<int> h, int l, int r, int min_h){
    // cout<<l<<" "<<r<<" "<<min_h<<endl;
    if(l > r) return 0;

    int mid = l;
    for(int i=l; i<=r; i++){
        if(h[i] < h[mid]) mid = i;
    }
    int ver = r-l+1;
    int hor = h[mid] - min_h;
    int left_h = get_min_count(h, l, mid-1, h[mid]);
    int right_h = get_min_count(h, mid+1, r, h[mid]);
    return min(ver, left_h + right_h + hor);
}

int main()
{
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        vector<int> h(n);
        for(int i=0; i<n; i++){
            cin>>h[i];
        }
        cout<<get_min_count(h, 0, n-1, 0)<<endl;
    }
    return 0;
}