#include <bits/stdc++.h>
using namespace std;

#define N 200005
#define K 100005
#define int long long

int a[N], l[K][2], r[K][2], dp[K][2]; // [0] is delete min pair   [1] is delete max

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int n, k; cin >> n >> k;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i]; sum += a[i];
        }
        sort(a, a + n);
        dp[0][0] = sum - a[0] - a[1]; l[0][0] = 2; r[0][0] = n - 1;
        dp[0][1] = sum - a[n - 1]; l[0][1] = 0; r[0][1] = n - 2;
        for (int i = 1; i < k; i++) {
            int l0 = l[i - 1][0], l1 = l[i - 1][1], r0 = r[i - 1][0], r1 = r[i - 1][1];
            if (dp[i - 1][0] - a[l0] - a[l0 + 1] > dp[i - 1][1] - a[l1] - a[l1 + 1]) {
                dp[i][0] = dp[i - 1][0] - a[l0] - a[l0 + 1];
                l[i][0] = l0 + 2;
                r[i][0] = r0;
            } else {
                dp[i][0] = dp[i - 1][1] - a[l1] - a[l1 + 1];
                l[i][0] = l1 + 2;
                r[i][0] = r1;                
            }
            if (dp[i - 1][0] - a[r0] > dp[i - 1][1] - a[r1]) {
                dp[i][1] = dp[i - 1][0] - a[r0];
                l[i][1] = l0;
                r[i][1] = r0 - 1;
            } else {
                dp[i][1] = dp[i - 1][1] - a[r1];
                l[i][1] = l1;
                r[i][1] = r1 - 1;
            }
        }
        // cout << "DEBUG " << dp[0][0] << ' ' <<  dp[0][1] << endl;
        // cout << "DEBUG " << dp[1][0] << ' ' <<  dp[1][1] << endl;
        cout << max(dp[k - 1][0], dp[k - 1][1]) << endl;
    }
    return 0;
}