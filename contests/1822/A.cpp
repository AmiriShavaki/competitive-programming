#include <bits/stdc++.h>
using namespace std;

#define N 51

int a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--) {
        int n, t;
        cin >> n >> t;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        int ans = -1, max_val = -1;
        for (int i = 0; i < n; i++) {
            if (i + a[i] <= t && max_val < b[i]) {
                ans = i + 1;
                max_val = b[i];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}