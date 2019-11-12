
#include <iostream>
#include<vector>

using namespace std;

int faulty_result(vector<int> &v){
    bool present = 0;
    for(int i = 1 ; i < v.size() ; i++)
        present |= (v[i] + v[i-1])%3 == 0;
    if(present)
        cout  << "Sorry, I fucked up!!!" << endl;
    return present;
}
int main() {
    int T, n, val; cin >> T;
    for(; T > 0 ; T--){
        cin >> n;
        
        vector<vector<int>> elements(3);
        for(int i = 0; i < n ; i++){
            cin >> val;
            if(val % 3 == 0)
                elements[0].push_back(val);
            else if(val % 3 == 1)
                elements[1].push_back(val);
            else
                elements[2].push_back(val);
        }
        
        // core
        // cz : count of zeros, co : count of ones , ct : count of two
        int cz = elements[0].size(), co = elements[1].size(), ct = elements[2].size();    
        int ez = co!=0 && ct!=0;     // ez : extra zero = 1, need later if both 1 and 2 are present
        
        // base test
        if(cz < ez || cz > (n/2 + (n&1))){
            cout << "-1" << endl;
            continue;
        }
        
        cz -=  ez;
        vector<int> A(n, -1);

        // zeros
         int i = 0, j = 0;
        while(i < n && j < cz){
            A[i] = elements[0][j++];
            i += 2;
        }
        
        // ones
        i = 0, j = 0;
        while(i < n && j < co){
            if(A[i]==-1)
                A[i] = elements[1][j++];
            i++;
        }

        // twos
        i = 0, j = 0;
        while(i < n && j < ct){
            if(A[i]==-1){
                if(i >=1 && A[i-1] % 3 == 1 && ez)
                    A[i] =  elements[0][cz], ez--;
                else
                    A[i] = elements[2][j++];
            }
            i++;
        }
        if(ez)
            A[n-1] = elements[0][cz], ez--;
        
        if(!faulty_result(A)){
            for(int e : A)
                cout << e << " ";
            cout << endl;
        }
    }
    return 0;
}


/*
Input:
7
11
1 1 0 0 0 0 0 0 2 2 2
9
1 1 0 0 0 0 0 0 2
6 
0 1 0 1 2 2 
4 
0 0 0 1
4
1 2 1 2
4
2 2 2 1 
5
0 0 0 2 2

Output:
0 1 0 1 0 2 0 2 0 2 0 
-1
0 1 1 0 2 2 
-1
-1
-1
0 2 0 2 0
*/