


// old one
// int find_max_element(int arr[], int n){
//     int max_el = INT_MIN;
//     for(int i=0; i<n; i++){
//         max_el = max(max_el, arr[i]);
//     }
//     return max_el;
// }
// vector<vector<int> > Solution::solve(int k, vector<vector<int> > &A) {
//     int row = A.size();
//     int col = A[0].size();
//     int arr[5];
//     for(int kk=0; kk<k; kk++){
//         for(int i=0; i<row; i++){
//             for(int j=0; j<col; j++){
//                 arr[0] = (i-1>=0) ? A[i-1][j] : 0;
//                 arr[1] = (i+1<row) ? A[i+1][j] : 0;
//                 arr[2] = (j-1>=0) ? A[i][j-1] : 0;
//                 arr[3] = (j+1<col) ? A[i][j+1] : 0;
//                 arr[4] = A[i][j];
//                 A[i][j] = find_max_element(arr, 5);  
//             }
//         }
//     }
//     return A;
// }

vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int> >solution;
    int n=B.size();
    int m=B[0].size();
    int i;
    for(i=0;i<n;i++){
        solution.push_back(B[i]);
    }
    int k,j;
    int t;
    for(k=1; k<=A; k++){
        for(i=0; i<n; i++){
            for(j=0; j<m; j++){
                if(i-1>=0) solution[i][j]=max(solution[i][j],B[i-1][j]);
                if(i+1<n) solution[i][j]=max(solution[i][j],B[i+1][j]);
                if(j-1>=0) solution[i][j]=max(solution[i][j],B[i][j-1]);
                if(j+1<m) solution[i][j]=max(solution[i][j],B[i][j+1]);   
            } 
        }
        B=solution;
    }    
    return solution;
}




int find_max_element(int arr[], int n){
    int max_el = INT_MIN;
    for(int i=0; i<n; i++){
        max_el = max(max_el, arr[i]);
    }
    return max_el;
}
vector<vector<int> > Solution::solve(int k, vector<vector<int> > &A) {
    int row = A.size();
    int col = A[0].size();
    int arr[5];
    for(int kk=0; kk<k; kk++){
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                arr[0] = (i-1>=0) ? A[i-1][j] : 0;
                arr[1] = (i+1<row) ? A[i+1][j] : 0;
                arr[2] = (j-1>=0) ? A[i][j-1] : 0;
                arr[3] = (j+1<col) ? A[i][j+1] : 0;
                arr[4] = A[i][j];
                A[i][j] = find_max_element(arr, 5);  
            }
        }
    }
    return A;
}






vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int> >solution;
    int n=B.size();
    int m=B[0].size();
    int i;
    for(i=0;i<n;i++){
        solution.push_back(B[i]);
    }
    int k,j;
    int t;
    for(k=1; k<=A; k++){
        for(i=0; i<n; i++){
            for(j=0; j<m; j++){
                if(i-1>=0) solution[i][j]=max(solution[i][j],B[i-1][j]);
                if(i+1<n) solution[i][j]=max(solution[i][j],B[i+1][j]);
                if(j-1>=0) solution[i][j]=max(solution[i][j],B[i][j-1]);
                if(j+1<m) solution[i][j]=max(solution[i][j],B[i][j+1]);   
            } 
        }
        B=solution;
    }    
    return solution;
}








#include<bits/stdc++.h>
typedef pair<int,pair<int,int>> kamesh;
bool fun(kamesh a, kamesh b){
    return a.first>b.first;
}
vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B) {
    int n=B.size();
    int m1=B[0].size();
    vector<kamesh> m(n*m1);
    int k=0;
    for(int i=0;i<B.size();i++){
        for(int j=0;j<B[i].size();j++){
            m[k]=make_pair(B[i][j],make_pair(i,j));
            k++;
        }
    }
    sort(m.begin(),m.end(),fun);
    int x=m.size();
    vector<vector<int>> v(B.size(),vector<int> (B[0].size()));
    for(int i=0;i<B.size();i++){
        for(int j=0;j<B[i].size();j++){
            for(int l=0;l<x;l++){
                if((abs(i-(m[l].second).first)+abs(j-(m[l].second).second))<=A){
                    v[i][j]=B[(m[l].second).first][(m[l].second).second];
                    break;
                }
            }
        }
    }
    
    return v;
}

