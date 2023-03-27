#include <bits/stdc++.h>
using namespace std;

#define N 200005

int a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, i, j;
        cin >> n;
        int zero_cnt = 0, ones_cnt = 0;
        for (i = 0; i < n; i++) {
            cin >> a[i];
            zero_cnt += a[i] == 0;
            ones_cnt += a[i] == 1;
        }
        if (zero_cnt <= n / 2 + n % 2) {
            cout << "0\n";
            continue;
        }
        if (zero_cnt + ones_cnt != n || !ones_cnt) {
            cout << "1\n";
            continue;
        }
        cout << "2\n";
    }
    return 0;
}