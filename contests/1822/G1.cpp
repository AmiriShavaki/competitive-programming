#include <bits/stdc++.h>
using namespace std;

#define B 1003
#define A 1000006
#define N 200005
#define int long long

int a[N], cnt[A];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        int ans = 0;

        for (int i = 0; i < n; i++) { // In case of b = 1 for a fixed a[i]
            ans += (cnt[a[i]] - 1) * (cnt[a[i]] - 2);
        }

        for (int i = 0; i < n; i++) {
            for (int b = 2; b * b * a[i] < A; b++) {
                ans += cnt[a[i] * b] * cnt[a[i] * b * b];
            }
        }
        cout << ans << endl;

        for (int i = 0; i < n; i++) {
            cnt[a[i]]--;
        }
    }
    return 0;
}