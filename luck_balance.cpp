
// contests[2] ==> luck balance and importance of contest
int luckBalance(int k, vector<vector<int>> contests) {
    vector<pair<int, int>> contest;
    int count = 0;
    for(int i=0; i<contests.size(); i++){
        if(contests[i][1] == 1) count++;
        contest.push_back(make_pair(contests[i][0], contests[i][1]));
    }
    sort(contest.begin(), contest.end());
    int ans = 0;
    count = count-k;
    for(auto itr : contest){
        if(count>0 && itr.second==1){
            ans -= itr.first;
            count--;
        }
        else{
            ans += itr.first;
        }
    }
    return ans;
}
