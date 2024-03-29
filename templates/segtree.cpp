#include <bits/stdc++.h>
using namespace std;

constexpr inline unsigned int geq_pow2(const unsigned int x) {return x & (x - 1) ? 2u << __lg(x) : x;}

template<typename T>
class segtree {
 
    struct Node {
        T sm = 0;
        T mn1, mx1, mn2, mx2;
        T cmn1 = 0, cmx1 = 0;
        T ps_add = 0;
 
        Node() {}
 
        Node(T x) {
            sm = x;
            mn1 = mx1 = x;
            cmn1 = cmx1 = 1;
        }
    };
 
    const T inf = numeric_limits<T>::max();
    vector<Node> m;
    size_t a, U;
 
    inline constexpr int gsz(int v) {
        return 1 << (__lg(U) - __lg(v));
    }
 
    T calcmn2(Node& l, Node& r) {
        T mn1 = min(l.mn1, r.mn1);
        T mn2 = inf;
        if (l.mn1 != mn1) mn2 = min(mn2 , l.mn1);
        if (r.mn1 != mn1) mn2 = min(mn2 , r.mn1);
        if (l.mn1 != l.mx1) mn2 = min(mn2 , l.mn2);
        if (r.mn1 != r.mx1) mn2 = min(mn2 , r.mn2);
        return mn2;
    }
 
    T calcmx2(Node& l, Node& r) {
        T mx1 = max(l.mx1, r.mx1);
        T mx2 = -inf;
        if (l.mx1 != mx1) mx2 = max(mx2 , l.mx1);
        if (r.mx1 != mx1) mx2 = max(mx2 , r.mx1);
        if (l.mn1 != l.mx1) mx2 = max(mx2 , l.mx2);
        if (r.mn1 != r.mx1) mx2 = max(mx2 , r.mx2);
        return mx2;
    }
 
    bool chk(T x, T a, T b) {
        return x != a && x != b;
    }
 
    void upd(int v) {
        if (v >= U) return;
        Node &n = m[v], &l = m[v << 1], &r = m[v << 1 | 1];
        n.sm = l.sm + r.sm;
        n.mn1 = min(l.mn1, r.mn1);
        n.mx1 = max(l.mx1, r.mx1);
        n.cmn1 = (l.mn1 == n.mn1 ? l.cmn1 : 0) + (r.mn1 == n.mn1 ? r.cmn1 : 0);
        n.cmx1 = (l.mx1 == n.mx1 ? l.cmx1 : 0) + (r.mx1 == n.mx1 ? r.cmx1 : 0);
        n.mn2 = calcmn2(l, r);
        n.mx2 = calcmx2(l, r);
    }
 
    void push_mineq(Node& n, T x) {
        if (n.mx1 <= x) return;
        int fl = n.mn1 == n.mx1, fl2 = n.mn1 == n.mx2;
        n.sm -= n.cmx1 * (n.mx1 - x);
        n.mx1 = x;
        if (fl) {
            n.mn1 = x;
        } else if (fl2) {
            n.mn2 = x;
        }
    }
 
    void push_maxeq(Node& n, T x) {
        if (n.mn1 >= x) return;
        int fl = n.mn1 == n.mx1, fl2 = n.mn1 == n.mx2;
        n.sm += n.cmn1 * (x - n.mn1);
        n.mn1 = x;
        if (fl) {
            n.mx1 = x;
        } else if (fl2) {
            n.mx2 = x;
        }
    }
 
    void push_add(int v, T x) {
        Node& n = m[v];
        n.ps_add += x;
        n.mn1 += x;
        n.mx1 += x;
        n.mn2 += x;
        n.mx2 += x;
        n.sm += x * gsz(v);
    }
 
    void push(int v) {
        if (v >= U) return;
        Node &n = m[v], &l = m[v << 1], &r = m[v << 1 | 1];
        T mn = n.mn1, mx = n.mx1;
        if (n.ps_add) {
            push_add(v << 1, n.ps_add);
            push_add(v << 1 | 1, n.ps_add);
            n.ps_add = 0;
        }
        push_mineq(l, mx);
        push_mineq(r, mx);
        push_maxeq(l, mn);
        push_maxeq(r, mn);
    }
 
