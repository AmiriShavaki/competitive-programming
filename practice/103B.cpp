#include <bits/stdc++.h>
using namespace std;

#define N 102

vector <int> G[N];
bool visited[N];

void dfs(int v) {
    visited[v] = true;
    for (int i = 0; i < G[v].size(); i++) {
        if (!visited[G[v][i]]) {
            dfs(G[v][i]);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int v, u; cin >> v >> u; v--; u--;
        G[v].push_back(u);
        G[u].push_back(v);
    }

    dfs(0);
    for (int i = 1; i < n; i++) {
        if (!visited[i]) {
            cout << "NO"; return 0;
        }
    }
    cout << (n == m ? "FHTAGN!" : "NO");
 
    return 0;
}