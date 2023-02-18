#include <bits/stdc++.h>
using namespace std;

#define N 200005 
#define MAX 31

long long a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector <int> zero_bit_cnt(MAX, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            for (int j = 0; j < MAX; j++) {
                zero_bit_cnt[j] += 1 - ((a[i] & (1 << j)) >> j);
            }
        }
        long long ans = 0;
        for (int j = MAX - 1; j >= 0; j--) {
            if (zero_bit_cnt[j] <= k || !zero_bit_cnt[j]) {
                k -= zero_bit_cnt[j];
                ans += 1LL << j;
            }
        }
        cout << ans << endl;
    }
    return 0;
}