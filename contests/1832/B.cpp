#include <bits/stdc++.h>
using namespace std;

#define N 200005
#define K 100005
#define int long long

int a[N], psuml[K], psumr[K];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int n, k; cin >> n >> k;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i]; sum += a[i];
        }
        sort(a, a + n);
        psuml[1] = a[0] + a[1]; psumr[1] = a[n - 1];
        for (int i = 1; i < k; i++) {
            psuml[i + 1] = psuml[i] + a[2 * i] + a[2 * i + 1];
            psumr[i + 1] = psumr[i] + a[n - i - 1];
        }
        int mi = numeric_limits<int>::max();
        for (int i = 0; i <= k; i++) {
            mi = min(mi, psuml[i] + psumr[k - i]);
        }
        cout << sum - mi << endl;
    }
    return 0;
}