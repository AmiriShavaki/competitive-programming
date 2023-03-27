#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        a = abs(a);
        b = abs(b);
        int mi = min(a, b);
        a -= mi;
        b -= mi;
        cout << mi * 2 + max(2 * (a + b) - 1, 0) << endl;
    }
    return 0;
}