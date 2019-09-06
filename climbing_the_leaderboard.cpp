/*
Approach:
Idea 1: We use Binary search, as alice's score is in increasing order, so previous rank won't interfere/influence current rank. O(MlogN)
Idea 2: (from discussion form) Transverse from back in score array and forword in alice's score array and ollect appropriate rank. O(N)
*/


// Complete the climbingLeaderboard function below.
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    int n = scores.size(), m = alice.size();
    int i = n-1, j = 0;
    vector<int> ranks(m, 0);

    unordered_map<int, int> myMap;
    int rank = 1;
    for(int i=0; i<n; i++){
        if(myMap.find(scores[i]) == myMap.end()){
            myMap[scores[i]] = rank;
            rank++;
        }
    }
    while(j < m){
        while(i>=0 && scores[i] < alice[j]){
            i--;
        }
        if(i<0) ranks[j] = myMap[scores[0]];
        else if(i>=0 && scores[i] == alice[j]) ranks[j] = myMap[scores[i]];
        else ranks[j] = myMap[scores[i]]+1;
        j++;
    }
    return ranks;
}
