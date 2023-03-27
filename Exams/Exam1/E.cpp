#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long ans = 0;
    int n;
    cin >> n;
    for (int divisor = 1; divisor <= n; divisor++) {
        int flr = n / divisor;
        ans += divisor * flr * (flr + 1) / 2;
    }
    cout << ans;
    return 0;
}