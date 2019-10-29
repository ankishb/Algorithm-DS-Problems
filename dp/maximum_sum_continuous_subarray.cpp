
// new try
class Solution {
public:
	int maxSubArray(vector<int>& A) {
        int n = A.size(), max_sum = A[0], cur_sum = 0;
        for(int i=0; i<n; i++){
            cur_sum += A[i];
            if(max_sum < cur_sum) max_sum = cur_sum;
            if(cur_sum < 0) cur_sum = 0;
        }
        return max_sum;
    }
};

// old one
class Solution {
public:
    int maxSubArray(vector<int>& A) {
        int n = A.size(); if(n == 0) return 0;
        int max_sum = INT_MIN, cur_sum = 0;
        for(int i=0; i<n; i++){
            cur_sum += A[i];
            max_sum = max(max_sum, cur_sum);
            if(cur_sum < 0) cur_sum = 0;
        }
        return max_sum;
    }
};




#include <bits/stdc++.h>
using namespace std;

void kadanes_algo(vector<int> vect){
	int global_max = INT_MIN;
	int cur_sum = 0;
	for(int i=0; i<vect.size(); i++){
		cur_sum	+= vect[i];
		if(global_max < cur_sum){
			global_max = cur_sum;
		}
		if(cur_sum < 0){
			cur_sum = 0;
		}
	}
	cout<<global_max<<endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<int> vect(n);
		for(int i=0; i<n; i++){
			cin>>vect[i];
		}
		kadanes_algo(vect);
	}
	return 0;
}
