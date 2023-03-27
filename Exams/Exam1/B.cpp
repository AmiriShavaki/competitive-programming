#include <bits/stdc++.h>
using namespace std;

#define N 202
int dp[N][N];
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) dp[i][i] = 1;
    for (int i = 0; i < n - 1; i++) dp[i][i + 1] = 1 + (a[i] == a[i + 1]);

    for (int len = 3; len <= n; len++) {
        for (int l = 0; l + len - 1 < n; l++) {
            if (a[l] == a[l + len - 1]) {
                dp[l][l + len - 1] = 2 + dp[l + 1][l + len - 2];
            } else {
                dp[l][l + len - 1] = max(dp[l][l + len - 2], dp[l + 1][l + len - 1]);
            }
        }
    }
    cout << dp[0][n - 1];
    return 0;
}