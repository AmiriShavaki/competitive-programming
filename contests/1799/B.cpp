#include <bits/stdc++.h>
using namespace std;

#define N 102

int a[N];

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int non_one = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            non_one += a[i] != 1;
        }
        if (non_one == 0 || n == 1) {
            cout << "0\n";
            continue;
        }
        if (non_one != n) {
            cout << "-1\n";
            continue;
        }
        vector <int> res1, res2;
        for (int i = 0; i < n;) {
            bool done = true;
            for (int j = 0; j < n; j++) {
                if (a[i] == a[j]) continue;
                if (a[i] > a[j]) {
                    res1.push_back(i + 1);
                    res2.push_back(j + 1);
                    a[i] = a[i] / a[j] + (a[i] % a[j] != 0);
                } else {
                    res1.push_back(j + 1);
                    res2.push_back(i + 1);
                    a[j] = a[j] / a[i] + (a[j] % a[i] != 0);
                }
                done = false;
            }
            if (done) break;
            i += a[i] == 2;
        }
        cout << res1.size() << endl;
        for (int i = 0; i < res1.size(); i++) cout << res1[i] << ' ' << res2[i] << endl;
    }
    return 0;
}