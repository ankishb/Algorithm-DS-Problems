
int count_jumps(vi A, int x, int y){
    int count = 0, cur, n = A.size();
    for(auto a : A){
        cur = 1;
        a -= x;
        /* // why this logic is not working
        // cur += floor(a/(x-y));
        // a = a%(x-y);
        // if(a > 0) cur++;
        */
        while(a > 0){
            cur++;
            a -= (x-y);
        }
        count += cur;
    }
    return count;
}




// older one
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