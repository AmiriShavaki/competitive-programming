#include <bits/stdc++.h>
using namespace std;

#define N 100005
#define LOGN 20

int p[N], h[N], par[N][LOGN];
vector <int> G[N];

void dfs(int v, int p = -1) {
    if (p + 1) {
        h[v] = h[p] + 1;
    }
    par[v][0] = p;
    for (int i = 1; i < LOGN; i++) {
        if (par[v][i - 1] + 1) par[v][i] = par[par[v][i - 1]][i - 1];
    }
    for (int i = 0; i < G[v].size(); i++) 
        if (p != G[v][i]) dfs(G[v][i], v);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    p[0] = -1;
    for (int i = 1; i <= n - 1; i++) {
        cin >> p[i]; p[i]--;
        G[p[i]].push_back(i);
        G[i].push_back(p[i]);
    }

    for (int i = 0; i < N; i++) for (int j = 0; j < LOGN; j++) par[i][j] = -1;
    dfs(0); // preprocess h[v] and par[v][i]

    for (int i = 0; i < q; i++) {
        int v, u; cin >> v >> u; v--; u--;
        
        if (h[v] < h[u]) swap(v, u);
        for (int i = LOGN - 1; i >= 0; i--) {
            if (par[v][i] + 1 && h[par[v][i]] >= h[u]) v = par[v][i];
        }
        if (u == v) {
            cout << u + 1 << endl; continue;
        }
        for (int i = LOGN - 1; i >= 0; i--) {
            if (par[v][i] != par[u][i]) {
                v = par[v][i]; 
                u = par[u][i];
            }
        }
        cout << par[v][0] + 1 << endl;
    }
    return 0;
}