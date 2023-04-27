#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    int a1, a2;
    cin >> a1 >> a2;
    int ans = 0;
    while (a1 >0 & a2 > 0) {
        if (a1 > a2) swap(a1, a2);
        a1++; a2 -= 2; ans++;
    }
    cout << ans - (a1 < 0 || a2 < 0);
}