#include <bits/stdc++.h>
using namespace std;

#define N 200005

int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i) {
            ans += max(0, a[i - 1] - a[i]);
            a[i] += max(0, a[i - 1] - a[i]);
        }
    }
    cout << ans;
    return 0;
}