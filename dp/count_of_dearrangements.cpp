
/* As problem states that no element should be at its own place.
So lets say, we have array (0,1,2,3,4) so 1 can't come at its own place,
There are two cases:
	1. If 1 is place at some index i, which refer that, they
		exchanged their position and left with (n-2) element
	2. If 1 is not placed at index i, so we left with (n-1)
		elements which can take place the current index

And all this is performed for (n-1) times for (n-1) elements

*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;
    vector<int> counts(1000, 0);
    counts[1] = 0;
    counts[2] = 1;
    for(int i=3; i<1000; i++){
        counts[i] = (i-1)*(counts[i-1] + counts[i-2]);
    }
    while(test--){
        int n;
        cin>>n;
        cout<<counts[n]<<endl;
    }
    return 0;
}