#include <bits/stdc++.h>
using namespace std;

#define N 100005
#define LOGN 20

vector <int> G[N];
bool visited[N], visited2[N], visitedp[N];
int h[N], par[N][LOGN];
string ans = "Yes";
stack <int> order;

void dfs(int v) {
    visited[v] = true;
    for (int i = 0; i < G[v].size(); i++) {
        if (!visited[G[v][i]]) {
            dfs(G[v][i]);
        }
    }
    order.push(v);
}

void dfs_preproc(int v, int p = -1) {
    visitedp[v] = true;
    par[v][0] = p;
    if (p + 1) {
        h[v] = h[p] + 1;
    }
    for (int i = 1; i < LOGN; i++) {
        if (par[v][i - 1] + 1) par[v][i] = par[par[v][i - 1]][i - 1];
    }

    for (int i = 0; i < G[v].size(); i++) {
        int u = G[v][i];
        if (!visitedp[u]) {
            dfs_preproc(u, v);
        }
    }
}

void check(int v, int u) {
    bool flg = false;
    if (h[v] < h[u]) { // original v is in higher layers
        ans = "No"; // it is forward or cross edge no matter both case makes two path
        return;
    }
    // v is in lower levels (further to the root)
    for (int i = LOGN - 1; i >= 0; i--) {
        // cout << "Debug i:" << i << " u:" << u << " v:" << v << " par: " << par[v][i] << endl;
        if (par[v][i] + 1 && h[par[v][i]] >= h[u]) v = par[v][i];
    }
    if (v == u) return; // back edge
    ans = "No"; // cross edge
}

void dfs2(int v) {
    visited2[v] = true;
    for (int i = 0; i < G[v].size(); i++) {
        int u = G[v][i];
        if (visited2[u]) { // forward / cross / back
            check(v, u);
        } else {
            dfs2(u); // tree edge
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to; cin >> from >> to; from--; to--;
        G[from].push_back(to);
    }
    
    // Obtain topological order
    for (int i = 0; i < n; i++) {
        if (!visited[i]) dfs(i);
    }

    // fill par
    for (int i = 0; i < N; i++) for (int j = 0; j < LOGN; j++) par[i][j] = -1;

    // Obtain h[i] & par[v][i]
    stack <int> order2 = order; 
    for (int top; !order2.empty(); order2.pop()) {
        top = order2.top();
        if (!visitedp[top]) dfs_preproc(top);
    }

    // final dfs (looking for forward and cross edges)
    for (int top; !order.empty(); order.pop()) {
        top = order.top();
        if (!visited2[top]) {
            dfs2(top);
        }
    }

    cout << ans;
    return 0;
}