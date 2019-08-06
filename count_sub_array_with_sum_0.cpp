
#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(n^2)
void count_subarray_with_sum_zero(vector<int> vect){
	int sum=0, count=0;
	int max_len = INT_MIN;
	int n = vect.size();
	for(int i=0; i<n; i++){
		sum = 0;
		for(int j=i; j<n; j++){
			sum += vect[j];
			if(sum == 0) count++;
			if(sum == 0) max_len = max(max_len, j-i+1);
		}
	}
	cout<<"count: "<<count<<endl;
	cout<<"Max-Len: "<<max_len<<endl;
}

// there are 3 cases to check
// 	1. If sum is zero, we increase count and also check in map, if any other 0 present, we add that many instances in count too.
// 	2. If sum!=0, but current sum exist in the map already, this ensure that, there is another sequence with sum as 0, we add that many instances in count too.
// 	3. Else we update our map.
void optimal_count_subarray_with_sum_zero(vector<int> vect){
	int n = vect.size();
	int count=0, sum=0;
	int max_len=INT_MIN;
	unordered_map<int, int> my_map;

	for(int i=0; i<n; i++){
		sum += vect[i];

		if(sum == 0){
			count++;
			if(my_map.find(sum) != my_map.end()){
				count += my_map[sum];
				my_map[sum]++;
			}
		}
		else if(my_map.find(sum) != my_map.end()){
			count += my_map[sum];
			my_map[sum]++;
		}
		else{
			my_map[sum]++;
		}
	}
	cout<<"count: "<<count<<endl;
}

void optimal_max_len_subarray_with_sum_zero(vector<int> vect){
	int n = vect.size();
	int count=0, sum=0;
	int max_len=0;
	unordered_map<int, int> my_map;

	for(int i=0; i<n; i++){
		sum += vect[i];

		if(vect[i]==0 && max_len==0){
			max_len = 1;
		}
		// to understand, follow these 2 exps: [0,1,4,-2,-2] & [0,4,-2,-2]
		if(sum == 0){
			max_len = i+1;
		}
		if(my_map.find(sum) != my_map.end()){
			max_len = max(max_len, i-my_map[sum]);
		}
		else{
			my_map[sum] = i;
		}
	}
	cout<<"max_len: "<<max_len<<endl;
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
		// count_subarray_with_sum_zero(vect);
		optimal_count_subarray_with_sum_zero(vect);
		optimal_max_len_subarray_with_sum_zero(vect);
	}
	return 0;
}



// int countZeroSumSubArray(vector<int>A)
// {
//     map<int,int>m;
//     int size=A.size();
//     int sum=0,count=0;
//     for(int i=0;i<size;i++)
//     {
//         sum+=A[i];
//         if(sum==0)
//             {
//                 count++;
//                 if(m.find(sum)!=m.end())
//                     count+=m[sum];
//                 m[sum]++;
//             }
//         else if(m.find(sum)!=m.end())
//         {
//             count+=m[sum];
//             m[sum]++;
//         }
//         else
//             m[sum]=1;
//     }
//     return count;
// }