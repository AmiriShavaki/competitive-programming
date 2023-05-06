#include <bits/stdc++.h>
using namespace std;

int lst_prm(int x) {
    for (int div = 2; div * div <= x; div++) {
        if (x % div == 0) return div;
    }
    return x;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--) {
        int n, m;
        cin >> n >> m;
        string ans;
        if (m == 1 || n == 1) {
            ans = "YES\n";
        } else if (lst_prm(n) <= m) {
            ans = "NO\n";
        } else {
            ans = "YES\n";
        }
        cout << ans;
    }
    return 0;
}