#include <bits/stdc++.h>
using namespace std;

#define N 50004

int p[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector <int> res(n, -1);
        unordered_set <int> us;
        int ind = n-1;
        for (int i = 0; i < m; i++) {
            cin >> p[i];
            if (ind < 0) continue;
            if (us.find(p[i]) == us.end()) {
                 us.insert(p[i]);
                res[ind--] = i + 1;
            }
        }
        for (int i = 0; i < n; i++) cout << res[i] << " \n"[i == n - 1];
    }
    return 0;
}