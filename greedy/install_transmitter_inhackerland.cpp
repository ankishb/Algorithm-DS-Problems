#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int n, k, p, prv[N];

int main() {

    scanf("%d %d", &n, &k);

    int last = -1, ans = 0;

    for(int i = 0; i < n; i++) {
        scanf("%d", &p);
        if(p == 1) last = i;
        prv[i] = last;
    }

    for(int i = 0; i < n; ) {
        int take = prv[min(i + k - 1, n - 1)];
        if(take == -1 || take + k <= i) { printf("-1\n"); return 0; }
        i = take + k; ans++;
    }

    printf("%d\n", ans);

    return 0;

}




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