#include <bits/stdc++.h>
using namespace std;

#define N 400005
#define int long long
int a[N];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 0; i < 2 * n; i++) {
            cin >> a[i];
            ans += abs(a[i]);
        }
        if (n == 1) {
            cout << abs(a[0] - a[1]) << endl;
            continue;
        }
        if (n == 2) {
            ans = min(ans, abs(2 - a[0]) + abs(2 - a[1]) + abs(2 - a[2]) + abs(2 - a[3]));
        }
        if (n % 2 == 0) {
            int min_dist = numeric_limits<long long>::max();
            int res = 0;
            for (int i = 0; i < n * 2; i++) res += abs(a[i] + 1);
            for (int i = 0; i < n * 2; i++) {
                min_dist = min(min_dist, res - abs(a[i] + 1) + abs(a[i] - n));
            }
            ans = min(ans, min_dist);
        }
        cout << ans << endl;
    }
    return 0;
}