#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, x, p;
        cin >> n >> x >> p;
        string res = "No\n";
        for (int i = 1; i < min(2 * n + 2, p + 1); i++) {
            if ((i * (i + 1) / 2) % n == (n - x) % n) {
                res = "Yes\n";
                break;
            }
        }
        cout << res;
    }
    return 0;
}