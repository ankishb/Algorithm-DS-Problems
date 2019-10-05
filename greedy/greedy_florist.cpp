
// new approach
int getMinimumCost(int k, vector<int> c) {
    int n = c.size();
    sort(c.begin(), c.end());
    int mul = 1, i = n-1, ans = 0, count = 0;
    while(i >= 0){
        ans += mul*c[i];
        count++;
        if(count == k){
            count = 0;
            mul++;
        }
        i--;
    }
    return ans;
}
// old approach
int getMinimumCost(int k, vector<int> c) {
    sort(c.begin(), c.end());
    int n = c.size();
    int count = 0;
    int ans = 0;
    int kk = k;
    for(int i=n-1; i>=0; i--){
        ans += (count+1)*c[i];
        kk--;
        if(kk == 0){
            kk = k;
            count++;
        }
    }
    return ans;
}