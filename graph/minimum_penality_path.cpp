
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

/*
Note: Dijkstra doesn't work here, because with or, greedy doesn't work.
For exp: 1 | 10 = 11, whereas 2 | 10 = 10
With dijsktra, we may not able to reach at second case.
For solid proof, we through following example

8 9
1 2 1
1 3 2
2 4 1
3 4 2
4 5 10
5 6 1
5 7 2
6 8 1
7 8 2
1 8

Output: 10
*/
int beautifulPath(vector<pii> adj[], int n, int src, int dst){
    vector<vector<bool>> vis(n+1, vector<bool>(1025, false));
    vis[src][0] = true;
    int u, v, wu, wv;
    queue<pii> pq;
    pq.push({0, src});
    while(!pq.empty()){
        pii f = pq.front();
        pq.pop();
        u = f.second;
        wu = f.first;
        
        for(auto pv : adj[u]){
            v = pv.first;
            wv = pv.second;
            int cs = (wu | wv);
            if(!vis[v][cs]){
                vis[v][cs] = true;
                pq.push({cs, v});
            }
        }
    }
    for(int i=0; i<1025; i++){
        if(vis[dst][i]) return i;
    }
    return -1;
}

int main()
{
    int n, m, u, v, c;
    cin>>n>>m;
    vector<pii> adj[n+1];
    for(int i=0; i<m; i++){
        cin>>u>>v>>c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    int src, dst;
    cin>>src>>dst;
    cout<<beautifulPath(adj, n, src, dst);
    
    return 0;
}










// editorial approach (using bfs)
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>>E[N + 1];
    for (int i = 0; i < M; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        E[x].push_back(make_pair(y, c));
        E[y].push_back(make_pair(x, c));
    }
    int A, B;
    cin >> A >> B;
    bool were[N + 1][1024];
    for (int i = 0; i <= N; i++)
        for (int j = 0; j < 1024; j++)
            were[i][j] = false;
    were[A][0] = true;
    queue<int>BFS;
    BFS.push(A);
    queue<int>K;
    K.push(0);
    while (!BFS.empty())
    {
        int a = BFS.front();
        BFS.pop();
        int k = K.front();
        K.pop();
        for (pair<int, int> b : E[a])
        {
            if (!were[b.first][k | b.second])
            {
                were[b.first][k | b.second] = true;
                BFS.push(b.first);
                K.push(k | b.second);
            }
        }
    }
    for (int i = 0; i < 1024; i++)
        if (were[B][i])
        {
            cout << i;
            return 0;
        }
    cout << -1;
    return 0;
}

// another editorial approach(using dfs)
#include <bits/stdc++.h>
using namespace std;

struct Edge { int y, cost; };
int n, m, A, B;
bool viz[1001][1024];
vector<Edge> g[1001];

void dfs(int x, int cost) {
    viz[x][cost] = true;
    for (Edge &e : g[x]) {
        if (!viz[e.y][cost | e.cost]) {
            dfs(e.y, cost | e.cost);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0, x, y, c; i < m; i++) {
        cin >> x >> y >> c;
        g[x].push_back({y, c});
        g[y].push_back({x, c});
    }
    
    cin >> A >> B;
    dfs(A, 0);
    
    for (int i = 1; i < 1024; ++i) {
        if (viz[B][i]) {
            cout << i << endl;
            return 0;
        }
    }
    
    cout << -1 << endl;
    return 0;
}