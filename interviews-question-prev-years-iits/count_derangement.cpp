
/* flipkart

Count Derangements (Permutation such that no element appears in its original position)

A Derangement is a permutation of n elements, such that no element appears in its original position. For example, a derangement of {0, 1, 2, 3} is {2, 3, 1, 0}.

Given a number n, find total number of Derangements of a set of n elements.

Examples :

Input: n = 2
Output: 1
For two elements say {0, 1}, there is only one 
possible derangement {1, 0}

Input: n = 3
Output: 2
For three elements say {0, 1, 2}, there are two 
possible derangements {2, 0, 1} and {1, 2, 0}

Input: n = 4
Output: 9
For four elements say {0, 1, 2, 3}, there are 9
possible derangements {1, 0, 3, 2} {1, 2, 3, 0}
{1, 3, 0, 2}, {2, 3, 0, 1}, {2, 0, 3, 1}, {2, 3,
1, 0}, {3, 0, 1, 2}, {3, 2, 0, 1} and {3, 2, 1, 0}

*/

#include <bits/stdc++.h>
using namespace std;

void get_permute(int n, vector<vector<int>> &store, 
    vector<int> &cur, vector<bool> &vis){
    if(cur.size() == n){
        store.push_back(cur);
        return;
    }
    for(int i=0; i<n; i++){
        if(vis[i] == true) continue;
        if(cur.size() == i) continue;
        cur.push_back(i);
        vis[i] = true;
        get_permute(n, store, cur, vis);
        cur.pop_back();
        vis[i] = false;
    }
}

int main()
{
    for(int n=1; n<10; n++){
        vector<int> cur;
        vector<bool> vis(n, false);
        vector<vector<int>> store;
        get_permute(n, store, cur, vis);
        cout<<store.size()<<endl;
    }
    return 0;
}

// Output: 0, 1, 2, 9, 44, 265, 1854, 14833, 133496