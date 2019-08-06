#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)

bool check_AP(vector<int> vect, int n){
    int a = vect[0];
    int d = vect[1]-vect[0];
    for(int i=2; i<n; i++){
        if(a+i*d != vect[i]){
            return false;
        }
    }
    cout<<a+n*d<<endl;
    return true;
}
bool check_GP(vector<int> vect, int n)
    int a = vect[0];
    int r = vect[1]/vect[0];
    for(int i=2; i<n; i++){
        if(a*pow(r, i) != vect[i]){
            return false;
        }
    }
    cout<<a*pow(r, n)<<endl;
    return true;
}
bool check_FIB(vector<int> vect, int n)
    int a = vect[0];
    int b = vect[1];
    for(int i=2; i<n; i++){
        if(vect[i-2]+vect[i-1] != vect[i]){
            return false;
        }
    }
    cout<<vect[n-2]+vect[n-1]<<endl;
    return true;
}

void find_next_element(vector<int> vect){
    int n = vect.size();
    if(!check_AP(vect, n)){
        if(!check_GP(vect, n)){
            if(!check_FIB(vect, n)){
                cout<<"-99999 \n";
            }
        }
    }
}


void solve(){
    int n;
    cin>>n;
    vector<int> vect(n);
    for(int i=0; i<n; i++){
        cin>>vect[i];
    }
    
    find_next_element(vect);
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