

// Complete the largestPermutation function below.
vector<int> largestPermutation(int k, vector<int> arr) {
    // vector<pair<int,int>> helper;
    unordered_map<int, int> helper;
    for(int i=0; i<arr.size(); i++){
        helper[arr[i]] = i;
    }
    int n = arr.size(), i = 0, no = n;
    while(k>0 && i<n){
        // cout<<i<<" "<<arr[i]<<" "<<no<<" "<<k<<endl;
        if(arr[i] >= no){ i++; no--; }
        else if(arr[i] < no){
            int idx1 = helper[no], idx2 = helper[arr[i]];
            int val1 = no, val2 = arr[i];
            swap(arr[i], arr[helper[no]]);
            helper[val1] = idx2;
            helper[val2] = idx1;
            i++; no--; k--;
        }
    }
    return arr;
}