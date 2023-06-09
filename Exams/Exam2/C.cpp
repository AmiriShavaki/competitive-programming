#include <bits/stdc++.h>
using namespace std;

#define N 100005
#define MOD 1000000007
#define int long long


int dp[N], prefixsum[N];

int32_t main() {
    int n; cin >> n;
    dp[0] = 1;
    dp[2] = 3;
    dp[4] = 11;
    dp[6] = 41;
    prefixsum[4] = 11 + 3 + 1;
    prefixsum[6] = 11 + 3 + 1 + 41;
    for (int i = 8; i <= n; i += 2) {
        dp[i] += (dp[i - 2] * 3);
        dp[i] %= MOD;
        dp[i] += prefixsum[i - 4] * 2;
        dp[i] %= MOD;
        // for (int j = 0; j <= i - 4; j += 2) {
        //     dp[i] += (dp[j] * 2);
        //     dp[i] %= MOD;
        // }
        prefixsum[i] = prefixsum[i - 2] + dp[i];
        prefixsum[i] %= MOD;
    }
    cout << dp[n];
}