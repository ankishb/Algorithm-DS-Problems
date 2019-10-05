
// new one
int get_min_count(vector<int> A){
	int j, i = 0, count = 0;
	int n = A.size();
    while(A[i] == 1) i++;
    while(i < n){
        count++;
        j = i+1;
        while(j < n && A[i] == A[j]) j++;
        i = j;
    }
    return count;
}

// old one
#include<bits/stdc++.h>
using namespace std;

int get_min_count(vector<int> vect){
	bool turn_state = 1;
	int n = vect.size();
	int count = 0;
	for(int i=0; i<n; i++){
		if(vect[i] != turn_state){
			count++;
			turn_state = (turn_state) ? 0 : 1;
		}
		// consider all bulbs with same state in continuous manner, from current step
		while(i<n && vect[i]==vect[i+1]){
			i++;
		}
	}
	return count;
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

		cout<<get_min_count(vect)<<endl;
	}
	return 0;
}
