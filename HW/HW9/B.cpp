#include <bits/stdc++.h>
using namespace std;

#define N 200005

int par[N], rnk[N], r[N];

int root_r(int v) {
    if (r[v] == v) return v;
    return r[v] = root_r(r[v]);
}

void connect_r(int v, int u) {
    int rv = root_r(v), ru = root_r(u);
    if (rv == ru) return;
    if (rv > ru) r[ru] = rv;
    else r[rv] = ru;
}

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

    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) { par[i] = i; r[i] = i; }

    for (int T = 0; T < q; T++) {
        int op, x, y; cin >> op >> x >> y; x--; y--;
        if (op == 1) {
            connect(x, y);
        } else if (op == 2) {
            int l = x;
            while (l < y) {
                int next_l = root_r(l) + 1;
                connect_r(l, y);
                connect(l, y);
                l = next_l;
            }
        } else if (op == 3) {
            if (root(x) == root(y)) cout << "YES\n";
            else cout << "NO\n";
        }
        // for (int i = 0; i < n; i++) cout << par[i] << " \n"[i == n - 1];
        // for (int i = 0; i < n; i++) cout << r[i] << " \n"[i == n - 1];
    }
    return 0;
}