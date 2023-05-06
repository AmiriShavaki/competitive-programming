#include <bits/stdc++.h>
using namespace std;

#define N 100005

unordered_set <int> G[N];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--; v--;
        G[u].insert(v);
        G[v].insert(u);
    }
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int u, v; cin >> u >> v; u--; v--;
        if (G[u].find(v) != G[u].end()) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}