#include <bits/stdc++.h>
using namespace std;

#define N 200005

vector <int> G[N];
int depth1[N], depth2[N];

int furthest(int root, int* depth) {
    queue <int> q; q.push(root); depth[root] = 0;
    queue <int> par; par.push(-1);
    int top;
    while(!q.empty()) {
        top = q.front(); q.pop();
        for (int i = 0; i < G[top].size(); i++) {
            if (G[top][i] != par.front()) {
                depth[G[top][i]] = depth[top] + 1;
                q.push(G[top][i]);
                par.push(top);
                // cout << G[top][i] << ' ' << top << endl;
            }
        }
        par.pop();
    }
    return top;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int v, u; cin >> v >> u; u--; v--;
        G[v].push_back(u);
        G[u].push_back(v);
    }

    cout << depth2[furthest(furthest(0, depth1), depth2)];
    return 0;
}