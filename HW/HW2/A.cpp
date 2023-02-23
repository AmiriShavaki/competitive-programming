#include <bits/stdc++.h>
using namespace std;

void print(vector <int> a) {
    cout << "debug ";
    for (int i = 0; i < a.size(); i++) cout << a[i] << " \n"[i == a.size() - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int mi = numeric_limits<int>::max();
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mi = min(mi, a[i]);
        }
        int ans = 0;
        for (int i = 0; i < a.size(); i++) {
            while (a[i] >= 2 * mi) {
                if (a[i] - 2 * mi + 1 < mi) {
                    a.push_back(mi);
                    a.push_back(a[i] - mi);
                } else {
                    a.push_back(2 * mi - 1);
                    a.push_back(a[i] - 2 * mi + 1);
                }
                ans++;
                a.erase(a.begin() + i);
            }
        }
        cout << ans << endl;
    }
    return 0;
}