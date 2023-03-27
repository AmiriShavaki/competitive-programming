#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int k = n / i;
            int res1 = k, res2 = k * (i - 1);
            cout << min(res1, res2) << ' ' << max(res1, res2) << endl;
            return 0;
        }
    }
    return 0;
}