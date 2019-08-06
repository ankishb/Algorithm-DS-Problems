
#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)

int check_if_pair_exist(vector<int> &A, int B){
    unordered_map<int, int> my_map;
    int sum1, sum2;
    for(int i=0; i<A.size(); i++){
        sum1 = A[i] - B;
        sum2 = A[i] + B;

        if(my_map.find(sum1) != my_map.end() || my_map.find(sum2) != my_map.end()){
            cout<<"found\n";
            return 1;
        }
        else{
            my_map.insert(make_pair(A[i], i));
        }
    }
    return 0;
}

int main()
 {
	int test;
	cin>>test;
	cin.ignore(1);
	while(test--){
	    int n;
	    cin>>n;
        int el;
        vector<int> vect;
        for(int i=0; i<n; i++){
            cin>>el;
            vect.push_back(el);
        }
        int sum;
        cin>>sum;
	    cout<<check_if_pair_exist(vect, sum)<<endl;
	}
	return 0;
}
