#include <bits/stdc++.h>
using namespace std;

#define N 1000006
#define int long long

int a[N], nodes[4*N], n;

void build(int l, int r, int id) {
    if (r == l) {
        nodes[id] = l < n ? a[l] : 0;
    } else {
        int mid = (l+r) / 2;
        build(l, mid, id<<1);
        build(mid+1, r, id<<1|1);
        nodes[id] = nodes[id<<1] + nodes[id<<1|1];
    }
}

void modify(int i, int x, int l, int r, int id) {
    nodes[id] = nodes[id] - a[i] + x;
    if (l == r) {
        a[i] = x;
        return;
    }
    int mid = (l+r) / 2;
    if (i <= mid) {
        modify(i, x, l, mid, id<<1);
    } else {
        modify(i, x, mid+1, r, id<<1|1);
    }
}

int sum(int ql, int qr, int l, int r, int id) {
    if (ql > r || qr < l)
        return 0;
    else if (ql <= l && qr >= r)
        return nodes[id];
    int mid = (l + r) / 2;
    return sum(ql, qr, l, mid, id<<1) + sum(ql, qr, mid+1, r, id<<1|1);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q; cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int min_greater_pow2 = n & (n - 1) ? 2ull << __lg(n) : n;
    // cout << min_greater_pow2 << endl;

    build(0, min_greater_pow2-1, 1);
    // for (int i = 1; i <= min_greater_pow2 * 2; i++) {
    //     cout << nodes[i] << endl;
    // }

    for (int _ = 0; _ < q; _++) {
        int op; cin >> op;
        if (op == 1) { // Get sum
            int l, r; cin >> l >> r; l--; r--;
            cout << sum(l, r, 0, min_greater_pow2-1, 1) << endl;
        } else { // Modify a[i] = x
            int i, x; cin >> i >> x; i--;
            modify(i, x, 0, min_greater_pow2-1, 1);
        }
    }
    return 0;
}