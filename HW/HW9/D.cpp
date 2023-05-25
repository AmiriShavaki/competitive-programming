#include <bits/stdc++.h>
using namespace std;

#define N 50004

vector <int> G[N], W[N];
int a[N], mark[N];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, t, k; cin >> n >> m >> t >> k;
    for (int i = 0; i < m; i++) {
        int v, u, w; cin >> v >> u >> w; v--; u--;
        G[v].push_back(u);
        G[u].push_back(v);
        W[v].push_back(w);
        W[u].push_back(w);
    }
    int cnt = n;
    for (int i = 0; i < t; i++) {
        cin >> a[i]; a[i]--;
        cnt -= mark[a[i]] == 0;
        mark[a[i]] = k;
        queue < pair<int, int> > q; q.push(make_pair(a[i], k));
        while (!q.empty()) {
            int front = q.front().first, cost = q.front().second; q.pop();
            for (int i = 0; i < G[front].size(); i++) {
                int neighbor = G[front][i], weight = W[front][i];
                int new_cost = cost - weight;
                if (new_cost > 0 && mark[neighbor] < new_cost) {
                    cnt -= mark[neighbor] == 0;
                    mark[neighbor] = new_cost;
                    q.push(make_pair(neighbor, new_cost));
                }
            }
        }
        // cout << "DEBUG ";
        // for (int i = 0; i < n; i++) cout << mark[i] << " ";
        cout << cnt << endl;
    }
    return 0;
}