#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << 1 << endl; continue;
        }
        if (n * (n + 1) / 2 % n == 0) {
            cout << -1 << endl; continue;
        }
        for (int i =0; i < n; i++) {
            if (i % 2) cout << i;
            else cout << i + 2;
            if (i < n - 1) cout << ' ';
            else cout << '\n';
        }
    }
    return 0;
}