#include <bits/stdc++.h>
using namespace std;

#define N 102
//#define int long long

string op[N];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> op[i];

        vector <int> mark(n, 1);
        for (int i = 0; i < k; i++) {
            for (int j = 1; j < n; j++) {
                if (op[j][i] != op[0][i]) mark[j] = 0;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) ans += mark[i];
        cout << ans << endl;
    }
    return 0;
}