#include <bits/stdc++.h>

using namespace std;

#define int long long

long long dearr_cnt[5] = {1, 0, 1, 2, 9};

inline long long comb(int k, int n) {
    int ans = 1;
    for (int i = n - k + 1; i <= n; i++) ans *= i;
    for (int i = 1; i <= k; i++) ans /= i;
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k; cin >> n >> k;

    int ans = 0;
    for (int i = 0; i <= k; i++) {
        ans += comb(i, n) * dearr_cnt[i];
    }
    cout << ans;
}