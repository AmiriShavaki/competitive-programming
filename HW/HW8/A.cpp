#include <bits/stdc++.h>
using namespace std;

#define N 100005

vector <int> G[N], GR[N];
int finish_time[N], t = 1, vertices_order[N];
bool visited[N], visited2[N];

void dfs(int v, vector <int>* g, bool* vis, int* f_t = NULL) {
    vis[v] = true;
    for (int i = 0; i < g[v].size(); i++) {
        int u = g[v][i];
        if (!vis[u]) dfs(u, g, vis, f_t);
    }
    if (f_t)
        f_t[v] = t++;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to; cin >> from >> to; from--; to--;
        G[from].push_back(to);
        GR[to].push_back(from);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) dfs(i, GR, visited, finish_time);
    }

    for (int i = 0; i < n; i++) vertices_order[i] = i;
    sort(vertices_order, vertices_order + n, 
        [&](int ind1, int ind2) -> bool {
            return finish_time[ind1] > finish_time[ind2];
        }
    );

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!visited2[vertices_order[i]]) {
            ans++;
            dfs(vertices_order[i], G, visited2);
        }
    }
    cout << ans;
    return 0;
}