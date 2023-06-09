#include <bits/stdc++.h>

using namespace std;

#define N 1000006
#define int long long

int val[N], ans[N], indices[N], dsu[N];
pair < int, pair<int,int> > edges[N];

int root(int v) {
    if (dsu[v] == v) return v;
    return dsu[v] = root(dsu[v]);
}

void connect(int v, int u) {
    int rv = root(v), ru = root(u);
    val[ru] = (val[rv]/2 + 1)*(val[ru]/2 + 1) * 2;
    dsu[rv] = ru;
}

int32_t main() {
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int v, u, f; cin >> v >> u >> f; v--; u--;
        edges[i] = make_pair(f, make_pair(v, u));
        indices[i] = i;
        dsu[i] = i;
    } dsu[n - 1] = n - 1;
    sort(indices, indices + n - 1,
        [&](int ind1, int ind2) -> bool {
            return edges[ind1].first < edges[ind2].first;
        }
    );
    for (int i = 0; i < n - 1; i++) {
        int e = indices[i];
        int v = edges[e].second.first;
        int u = edges[e].second.second;
        connect(v, u);
        ans[e] = val[root(u)];
    }
    for (int i = 0; i < n - 1; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}