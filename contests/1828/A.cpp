#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cout << i * (1 + (1 - n % 2)) << " \n"[i == n];
        }
    }
    return 0;
}