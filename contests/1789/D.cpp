#include <bits/stdc++.h>
using namespace std;

#define N 2003

bitset <N> a,b;
int n;
vector <int> res;

void rsh(int sh_n) {
    a ^= a >> sh_n;
    res.push_back(-sh_n);
}

void lsh(int sh_n) {
    a ^= a << sh_n;
    res.push_back(sh_n);
}

int hb(bitset <N>& num) {
    int i;
    for (i = n - 1; i >= 0 && num[i] != 1; i--) {;}
    return i;
}

int lb(bitset <N>& num) {
    int i;
    for (i = 0; num[i] != 1; i++) {
        if (i == n) return -1;
    }
    return i;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; 
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> a >> b;

        int lb_b = lb(b), hb_a = hb(a);

        if (lb_b == -1 && hb_a == -1) {
            cout << "0\n";
            continue;
        }
        if (lb_b == -1 || hb_a == -1) {
            cout << "-1\n";
            continue;
        }

        res.clear();

        if (hb_a < lb_b) {
            lsh(lb_b - hb_a);
            hb_a = lb_b;
        }
        for (int i = lb_b; i >= 0; i--) {
            if (a[i] != b[i]) rsh(hb_a - i);
        }
        int lb_a = lb_b;
        for (int i = lb_b + 1; i < n; i++) {
            if (a[i] != b[i]) lsh(i - lb_a);
        }

        cout << res.size() << endl;
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " \n"[i == res.size() - 1];
        }
    }
    return 0;
}