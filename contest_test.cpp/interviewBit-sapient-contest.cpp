
int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E, vector<int> &F) {
    int n = C.size();
    int x_A1, x_A2, y_A1, y_A2, x_B1, x_B2, y_B1, y_B2;
    for(int i=0; i<n; i++){
        x_A1 = A[0]+C[i];
        y_A1 = A[1]+D[i];
        x_B1 = B[0]+E[i];
        y_B1 = B[1]+F[i];

        x_A2 = A[0]+E[i];
        y_A2 = A[1]+F[i];
        x_B2 = B[0]+C[i];
        y_B2 = B[1]+D[i];
        
        long long int dist12 = abs(x_A1 - x_B1) + abs(y_A1 - y_B1);
        long long int dist21 = abs(x_A2 - x_B2) + abs(y_A2 - y_B2);

        if(dist12 > dist21){
            A[0] += C[i];
            A[1] += D[i];
            B[0] += E[i];
            B[1] += F[i];
        }
        else{
            A[0] += E[i];
            A[1] += F[i];
            B[0] += C[i];
            B[1] += D[i];
        }
    }
    return abs(A[0] - B[0]) + abs(A[1] - B[1]);
}





int Solution::solve(vector<int> &A) {
    int mod = 1000000007;
    set<vector<int>> store;
    vector<int> temp;
    int n = A.size();
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            temp.push_back(A[j]);
            store.insert(temp);
        }
        temp.clear();
    }
    
    long long int ans = 1;
    int max_ = 0;
    for(auto itr1 : store){
        max_ = 0;
        for(auto itr2 : itr1){
            cout<<itr2<<" ";
            max_ = max(max_, itr2);
        }
        cout<<" : "<<max_<<endl;
        ans = ans*(max_%mod);
        ans = ans%mod;
    }
    return ans%mod;
}
