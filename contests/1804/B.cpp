#include <bits/stdc++.h>
using namespace std;

#define N 200005
int t[N];
int late[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _;
    cin >> _;
    while(_--) {
        int n, k, d, w;
        cin >> n >> k >> d >> w;
        for (int i = 0; i < n; i++) {
            cin >> t[i];
            late[i] = t[i] + w;
        }
        int cur = 0, ans = 0;
        for (; cur < n;) {
            int new_cur = cur;
            for (int i = 1; i < k && i + cur < n; i++) {
                if (t[cur + i] - late[cur] <= d) {
                    new_cur = cur + i;
                } else {
                    break;
                }
            }
            //cout << "cur:" << cur << " new_cur:" << new_cur << endl;
            cur = new_cur + 1;
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}