#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        bool flg = false, flg2 = false, flg3 = false;
        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            if (l == r && l == k) {
                flg = true;
            } else if (l == k) {
                flg2 = true;
            } else if (r == k) {
                flg3 = true;
            }
        }
        cout << (flg || flg2 && flg3 ? "YES\n" : "NO\n");
    }

    return 0;
}