
/*
Flipkart IIT Kanpur 2018

https://www.hackerrank.com/contests/hack-it-to-win-it-paypal/challenges/q4-traveling-is-fun
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

struct dsu {
    vector<int> par, sz;
    dsu(int n): par(n), sz(n, 1) {
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }
    int root(int a) {
        if (a == par[a]) return a;
        return par[a] = root(par[a]);
    }
    void merge(int a, int b) {
        a = root(a);
        b = root(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        par[b] = a;
    }
};

vector<int> findReachable(int n, int g, vector<int> from, vector<int> to) {
    dsu d(n);
    for (int k = g + 1; k <= n; k++) {
        for (int x = 2 * k; x <= n; x += k) {
            d.merge(x - 1, x - k - 1);
        }
    }

    int m = from.size();
    vector<int> ans;
    for (int i = 0; i < m; i++) {
        ans.push_back(d.root(from[i] - 1) == d.root(to[i] - 1));
    }
    return ans;
}

signed main() {
    vector<int> from {10, 4, 3, 6};
    vector<int> to {3, 6, 2, 9};
    vector<int> reachable = findReachable(10, 1, from, to);
    for (int i = 0; i < 4; i++) {
        cout << "From " << from[i] << " to " << to[i] << ": ";
        cout << (reachable[i] ? "Possible" : "Not possible") << '\n';
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

bool dfs(int src, int dst, vector<int> adj[], vector<bool> vis){
    
    for(auto v : adj[src]){
        if(v == dst) return true;
        if(vis[v]) continue;
        vis[v] = true;
        return dfs(v, dst, adj, vis);
    }
    return false;
}

vector <int> connectedCities(int n, int g, vector <int> originCities, vector <int> destinationCities) {
    vector<int> adj[n+1];
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(gcd(i,j) > g){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    
    int nq = originCities.size();
    vector<int> ans(nq,0);
    int u, v;
    for(int i=0; i<nq; i++){
        u = originCities[i];
        v = destinationCities[i];
        vector<bool> vis(n+1, false);
        ans[i] = dfs(u, v, adj, vis);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int g;
    cin >> g;
    int originCities_cnt;
    cin >> originCities_cnt;
    vector<int> originCities(originCities_cnt);
    for(int originCities_i = 0; originCities_i < originCities_cnt; originCities_i++){
    	cin >> originCities[originCities_i];
    }
    int destinationCities_cnt;
    cin >> destinationCities_cnt;
    vector<int> destinationCities(destinationCities_cnt);
    for(int destinationCities_i = 0; destinationCities_i < destinationCities_cnt; destinationCities_i++){
    	cin >> destinationCities[destinationCities_i];
    }
    vector <int> res = connectedCities(n, g, originCities, destinationCities);
    for (ssize_t i = 0; i < res.size(); i++) {
        cout << res[i] << (i != res.size() - 1 ? "\n" : "");
    }
    cout << endl;


    return 0;
}





public static List<Integer> connectedCities(int n, int g, List<Integer> originCities, List<Integer> destinationCities) {
    int[] root = new int[n + 1];
    int[] ids = new int[n + 1];

    for (int i = 0; i <= n; i++) {
        root[i] = i;
        ids[i] = 1;
    }

    for (int i = g + 1; i <= n; i++)
        for (int j = 2 * i; j <= n; j += i)
            unionFind(j, i, root, ids);

    List<Integer> res = new ArrayList<>(originCities.size());
    Iterator<Integer> itSrc = originCities.iterator();
    Iterator<Integer> itDest = destinationCities.iterator();

    while (itSrc.hasNext() && itDest.hasNext())
        res.add(getRoot(itSrc.next(), root) == getRoot(itDest.next(), root) ? 1 : 0);

    return res;
}

private static void unionFind(int a, int b, int[] root, int[] ids) {
    int aRoot = getRoot(a, root);
    int bRoot = getRoot(b, root);

    if (aRoot == bRoot)
        return;

    if (ids[aRoot] < ids[bRoot]) {
        root[aRoot] = root[bRoot];
        ids[bRoot] += ids[aRoot];
    } else {
        root[bRoot] = root[aRoot];
        ids[aRoot] += ids[bRoot];
    }
}

private static int getRoot(int a, int[] root) {
    while (a != root[a])
        a = root[a];
    return a;
}