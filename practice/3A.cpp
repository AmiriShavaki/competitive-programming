#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, t; cin >> s >> t;
    char x1 = s[0], y1 = s[1], x2 = t[0], y2 = t[1];
    int x_bias = x1 - x2, y_bias = y1 - y2;

    cout << max(abs(x_bias), abs(y_bias)) << endl;

    while (x_bias || y_bias) {
        if (x_bias < 0) {
            cout << 'R';
            x_bias++;
        } else if (x_bias > 0) {
            cout << 'L';
            x_bias--;
        }
        if (y_bias < 0) {
            cout << 'U';
            y_bias++;
        } else if (y_bias > 0) {
            cout << 'D';
            y_bias--;
        }
        cout << endl;
    }

    return 0;
}