
#include <bits/stdc++.h>
using namespace std;

/*
Algorithm:

    1. First we find the minimum and maximum elements in the matrix. Minimum element can be easily found by comparing the first element of each row, and similarly the maximum element can be found by comparing the last element of each row.
    2. Then we use binary search on our range of numbers from minimum to maximum, we find the mid of the min and max, and get count of numbers less than our mid. And accordingly change the min or max.
    3. For a number to be median, there should be (r*c)/2 numbers smaller than that number. So for every number, we get the count of numbers less than that by using upper_bound() in each row of matrix, if it is less than the required count, the median must be greater than the selected number, else the median must be less than or equal to the selected number.
*/

int findMedian(vector<vector<int> > &A) {
// }
// // function to find median in the matrix 
// int binaryMedian(int m[][MAX], int r ,int c) 
// { 
    int r = A.size();
    int c = A[0].size();
    int min = INT_MAX, max = INT_MIN; 
    for (int i=0; i<r; i++) 
    { 
        // Finding the minimum element 
        if (A[i][0] < min) 
            min = A[i][0]; 
  
        // Finding the maximum element 
        if (A[i][c-1] > max) 
            max = A[i][c-1]; 
    } 
  
    int desired = (r * c + 1) / 2; 
    while (min < max) 
    { 
        int mid = min + (max - min) / 2; 
        int place = 0; 
  
        // Find count of elements smaller than mid 
        int temp;
        for (int i = 0; i < r; ++i){
            // place += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
            // cout<<"--"<<place<<endl;
            temp = upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
            
            place += temp; 
            cout<<"--"<<temp<<"--"<<place<<endl;
        }
        if (place < desired) 
            min = mid + 1; 
        else
            max = mid; 
    } 
    return min; 
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
        
        print_vector(vect);
        cout<<findMedian(vect);
    }
    return 0;
}