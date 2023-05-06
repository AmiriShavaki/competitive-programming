#include <bits/stdc++.h>
using namespace std;

#define N 4003
#define INF numeric_limits<int>::max()

bool visited[N], visited_edge[N][N], adj_mat[N][N];
int ans = INF, n;
vector <int> G[N];

inline int recog_sum(int v1, int v2, int v3) {
    return G[v1].size() + G[v2].size() + G[v3].size() - 6;
}

void dfs(int v) {
    visited[v] = true;
    for (int i = 0; i < G[v].size(); i++) {
        if (!visited_edge[G[v][i]][v]) {
            visited_edge[G[v][i]][v] = true;

            for (int j = 0; j < n; j++) {
                if (j == v || j == G[v][i]) continue;
                if (adj_mat[j][v] && adj_mat[j][G[v][i]]) ans = min(ans, recog_sum(j, v, G[v][i]));
            }

            dfs(G[v][i]);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
        adj_mat[a][b] = true;
        adj_mat[b][a] = true;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    cout << (ans != INF ? ans : -1);
    return 0;
}