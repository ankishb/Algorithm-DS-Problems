// Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i] amount of money present in it.

#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)

void solve(){
	int n, el;
	cin>>n;
	vector<int> vect;
	for(int i=0; i<n; i++){
		cin>>el;
		vect.push_back(el);
	}

	int inc = 0; // include current element in exclude
	int exc = 0; // find whther to choose last include element or excluded element
	int prev_inc = 0;
	for(int i=0; i<n; i++){
		prev_inc = inc;
		inc = exc+vect[i];
		
		if(i==0){
			exc = 0;
		}
		else{
			exc = max(exc, prev_inc);
		}
		
	}

	cout<<max(inc, exc)<<endl;
}

int main()
 {
	int test;
	cin>>test;
	while(test--){
	    solve();
	}
	return 0;
}