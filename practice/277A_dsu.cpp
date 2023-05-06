#include <bits/stdc++.h>
using namespace std;

#define N 102

int par[N], rnk[N], a[N];
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

    for (int i = 1; i < m+1; i++) {
        par[i] = i;
        rnk[i] = 1;
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int k; cin >> k; ans += 0 == k;
        for (int j = 0; j < k; j++) {
            cin >> a[j];
            mark[a[j]] = true;
            for (int t = j - 1; t >= 0; t--) connect(a[j], a[t]);
        }
    }

    unordered_set <int> roots;

    for (int i = 1; i < m + 1; i++) {
        if (mark[i]) {
            roots.insert(root(i));
            // cout << i << ' ' << root(i) << endl;
        }
    }

    // for (auto& pr : roots) {
    //     cout << pr << endl;
    // }

    // cout << "DEBUG " << roots.size() - 1 << endl;

    // cout << "DEBUG " << ans << endl;

    cout << ans + max(0, (int)roots.size() - 1);

    return 0;
}