    void seg_add(int ql, int qr, T x, int l, int r, int v) {
        if (qr < l || r < ql) return;
        push(v);
        if (ql <= l && r <= qr) {
            push_add(v, x);
            return;
        }
        int md = (l + r) >> 1;
        seg_add(ql, qr, x, l, md, v << 1);
        seg_add(ql, qr, x, md + 1, r, v << 1 | 1);
        upd(v);
    }
 
    T seg_sum(int ql, int qr, int l, int r, int v) {
        if (qr < l || r < ql) return 0;
        push(v);
        if (ql <= l && r <= qr) return m[v].sm;
        int md = (l + r) >> 1;
        return seg_sum(ql, qr, l, md, v << 1) +
               seg_sum(ql, qr, md + 1, r, v << 1 | 1);
    }
 
    T seg_max(int ql, int qr, int l, int r, int v) {
        if (qr < l || r < ql) return -inf;
        push(v);
        if (ql <= l && r <= qr) return m[v].mx1;
        int md = (l + r) >> 1;
        return max(seg_max(ql, qr, l, md, v << 1),
                   seg_max(ql, qr, md + 1, r, v << 1 | 1));
    }
 
    T seg_min(int ql, int qr, int l, int r, int v) {
        if (qr < l || r < ql) return inf;
        push(v);
        if (ql <= l && r <= qr) return m[v].mn1;
        int md = (l + r) >> 1;
        return min(seg_min(ql, qr, l, md, v << 1),
                   seg_min(ql, qr, md + 1, r, v << 1 | 1));
    }
 
    void seg_mineq(int ql, int qr, T x, int l, int r, int v) {
        Node& n = m[v];
        if (qr < l || r < ql || x >= n.mx1) return;
        push(v);
        if (ql <= l && r <= qr && (n.mn1 == n.mx1 || x > n.mx2)) {
            push_mineq(n, x);
            return;
        }
        int md = (l + r) >> 1;
        seg_mineq(ql, qr, x, l, md, v << 1);
        seg_mineq(ql, qr, x, md + 1, r, v << 1 | 1);
        upd(v);
    }
 
    void seg_maxeq(int ql, int qr, T x, int l, int r, int v) {
        Node& n = m[v];
        if (qr < l || r < ql || x <= n.mn1) return;
        push(v);
        if (ql <= l && r <= qr && (n.mn1 == n.mx1 || x < n.mn2)) {
            push_maxeq(n, x);
            return;
        }
        int md = (l + r) >> 1;
        seg_maxeq(ql, qr, x, l, md, v << 1);
        seg_maxeq(ql, qr, x, md + 1, r, v << 1 | 1);
        upd(v);
    }
 
public:
    segtree() = default;
 
    segtree(vector<T>& n): a(n.size()), U(geq_pow2(a)) {
        m.resize(U * 2);
        for (size_t q = 0; q < a; q++) {
            m[U + q] = Node(n[q]);
        }
        for (size_t q = U; --q;) {
            upd(q);
        }
    }
 
    T seg_sum(int ql, int qr) {return seg_sum(ql, qr, 0, U - 1, 1);}
    T seg_max(int ql, int qr) {return seg_max(ql, qr, 0, U - 1, 1);}
    T seg_min(int ql, int qr) {return seg_min(ql, qr, 0, U - 1, 1);}
    void seg_add(int ql, int qr, T x) {seg_add(ql, qr, x, 0, U - 1, 1);}
    void seg_mineq(int ql, int qr, T x) {seg_mineq(ql, qr, x, 0, U - 1, 1);}
    void seg_maxeq(int ql, int qr, T x) {seg_maxeq(ql, qr, x, 0, U - 1, 1);}
    void seg_set(int ql, int qr, T x) {seg_mineq(ql, qr, x); seg_maxeq(ql, qr, x);}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        segtree <long long> seg(a);
        cout << seg.seg_sum(3, 6) << endl;
        seg.seg_add(4, 5, -3);
        cout << seg.seg_sum(3, 6) << endl;
        seg.seg_add(4, 5, 3);
        cout << seg.seg_sum(3, 6) << endl;
    }
    
    return 0;
}