#include <bits/stdc++.h>
using namespace std;

#define N 100005

vector <int> G[N];
bool vis1[N], vis2[N];
int depth1[N], depth2[N], max_depth[N], cnt[N], suf_sum[N];

int furthest(int v, int* depth, bool* visited) {
    queue <int> q; q.push(v); visited[v] = true; depth[v] = 0;
    int top;
    while(!q.empty()) {
        top = q.front(); q.pop();
        for (int i = 0; i < G[top].size(); i++) {
            if (!visited[G[top][i]]) {
                visited[G[top][i]] = true;
                depth[G[top][i]] = depth[top] + 1;
                q.push(G[top][i]);
            }
        }
    }
    return top;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> v >> u; v--; u--;
        G[v].push_back(u);
        G[u].push_back(v);
    }

    int head1 = furthest(0, depth1, vis1);
    memset(vis1, 0, sizeof(vis1));
    int head2 = furthest(head1, depth1, vis1);
    furthest(head2, depth2, vis2);

    for (int i = 0; i < n; i++) {
        max_depth[i] = max(depth1[i], depth2[i]);
        cnt[max_depth[i]]++;
    }

    // cout << "DEBUGGGGG " << head1 << ' ' << head2 << endl;
    // for (int i = 0; i < n; i++) cout << "DEBUG " << max_depth[i] << endl;

    suf_sum[n] = 0;
    for (int i = n - 1; i >= 1; i--) {
        suf_sum[i] = suf_sum[i + 1] + cnt[i];
    }

    for (int i = 1; i <= n; i++) {
        cout << min(n - suf_sum[i] + 1, n) << " \n"[n == i];
    }

    return 0;
}