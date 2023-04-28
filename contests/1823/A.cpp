#include <bits/stdc++.h>
using namespace std;

inline int f(int x, int y) {
    return x * (x - 1) / 2 + y * (y - 1) / 2;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--) {
        int n, k;
        cin >> n >> k;
        int x = n, y = 0;
        string ans = "NO";
        for (;x >= 0; x--, y++) {
            if (f(x, y) == k) {
                ans = "YES";
                break;
            }
        }
        cout << ans << endl;
        if (ans == "YES") {
            for (int i = 0; i < x; i++) {
                cout << "1";
                if (i != x - 1) cout << ' ';
            }
            if (x && y) cout << ' ';
            for (int j = 0; j < y; j++) {
                cout << "-1" << ' ';
                if (j != y - 1) cout << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}