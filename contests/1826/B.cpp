#include <bits/stdc++.h>
using namespace std;

#define N 100005
//#define int long long

int a[N], b[N];

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];

        bool ispal = true;
        for (int i = 0; i < n / 2; i++) {
            ispal &= a[i] == a[n - i - 1];
            b[i] = abs(a[i] - a[n - i - 1]);
        }

        if (ispal) {
            cout << "0\n"; continue;
        }

        int ans = b[0];
        for (int i = 1; i < n / 2; i++) {
            ans = gcd(b[i], ans);
        }
        cout << ans << endl;
    }
    return 0;
}