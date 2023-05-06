#include <bits/stdc++.h>
using namespace std;

#define N 100005

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
    for (int i= 0; i < m; i++) {
        int u, v; cin >> v >> u; u--; v--;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    int oddcnt = 0;
    for (int i = 0; i < n; i++) {
        oddcnt += G[i].size() % 2;
    }
    
    for (int i = 0; i < n; i++) {
        if (G[i].size()) {
            dfs(i); 
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (G[i].size() && !visited[i]) {
            cout << "NO";
            return 0;
        }
    }

    cout << (oddcnt <= 2 ? "YES" : "NO");
    return 0;
}