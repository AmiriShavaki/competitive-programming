#include <bits/stdc++.h>
using namespace std;

#define N 100005
#define int long long

int psum[N], a[N];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        psum[i] = i ? a[i]+psum[i-1] : a[0];
    }
    for (int i = 0; i < q; i++) {  
        int l, r; cin >> l >> r; l--; r--;
        cout << (l ? psum[r] - psum[l - 1] : psum[r]) << endl;
    }
    return 0;
}