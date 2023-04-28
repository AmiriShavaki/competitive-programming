#include <bits/stdc++.h>
using namespace std;

#define N 1003
//#define int long long

int a[N];
unordered_map <int, int> factored;

void factorize(int n) {
    for (int div = 2; div * div <= n; div++) {
        while (n % div == 0) {
            n /= div;
            factored[div]++;
        }
    }
    if (n > 1) factored[n]++;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            factorize(a[i]);
        }

        int single_cnt = 0, ans = 0;

        for (auto& it:factored) {
            int pwr = it.second;
            single_cnt += pwr % 2;
            ans += pwr / 2;
        }
        ans += single_cnt / 3;
        cout << ans << endl;
        factored.clear();
    }
    return 0;
}