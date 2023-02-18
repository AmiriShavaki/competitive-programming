#include <bits/stdc++.h>
using namespace std;

#define N 200005
#define int long long

long long a[N], b[N], psum[N];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        multiset <int> drinks;
        int delta = 0;
        for (int i = 0; i < n; i++) {
            drinks.insert(delta + a[i]);
            long long ans = 0;
            while(!drinks.empty() && *drinks.begin() - delta <= b[i]) {
                ans += *drinks.begin() - delta;
                drinks.erase(drinks.begin());
            }
            ans += drinks.size() * b[i];
            delta += b[i];
            //cout << "ans: " << ans << "    delta: " << delta << endl;
            cout << ans << " \n"[i == n - 1];
        }
    }
    
    return 0;
}