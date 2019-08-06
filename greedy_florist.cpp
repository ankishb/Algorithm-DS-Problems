
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