#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int prev;
    cin >> n >> prev;
    int ans = 0;
    while(--n) {
        int cur;
        cin >> cur;
        ans += cur ^ prev;
        prev = cur;
    }
    cout << ans << endl;
    return 0;
}