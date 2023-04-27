#include <bits/stdc++.h>

using namespace std;

#define N 18
#define K 18 * 18
#define int long long

int a[N];
int dp[1 << N][N];
int joybefore[N][N];

int32_t main() {
    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    int x, y, c;
    for (int i = 0; i < k; i++) {
        cin >> x >> y >> c; x--; y--;
        joybefore[y][x] = c; // if he eats x before y then he gets c
    }

    int ans = 0;
    for (int i = (1 << n) - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                for (int t = 0; t < n; t++) {
                    int new_val = (i < (1 << n) - 1 ? joybefore[j][t] : 0) + dp[i][t] + a[j];
                    dp[i & ~(1 << j)][j] = max(dp[i & ~(1 << j)][j], new_val);
                    if (__builtin_popcount(i & ~(1 << j)) == n - m) {
                        ans = max(ans, dp[i & ~(1 << j)][j]);
                        //cout << (i & ~(1 << j)) << ' ' << ans << endl;
                    }
                }
            }
        }
    }

    // for (int i = 0; i < 16; i++) {
    //     for (int j = 0; j < 4; j++) {
    //         cout << dp[i][j] << " \n"[j == 4-1];
    //     }
    // }

    cout << ans;
    
    return 0;
}