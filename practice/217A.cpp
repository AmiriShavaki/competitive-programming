#include <bits/stdc++.h>
using namespace std;

#define N 102
#define PNT 1003

vector <int> xp[PNT], yp[PNT], G[N];
bool visited[N];

void dfs(int v) {
    visited[v] = true;
    for (int i = 0; i < G[v].size(); i++) {
        if (!visited[G[v][i]]) dfs(G[v][i]);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;

        for (int j = 0; j < xp[x].size(); j++) {
            int v = xp[x][j];
            G[v].push_back(i);
            G[i].push_back(v);
        }
        for (int j = 0; j < yp[y].size(); j++) {
            int v = yp[y][j];
            G[v].push_back(i);
            G[i].push_back(v);
        }

        xp[x].push_back(i);
        yp[y].push_back(i);
    }

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            cnt++;
        }
    }

    cout << cnt - 1;
    return 0;
}