
int main() {
    int n, k; cin >> n >> k;
    vector<int> tower(n);
    for(int i = 0; i < n; ++i)
        cin >> tower[i];
    
    int count = 0,  last = -1, front = -1;
    while(front < n-1) {
        int seek = min(front+k, n-1);
        while(seek > last && tower[seek] == 0)
            seek -= 1;

        if(seek == last) {
            count = -1;
            break;
        }
    
        count += 1;
        last = seek;
        front = seek + k - 1;
    }
    cout << count << endl;
    return 0;
}




int main() {
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    
    int xmits = 0;
    for(auto cur = v.begin(); cur != v.end(); ) {
        auto place = upper_bound(cur, v.end(), (*cur)+k) - 1;
        cur = lower_bound(place, v.end(), (*place)+k+1);
        xmits += 1;
    }
    cout << xmits << endl;
    
    return 0;
}