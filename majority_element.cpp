// Given an array of size n, find the majority element. The majority element is the element that appears more than floor(n/2) times.

// You may assume that the array is non-empty and the majority element always exist in the array.

// Example :

// Input : [2, 1, 2]
// Return  : 2 which occurs 2 times which is greater than 3/2. 




#include <bits/stdc++.h>
using namespace std;

int find_major_element(vector<int> A){
	int k = floor(A.size()/2);
	sort(A.begin(), A.end());

	for(int i=0; i<A.size(); i++){
		cout<<A[i]<<" ";
	}
	cout<<endl<<"==========="<<endl;

	unordered_map<int, int> freq_table;
	int hash[A[A.size() - 1]+5] = {0};
	for(int i=0; i<A.size(); i++){
		cout<<A[i]<<" -- "<<k<<endl;
		freq_table[A[i]]++;
		hash[A[i]]++;
	}
	
	// for(int i=0; i<freq_table.size(); i++){
	// 	cout<< freq_table[i]->first <<" " << freq_table[i]->second<<endl;
	// }

	int max_value=-1, max_count=0;
	unordered_map<int, int>::iterator it;
	for(it=freq_table.begin(); it!=freq_table.end(); ++it){
		cout<< it->first <<" " << it->second<<endl;
		if(it->second > max_count && it->second > k){
			max_count = it->second;
			max_value = it->first;
		}
	}

	// int max = -1;
	// for(int i=0; i<A.size(); i++){
	// 	cout<<hash[A[i]]<<" ";
	// 	max = (max > hash[A[i]]) ? max : A[i];
	// }
	cout<<endl<<"==========="<<endl;
	cout<<max_count << " " << max_value<<endl;
	
}


int optimal_find_major_element(vector<int> A){
    int k = floor(A.size()/2);

    unordered_map<int, int> freq_table;
    for(int i=0; i<A.size(); i++){
        freq_table[A[i]]++;
    }
    
    int max_value=-1, max_count=0;
    unordered_map<int, int>::iterator it;
    for(it=freq_table.begin(); it!=freq_table.end(); ++it){
        // cout<< it->first <<" " << it->second<<endl;
        if(it->second > max_count && it->second > k){
            max_count = it->second;
            max_value = it->first;
        }
    }
    return max_value;
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<int> vect;
		int arr[n], el;
		for(int i=0; i<n; i++){
			cin>>el;
			vect.push_back(el);
		}

		// find_major_element(vect);
		cout<<optimal_find_major_element(vect)<<endl;
	}
	return 0;
}
