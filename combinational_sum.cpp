
// new program
void helper(vector<int> A, int sum, int curSum, int idx,
    set<vector<int>> &store, vector<int> &temp){
    if(curSum > sum) return;
    if(idx > A.size()) return ;
    if(curSum == sum){
        store.insert(temp);
        return;
    }
    for(int i=idx; i<A.size(); i++){
        temp.push_back(A[i]);
        helper(A, sum, curSum+A[i], i, store, temp);
        temp.pop_back();
        helper(A, sum, curSum, i+1, store, temp);
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int t) {
    int n = A.size();
    if(n == 0) return {{}};
    set<vector<int>> store;
    vector<vector<int>> store_;
    vector<int> temp;
    sort(A.begin(), A.end());
    helper(A, t, 0, 0, store, temp);
    for(auto v : store){
        // sort(v.begin(), v.end());
        store_.push_back(v);
    }
    return store_;
}




// submitted on interviewBit
void rec(vector<int> A, int B, int idx, int sum, vector<vector<int> > &ans, vector<int> &temp){
    if(sum == B){
        // sort(temp.begin(), temp.end());
        ans.push_back(temp);
        // ans.insert(temp);
        return ;
    }
    else if(sum>B){
        return ;
    }
    for(int i=idx; i<A.size(); i++){
        sum = sum + A[i];
        if(sum<=B){
            temp.push_back(A[i]);
        }
        else{
            sum = sum - A[i];
            break;
        }

        rec(A, B, i, sum, ans, temp);
        sum = sum - A[i];
        temp.pop_back();
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
// void get_all_possible_combinational_sum(vector<int> A, int B){
    vector<int> temp;
    vector<vector<int> > ans;
    int sum = 0;
    sort(A.begin(),  A.end());
    A.erase(unique(A.begin(), A.end()), A.end()); 
    rec(A, B, 0, sum, ans, temp);

    // vector<vector<int> > ans;
    // for(auto itr: ans1){
    //     ans.push_back(itr);
    // }
    return ans;
}









// Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

// The same repeated number may be chosen from C unlimited number of times.

#include <bits/stdc++.h>
using namespace std;

void rec(vector<int> A, int B, int idx, int sum, set<vector<int> > &ans, vector<int> &temp){
    if(sum == B){
        sort(temp.begin(), temp.end());
        // ans.push_back(temp);
        ans.insert(temp);
        return ;
    }
    else if(sum>B){
        return ;
    }
    for(int i=idx; i<A.size(); i++){
        sum = sum + A[i];
        temp.push_back(A[i]);

        rec(A, B, i, sum, ans, temp);
        sum = sum - A[i];
        temp.pop_back();
    }
}

void get_all_possible_combinational_sum(vector<int> A, int B){
    vector<int> temp;
    set<vector<int> > ans1;
    int sum = 0;
    rec(A, B, 0, sum, ans1, temp);

    vector<vector<int> > ans;
    for(auto itr: ans1){
        ans.push_back(itr);
    }

    cout<<"\n All combinations \n";
    for(auto itr1:ans){
        for(auto itr2 : itr1){
            cout<<itr2<<" ";
        }
        cout<<endl;
    }
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n, k;
        cin>>n;
        vector<int> vect;
        int el;
        while(n--){
            cin>>el;
            vect.push_back(el);
        }
        cin>>k;
        get_all_possible_combinational_sum(vect, k);
	}
	return 0;
}



//  my submission

void rec(vector<int> A, int B, int idx, int sum, vector<vector<int> > &ans, vector<int> &temp){
    if(sum == B){
        // sort(temp.begin(), temp.end());
        ans.push_back(temp);
        // ans.insert(temp);
        return ;
    }
    else if(sum>B){
        return ;
    }
    for(int i=idx; i<A.size(); i++){
        sum = sum + A[i];
        if(sum<=B){
            temp.push_back(A[i]);
        }
        else{
            sum = sum - A[i];
            break;
        }

        rec(A, B, i, sum, ans, temp);
        sum = sum - A[i];
        temp.pop_back();
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
// void get_all_possible_combinational_sum(vector<int> A, int B){
    vector<int> temp;
    vector<vector<int> > ans;
    int sum = 0;
    sort(A.begin(),  A.end());
    A.erase(unique(A.begin(), A.end()), A.end()); 
    rec(A, B, 0, sum, ans, temp);

    // vector<vector<int> > ans;
    // for(auto itr: ans1){
    //     ans.push_back(itr);
    // }
    return ans;
}








// class Solution {
// public:

//     void doWork(vector<int> &candidates, int index, vector<int> &current, int currentSum, int target, vector<vector<int> > &ans) {
//         if (currentSum > target) {
//             return;
//         }
//         if (currentSum == target) {
//             ans.push_back(current);
//             return;
//         }
//         for (int i = index; i < candidates.size(); i++) {
//             current.push_back(candidates[i]);
//             currentSum += candidates[i];

//             doWork(candidates, i, current, currentSum, target, ans);
            
//             current.pop_back();
//             currentSum -= candidates[i];
//         }
        
//     }

//     vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
//         vector<int> current; 
//         vector<vector<int> > ans;
//         sort(candidates.begin(), candidates.end());
//         vector<int> uniqueCandidates;
//         for (int i = 0; i < candidates.size(); i++) {
//             if (i == 0 || candidates[i] != candidates[i-1]) {
//                 uniqueCandidates.push_back(candidates[i]);
//             }
//         }
//         doWork(uniqueCandidates, 0, current, 0, target, ans); 
//         return ans;
//         }
// };