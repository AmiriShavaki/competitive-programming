#include <bits/stdc++.h>
using namespace std;

#define N 200005
//#define int long long

int a[N];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--) {
        int n, k;
        cin >> n >> k;
        int bad_cnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            bad_cnt += a[i] % k != (i + 1) % k;
        }
        if (bad_cnt == 0) cout << "0\n";
        else if (bad_cnt == 2) cout << "1\n";
        else cout << "-1\n";
    }
    return 0;
}