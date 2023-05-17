#include <bits/stdc++.h>
using namespace std;

#define N 1003
#define int long long

int a[N], k[N], backup[N];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) backup[i] = a[i];

    for (int T = 0; T < q; T++) {
        for (int i = 0; i < n; i++) a[i] = backup[i];
        int k; cin >> k;

        if (k <= n) {
            for (int i = k, j = 0; i >= 1; i--, j++) {
                a[j] += i;
            }
            int ans = a[0]; for (int i = 1; i < n; i++) ans = min(ans, a[i]);
            cout << ans;
        } else {
            int minus_cnt;
            if ((k - n) % 2 == 0) {
                for (int i = k, j = 0; i >= 1 && j < n; i--, j++) {
                    a[j] += i;
                }
                minus_cnt = (k - n) / 2;
            } else {
                for (int i = k, j = 0; i >= 1 && j < n - 1; i--, j++) {
                    a[j] += i;
                }
                minus_cnt = (k - n + 1) / 2;
            }
            int mi = a[0]; for (int i = 1; i < n; i++) mi = min(mi, a[i]);
            int overmi_sum = 0; for (int i = 0; i < n; i++) overmi_sum += a[i] - mi;
            if (overmi_sum >= minus_cnt) cout << mi;
            else cout << mi - (minus_cnt - overmi_sum) / n - ((minus_cnt - overmi_sum) % n > 0);
        }
        cout << " \n"[T == q - 1];
    }
    return 0;
}