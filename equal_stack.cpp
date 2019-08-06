
#include<bits/stdc++.h>
using namespace std;


int equalStacks(vector<int> v1, vector<int> v2, vector<int> v3){
    int n1=v1.size()-1, n2=v2.size()-1, n3=v3.size()-1;
    int sum1=0, sum2=0, sum3=0;
    for(int i=n1-1; i>=0; i--) v1[i] += v1[i+1];
    for(int i=n2-1; i>=0; i--) v2[i] += v2[i+1];
    for(int i=n3-1; i>=0; i--) v3[i] += v3[i+1];

    for(auto itr:v1){ cout<<itr<<" ";}
    cout<<endl;
    for(auto itr:v2){ cout<<itr<<" ";}
    cout<<endl;
    for(auto itr:v3){ cout<<itr<<" ";}
    cout<<endl;
    
    int n11=0, n22=0, n33=0;
    while(n11!=n1+1 && n22!=n2+1 && n33!=n3+1){
        cout<<n11<<" "<<n22<<" "<<n33<<endl;
        cout<<v1[n11]<<" "<<v2[n22]<<" "<<v3[n33]<<endl;
        
        if(v1[n11] == v2[n22] && v2[n22] == v3[n33]){
            return v1[n11];
        }
        int min_height = min(v1[n11], min(v2[n22], v3[n33]));
        if(v1[n11] != min_height) n11++;
        if(v2[n22] != min_height) n22++;
        if(v3[n33] != min_height) n33++;
        cout<<v1[n11]<<" "<<v2[n22]<<" "<<v3[n33]<<endl;
        cout<<"---------------"<<endl;
    }
    return 0;
}

int main()
{
	int test = 1;
	// cin>>test;
	while(test--){
		int n1, n2, n3;
		cin>>n1>>n2>>n3;
		vector<int> v1(n1);
		vector<int> v2(n2);
		vector<int> v3(n3);
		for(int i=0; i<n1; i++) cin>>v1[i];
		for(int i=0; i<n2; i++) cin>>v2[i];
		for(int i=0; i<n3; i++) cin>>v3[i];

		int ans = equalStacks(v1, v2, v3);
		cout<<ans<<endl;
	}
	return 0;
}