#include <bits/stdc++.h>

using namespace std;

#define int long long
#define N 1003 

int dp[N], a[N];

int32_t main() {
    int n; cin >> n;
    for (int i = 2; i <= n + 1; i++) cin >> a[i]; //2-based

    for (int i = 2; i <= n + 2; i++) {
        dp[i] = min(dp[i - 1] + a[i], dp[i - 2] + a[i]);
    }
    cout << dp[n + 2];
}