
#include <bits/stdc++.h>
using namespace std;

int search_element(vector<vector<int> > &A, int B){
    // start from top right of mXn matrix
    int m=A.size(), n=A[0].size();
    cout<<m<<"--"<<n<<endl;
    int i, j;
    i=0, j=n-1;
    while(i<=m-1 && j>=0){
        cout<<i<<" "<<j<<" "<<A[i][j]<<endl;
        if(B == A[i][j]){
            return 1;
        }
        if(B > A[i][j]){
            i++;
        }
        else if(B < A[i][j]){
            j--;
        }
    }
    return 0;
}

void print_vector(vector<vector<int> > vect){
    cout<<"\n ---- 2D Vector ---- \n";
    for(int i=0; i<vect.size(); i++){
            for(int j=0; j<vect[i].size(); j++){
                cout<<vect[i][j]<<" ";
            }
            cout<<endl;
        }
    cout<<"----------------------\n";
}

int main()
{
    int test;
    cin>>test;

    while(test--){
        int n, m;
        cin>>m>>n;

        // vector<vector<int> > vect(m);
        vector<vector<int> > vect(m, vector<int> (n, 0));
        int el;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cin>>vect[i][j];
                // vect[i].push_back(el);
            }
        }
        int ele;
        cin>>ele;
        
        print_vector(vect);
        cout<<search_element(vect, ele)<<endl;;
    }
    return 0;
}