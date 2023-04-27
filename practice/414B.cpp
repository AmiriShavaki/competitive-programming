#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007
#define N 2003

int dp[N][N]; //dp[last number][length]

int32_t main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i < N; i++) dp[i][1] = 1;
    for (int len = 1; len < k; len++) {
        for (int last = 1; last <= n; last++) {
            int mul = 1;
            while(mul * last <= n) {
                dp[mul * last][len + 1] += dp[last][len];
                dp[mul * last][len + 1] %= MOD;
                mul++;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += dp[i][k];
        ans %= MOD;
    }
    cout << ans;
}