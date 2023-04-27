#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n; cin >> n;

        if (n == 1) {
            cout << "1\n"; continue;
        }
        if (n == 2) {
            cout << "2 1\n"; continue;
        }
        if (n & 1) {
            cout << "-1\n"; continue;
        }

        cout << n << ' ';
        int cur = 0, l = 1, r = n - 1;
        while (true) {
            int last = cur;
            cur = l++;
            int new_res = (cur - last + n) % n;
            cout << new_res;
            //cout << "cur:" << cur << " new_res:" << new_res << endl;
            if (l > r) {
                cout << '\n';
                break;
            } else cout << ' ';

            last = cur;
            cur = r--;
            new_res = (cur - last + n) % n;
            cout << new_res << ' ';
            //cout << "cur:" << cur << " new_res:" << new_res << endl;
        }
    }
    return 0;
}