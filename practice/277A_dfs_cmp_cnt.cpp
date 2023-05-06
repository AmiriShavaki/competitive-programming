#include <bits/stdc++.h>
using namespace std;

#define N 102

int a[N], k[N];
bool visited[N * 2];
vector <int> G[N * 2];

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

    int ans = 0;

    for (int i = 0; i < n; i++) {
        cin >> k[i]; ans += k[i] == 0;
        for (int j = 0; j < k[i]; j++) {
            cin >> a[j];
            G[i].push_back(a[j] + n);
            G[a[j] + n].push_back(i);
        }
    }

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && k[i]) {
            dfs(i);
            cnt++;
        }
    }
    //cout << "DEBUG " << cnt << ' ' << ans << endl;
    cout << ans + max(0, cnt - 1);

    return 0;
}