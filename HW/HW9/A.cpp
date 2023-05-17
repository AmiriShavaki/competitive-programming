#include <bits/stdc++.h>
using namespace std;

#define N 250005
#define int long long
#define INF numeric_limits<int>::max()

int par[N], indices[N], rnk[N];
pair <int, pair <int, int>> edges[N];
bool mark[N];

int root(int v) {
    if (par[v] == v) return v;
    return par[v] = root(par[v]);
}

void connect(int v, int u) {
    int rv = root(v), ru = root(u);
    if (rv == ru) return;
    if (rnk[rv] > rnk[ru]) par[ru] = rv;
    else if (rnk[ru] > rnk[rv]) par[rv] = ru;
    else {
        par[rv] = ru;
        rnk[ru]++;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    int edge_ind = 0;
    for (int i = 0; i < m; i++) {
        int v, u, w; cin >> v >> u >> w; v--; u--;
        edges[edge_ind++] = make_pair(w, make_pair(v, u));
    }

    for (int i = 0; i < m; i++) indices[i] = i;
    sort(indices, indices + m,
        [&](int ind1, int ind2) -> bool {
            return edges[ind1].first < edges[ind2].first;
        }    
    );

    for (int i = 0; i < n; i++) par[i] = i;

    vector <int> mst;
    int mst_val = 0;
    for (int i = 0; i < m; i++) {
        int ind = indices[i];
        int v = edges[ind].second.first, u = edges[ind].second.second;
        if (root(v) != root(u)) {
            connect(v, u);
            mst.push_back(ind);
            mst_val += edges[ind].first;
            mark[ind] = true;
        }
    }

    if (mst.size() != n - 1) {
        cout << "-1\n"; return 0;
    }
    // for (int i = 0; i < n - 1; i++) cout << mst[i] << " \n"[i == n - 2];

    int res = INF;
    for (int del_ind = 0; del_ind < n - 1; del_ind++) {
        int del_e = mst[del_ind];
        int del_w = edges[del_e].first;
        int cur_val = mst_val - del_w;

        // construct dsu
        for (int i = 0; i < n; i++) { par[i] = i; rnk[i] = 0; }
        for (int i = 0; i < n - 1; i++) {
            if (i == del_ind) continue;
            int e = mst[i];
            connect(edges[e].second.first, edges[e].second.second);
        }
        
        // find new mst
        for (int i = 0; i < m; i++) {
            int e = indices[i];
            if (mark[e]) continue;
            int v = edges[e].second.first, u = edges[e].second.second, w = edges[e].first;
            if (root(v) != root(u)) {
                if (cur_val + w < res) res = cur_val + w;
            }
        }
    }
    cout << (res != INF ? res : -1) << endl;
    return 0;
}