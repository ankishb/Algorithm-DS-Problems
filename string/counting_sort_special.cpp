// Complete the countSort function below.
void countSort(vector<vector<string>> arr) {
    int n = arr.size();
    vector<string> adj[100];
    int count = 0;
    for(int i=0; i<n; i++){
        if(count < n/2){
            int no = stoi(arr[i][0]);
            adj[no].push_back("-");
        }
        else{
            int no = stoi(arr[i][0]);
            adj[no].push_back(arr[i][1]);
        }
        count++;
    }
    for(int i=0; i<100; i++){
        for(auto str : adj[i]){
            cout<<str<<" ";
        }
    }
    cout<<endl;
}