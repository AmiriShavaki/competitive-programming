#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        multiset <int> pos, neg;
        int n;
        cin >> n;
        if (n == 2) {
            int a, b;
            cin >> a >> b;
            cout << a * b << endl;
            continue;
        }
        for (int i = 0; i < n; i++) {
            int a_i;
            cin >> a_i;
            if (a_i >= 0) pos.insert(a_i);
            else neg.insert(a_i);
        }
        int ans = -1;
        if (pos.size() >= 2) {
            set <int>::iterator it = pos.end(); it--;
            int a = *it;
            it--;
            int b = *it;
            ans = max(a * b, ans);
        }
        if (neg.size() >= 2) {
            set <int>::iterator it = neg.begin();
            int a = *it;
            it++;
            int b = *it;
            ans = max(a * b, ans);
        }
        cout << ans << endl;
    }
    return 0;
}