#include <bits/stdc++.h>
using namespace std;

#define N 100005

int h[N], h2[N];
bool visited[N];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int n, m, s, t;
        cin >> n >> m >> s >> t; s--; t--;
        vector < vector<int> > G(n);
        for (int i = 0; i < m; i++) {
            int from, to; cin >> from >> to; from--; to--;
            G[from].push_back(to);
        }

        // fill(visited, visited + n, 0);
        // //bfs1
        // queue<int> q1; q1.push(s); visited[s] = true; h[s] = 0;
        // while (!q1.empty()) {
        //     int top = q1.front(); q1.pop();
        //     for (int i = 0; i < G[top].size(); i++) {
        //         int u = G[top][i];
        //         if (!visited[u]) {
        //             visited[u] = true;
        //             q1.push(u);
        //             h[u] = h[top] + 1;
        //         }
        //     }
        // }

        fill(visited, visited + n, 0);
        //bfs2
        queue<int> q2; q2.push(t); visited[t] = true; h2[t] = 0; h2[s] = 0;
        while (!q2.empty()) {
            int top = q2.front(); q2.pop();
            for (int i = 0; i < G[top].size(); i++) {
                int u = G[top][i];
                if (!visited[u]) {
                    visited[u] = true;
                    q2.push(u);
                    h2[u] = h2[top] + 1;
                }
            }
        }
        // cout << "DEBUG " << h2[s] << ' ' << h[t] << endl;
        cout << (!h2[s] ? -1 : h2[s]) << endl;
    }
    return 0;
}