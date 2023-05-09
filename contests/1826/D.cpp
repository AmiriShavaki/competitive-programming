#include <bits/stdc++.h>
using namespace std;

#define N 100005
#define int long long

int b[N], pref[N], suff[N];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        pref[0] = b[0] + 1;
        for (int i = 1; i < n; i++) pref[i] = max(pref[i - 1], b[i] + i + 1);

        suff[n - 1] = b[n - 1] - n;
        for (int i = n - 2; i >= 0; i--) suff[i] = max(suff[i + 1], b[i] - i - 1);

        int ans = -1;
        for (int i = 1; i < n - 1; i++) {
            ans = max(ans, suff[i + 1] + pref[i - 1] + b[i]);
            // cout << b[i] << ' ' << pref[i - 1] << ' ' << suff[i + 1] << endl;
        }
        cout << ans << endl;
    }
    return 0;
}