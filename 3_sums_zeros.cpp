vector<vector<int> > Solution::threeSum(vector<int> &A) {
    vector<vector<int> > ans;
    set<vector<int> > ans1;
    vector<int> temp;
    int cur_sum = 0;
    unordered_map<int, int> my_map;
    for(int i=0; i<A.size(); i++){
        for(int j=i+1; j<A.size(); j++){
            cur_sum = A[i] + A[j];
            if(my_map.find(-cur_sum) != my_map.end()){
                // element found
                int index = my_map[-cur_sum];
                if(index != i && index != j){
                    temp.push_back(A[i]);
                    temp.push_back(A[j]);
                    temp.push_back(-cur_sum);
                    sort(temp.begin(), temp.end());
                    // ans.push_back(temp);
                    ans1.insert(temp);
                    temp.clear();
                }
            }
            else{
                my_map.insert({A[j], j});
            }
        }
    }
    for(auto itr : ans1){
        ans.push_back(itr);
    }
    ans1.clear();
    // sort( ans.begin(), ans.end() );
    // ans.erase( unique(ans.begin(), ans.end()), ans.end() );
    return ans;
}


