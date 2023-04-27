#include <bits/stdc++.h>

using namespace std;

#define N 100005
#define int long long

int a[N], sum[N], dp[N];

int32_t main() {
    int n;
    cin >> n;
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum[a[i]] += a[i];
    }
    dp[1] = sum[1];
    for (int i = 2; i < N; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + sum[i]);
    }
    cout << dp[N - 1];
}