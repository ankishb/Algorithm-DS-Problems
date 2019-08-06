
#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)

int colorful(int A){
    if(A==0){
        return 1;
    }
    unordered_set<int> my_set;
    unordered_set<int>::iterator itr;
    vector<int> vect;
    while(A!=0){
        vect.push_back(A%10);
        A = A/10;
    }
    int prod;

    for(int i=0; i<vect.size(); i++){
        prod = 1;
        for(int j=i; j<vect.size(); j++){
            if(i==j){
                prod = vect[i];
                // cout<<prod<<endl;
            }
            else{
                prod = prod*vect[j];
                // cout<<prod<<endl;
            }
            itr = my_set.find(prod);
            if(itr != my_set.end()){
                return 0;
            }
            my_set.insert(prod);
        }
    }
    return 1;
}

int main()
 {
	int test;
	cin>>test;
	cin.ignore(1);
	while(test--){
	    int n;
	    cin>>n;
	    cout<<colorful(n)<<endl;
	}
	return 0;
}
