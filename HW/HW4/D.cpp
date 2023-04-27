#include <bits/stdc++.h>

using namespace std;

#define int long long
#define K 102

int a[K], dp[K][K], pref_sum[K];

int sum(int s, int e) {
    if (s == 0) return pref_sum[e];
    return pref_sum[e] - pref_sum[s - 1];
}

int32_t main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        pref_sum[i] = i > 0 ? pref_sum[i - 1] + a[i] : a[0];
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            dp[i][j] = i == j ? 0 : numeric_limits<int>::max();
        }
    }

    for (int len = 2; len < k + 1; len++) {
        for (int st = 0; st + len <= k; st++) {
            for (int cutpoint = 1; cutpoint < len; cutpoint++) {
                dp[st][st + len - 1] = min(
                    dp[st][st + len - 1], 
                    dp[st][st + cutpoint - 1] + dp[st + cutpoint][st + len - 1] + sum(st, st + len - 1)
                );
            }
        }
    }
    cout << dp[0][k - 1];
}