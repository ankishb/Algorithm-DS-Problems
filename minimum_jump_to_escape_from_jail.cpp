// A thief trying to escape from a jail has to cross N walls each with varying heights. He climbs X feet every time. But, due to the slippery nature of those walls, every times he slips back by Y feet.  Now the task is to calculate the total number of jumps required to cross all walls and escape from the jail.

#include <bits/stdc++.h>
using namespace std;

void get_minimum_jump(int arr[], int x, int y, int n){
	int jumps=0;
	for(int i=0; i<n; i++){
		while(arr[i]>0){
			if(arr[i] <= x){
				jumps++;
				arr[i] = max(0, arr[i]-x);
			}
			else{
				jumps++;
				arr[i] = max(0, arr[i]-(x-y));
			}
		}
	}
	cout<<jumps<<endl;
}

int main()
{
	int test;
	cin>>test;

	while(test--){
		// jump size, slippery size, no_of_walls
		int x, y, n;
		cin>>x>>y>>n;

		int heights[n];
		for(int i=0; i<n; i++){
			cin>>heights[i];
		}

		get_minimum_jump(heights, x, y, n);
	}
	return 0;
}