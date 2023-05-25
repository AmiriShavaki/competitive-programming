#include <bits/stdc++.h>
using namespace std;

#define N 1000006
#define int long long

int a[N], nodes[4*N], n, min_pref[4*N], min_suff[4*N], res[4*N];

void build(int l, int r, int id) {
    if (r == l) {
        if (l < n) {
            nodes[id] = a[l];
            if (a[l] < 0) {
                min_pref[id] = a[l];
                min_suff[id] = a[l];
                res[id] = a[l];
            }
        }
    } else {
        int mid = (l+r) / 2;
        build(l, mid, id<<1);
        build(mid+1, r, id<<1|1);
        nodes[id] = nodes[id<<1] + nodes[id<<1|1];
        res[id] = min(res[id<<1], min(res[id<<1|1], min_pref[id<<1|1] + min_suff[id<<1]));
        min_pref[id] = min(min_pref[id<<1], nodes[id<<1] + min_pref[id<<1|1]);
        min_suff[id] = min(min_suff[id<<1|1], min_suff[id<<1] + nodes[id<<1|1]);
    }
}

void modify(int i, int x, int l, int r, int id) {
    if (l == r) {
        a[i] = x;
        nodes[id] = a[i];
        res[id] = min(0LL, a[i]);
        min_pref[id] = res[id];
        min_suff[id] = res[id];
        return;
    }
    int mid = (l+r) / 2;
    if (i <= mid) {
        modify(i, x, l, mid, id<<1);
    } else {
        modify(i, x, mid+1, r, id<<1|1);
    }
    // TODO: Update pref, suf and res
    nodes[id] = nodes[id<<1] + nodes[id<<1|1];
    min_suff[id] = min(min_suff[id<<1|1], min_suff[id<<1]+nodes[id<<1|1]);
    min_pref[id] = min(min_pref[id<<1], nodes[id<<1]+min_pref[id<<1|1]);
    res[id] = min(res[id<<1], min(res[id<<1|1], min_pref[id<<1|1] + min_suff[id<<1]));
}

// int sum(int ql, int qr, int l, int r, int id) {
//     if (ql > r || qr < l)
//         return 0;
//     else if (ql <= l && qr >= r)
//         return nodes[id];
//     int mid = (l + r) / 2;
//     return sum(ql, qr, l, mid, id<<1) + sum(ql, qr, mid+1, r, id<<1|1);
// }

struct query_node {
    int suff;
    int pref;
    int res;
    int sum;
};

query_node query(int ql, int qr, int l, int r, int id) {
    query_node qn, qn2, qn_ans;
    if (ql > r || qr < l) {
        qn.suff = 0; qn.pref = 0; qn.res = 0; qn.sum = 0; return qn;
    }
    else if (ql <= l && qr >= r) {
        qn.suff = min_suff[id]; qn.pref = min_pref[id]; qn.res = res[id]; qn.sum = nodes[id]; return qn;
    }
    int mid = (l + r) / 2;
    // Combine answers
    qn = query(ql, qr, l, mid, id<<1);
    qn2 = query(ql, qr, mid+1, r, id<<1|1);
    qn_ans.sum = qn.sum + qn2.sum;
    qn_ans.suff = min(qn2.suff, qn2.sum + qn.suff);
    qn_ans.pref = min(qn.pref, qn.sum + qn2.pref);
    qn_ans.res = min(qn.res, min(qn2.res, qn2.pref + qn.suff));
    return qn_ans;
}

void print_tree(int nodes_cnt) {
    for (int i = 1; i <= nodes_cnt; i++) {
        cout << endl;
        cout << "node_id: " << i << endl;
        cout << "nodes[i]: " << nodes[i] << endl;
        cout << "res[i]: " << res[i] << endl;
        cout << "pref[i]: " << min_pref[i] << endl;
        cout << "suff[i]: " << min_suff[i] << endl;
        cout << endl;
    }
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
            cout << query(l, r, 0, min_greater_pow2-1, 1).res << endl;
        } else { // Modify a[i] = x
            int i, x; cin >> i >> x; i--;
            modify(i, x, 0, min_greater_pow2-1, 1);
            //print_tree(15);
        }
    }
    
    return 0;
}