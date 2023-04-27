#include <bits/stdc++.h>

using namespace std;

#define int long long
#define N 500005

int presum[N], a[N];

int32_t main() {
    int n;
    cin >> n;
    int ans = 0, onethirdS = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        presum[i] = i > 0 ? presum[i - 1] + a[i] : a[0];
    }
    int sum = presum[n - 1];
    for (int i = 0; i < n - 1; i++) {
        if (presum[i] == sum * 2 / 3) ans += onethirdS;
        if (presum[i] == sum / 3) onethirdS++;
    }
    cout << (sum % 3 ? 0 : ans);
}