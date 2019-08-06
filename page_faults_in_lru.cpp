// https://practice.geeksforgeeks.org/problems/page-faults-in-lru/0

// In operating systems that use paging for memory management, page replacement algorithm are needed to decide which page needs to be replaced when the new page comes in. Whenever a new page is referred and is not present in memory, the page fault occurs and Operating System replaces one of the existing pages with a newly needed page. Given a sequence of pages and memory capacity, your task is to find the number of page faults using Least Recently Used (LRU) Algorithm.

#include <bits/stdc++.h>
using namespace std;

void count_page_fault(int arr[], int n, int capacity){
	queue<int> cache;
	int hash[1005] = {0};
	int fault_counts = 0;

	for(int i=0; i<n; i++){
		if(cache.size() < capacity && hash[arr[i]] == 0){
			cache.push(arr[i]);
			hash[arr[i]] = 1;
			fault_counts++;
		}
		else if(hash[arr[i]] == 0){
			hash[cache.front()] = 0;
			cache.pop();
			cache.push(arr[i]);
			hash[arr[i]] = 1;
			fault_counts++;
		}
	}
	cout<<fault_counts<<endl;
}


void _count_page_fault(int arr[], int n, int capacity){
	deque<int> cache;
	deque<int>::iterator it;
	int hash[1005] = {0};
	int fault_counts = 0;

	for(int i=0; i<n; i++){
		if(cache.size() < capacity && hash[arr[i]] == 0){
			cache.push_back(arr[i]);
			hash[arr[i]] = 1;
			fault_counts++;
		}
		else if(hash[arr[i]] == 0){
			hash[cache.front()] = 0;
			cache.pop_front();
			cache.push_back(arr[i]);
			hash[arr[i]] = 1;
			fault_counts++;
		}
		else if(hash[arr[i]] == 1){
			it = find(cache.begin(), cache.end(), arr[i]);
			if(it != cache.end()){
				// found position of element in queue, just erase it
				cache.erase(it);
				cache.push_back(arr[i]);
			}
		}
	}
	cout<<fault_counts<<endl;
}

int main()
{
	int test;
	cin>> test;
	while(test--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		int capacity;
		cin>>capacity;

		_count_page_fault(arr, n, capacity);
	}
	return 0;
}