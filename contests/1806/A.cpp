#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (d < b || d - b + a < c) {
            cout << "-1\n";
        } else {
            cout << d - b + (d - b + a - c) << endl;
        }
    }
    return 0;
}