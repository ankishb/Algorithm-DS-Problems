
int Solution::mice(vector<int> &mice_pos, vector<int> &holes) {
    sort(mice_pos.begin(), mice_pos.end());
    sort(holes.begin(), holes.end());
    int n = holes.size();
    
    int diff = INT_MIN;
    for(int i=0; i<n; i++){
        diff = max(diff, abs(mice_pos[i]-holes[i]));
    }
    return diff;
}
