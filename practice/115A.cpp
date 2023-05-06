#include <bits/stdc++.h>
using namespace std;

#define N 2003
int depth[N], par[N];

int go(int i) {
    if (depth[i] != -1) return depth[i];
    return go(par[i]) + 1;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> par[i];
        if (par[i] + 1) par[i]--;
        depth[i] = par[i] == -1 ? 1 : -1;
    }

    int ans = 1;

    for (int i = 0; i < n; i++) {
        if (depth[i] == -1) depth[i] = go(i);
        ans = max(ans, depth[i]);
    }

    cout << ans;
    return 0;
}